#!/bin/bash

# Gnome GlobalMenu instalation script for ubuntu 10.10 (Macbuntu G2GM patch)
# Author: lookout
# Send feedback to lookout@losoft.org
# Homepage: http://www.losoft.org/macbuntu/
# 
# Copyright (c) 2010 Jan Komadowski
# 
# This program is free software. Feel free to redistribute and/or
# modify it under the terms of the GNU General Public License v3
# as published by the Free Software Foundation.
# This program is distributed in the hope that it will be useful
# but comes WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# 
# See the GNU General Public License for more details.

UBUVER="10.10"
UBUNTU="Ubuntu $UBUVER"

ARCH=$(uname -m)
ARCHSN=`[ "$ARCH" == "x86_64" ] && echo "amd64" || echo "i386"`

chk_user()
{
	echo ""
	echo "Checkin script user..."
	if [ $(whoami) = "root" ]
	then
		echo "Failed."
		echo "Root user not allowed, please run this script as a regular user."
		echo "Exiting..."
		exit 1;
	fi
	echo "Passed"
}

chk_root()
{
	echo ""
	echo "Checkin for a root access..."
	s=`sudo cat /etc/issue`
	if [ -n "$s" ]; then
		return
	fi
	echo "Authorization failed."
	echo "Exiting..."
	exit 1;
}

chk_system()
{
	echo ""
	echo "Checking Ubuntu version..."
	s=`cat /etc/issue | grep -i "$UBUNTU"`
	if [ ! -n "$s" ]; then
		echo "Failed. System not supported, script will end here"
		echo "To ignore their compatibility with current OS try ./install.sh force"
		echo "Exiting..."
		exit 1;
	fi
	echo "Passed"
}

# Changing current to script dir
cd -- "$(dirname -- "$0")"

echo ""
echo "Gnome GlobalMenu instalation script for $UBUNTU (Macbuntu G2GM patch)"

case "$force" in
	--force|force) ;;
	*) chk_system ;;
esac

chk_user

echo ""
echo "This script will install and enable GlobalMenu now"
echo "You must have root privileges to be able to install listed components."
echo ""
echo "Attention!"
echo "Running scripts with root privileges is dangerous, if you"
echo "do not trust the software or you are unsure about the origin"
echo "of this software, please abort (Control+C)."
echo ""
echo "Debs are dedicated to Ubuntu 10.04 Lucid Lynx,"
echo "it is therefore possible that there might be problems"
echo "using this version on Ubuntu 10.10 Maverick Meerkat."
echo ""
echo "Do you want to continue [Y/n]?"
read ans
case "$ans" in
	n*|N*)
	echo "Installation aborted. Exiting..."
	exit 0;
esac

chk_root

echo ""
echo "Downloading..."
mkdir /tmp/g2gm/
wget https://launchpad.net/~globalmenu-team/+archive/ppa/+files/libgnomenu0-2_0.7.9-0ubuntu1~ppa1~lucid2_$ARCHSN.deb -O /tmp/g2gm/libgnomenu0-2_0.7.9-0ubuntu1~ppa1~lucid2_$ARCHSN.deb
wget https://launchpad.net/~globalmenu-team/+archive/ppa/+files/libglobalmenu-gnome_0.7.9-0ubuntu1~ppa1~lucid2_$ARCHSN.deb -O /tmp/g2gm/libglobalmenu-gnome_0.7.9-0ubuntu1~ppa1~lucid2_$ARCHSN.deb
wget https://launchpad.net/~globalmenu-team/+archive/ppa/+files/gnome-globalmenu-common_0.7.9-0ubuntu1~ppa1~lucid2_all.deb -O /tmp/g2gm/gnome-globalmenu-common_0.7.9-0ubuntu1~ppa1~lucid2_all.deb
wget https://launchpad.net/~globalmenu-team/+archive/ppa/+files/gnome-applet-globalmenu_0.7.9-0ubuntu1~ppa1~lucid2_$ARCHSN.deb -O /tmp/g2gm/gnome-applet-globalmenu_0.7.9-0ubuntu1~ppa1~lucid2_$ARCHSN.deb
wget https://launchpad.net/~globalmenu-team/+archive/ppa/+files/gnome-globalmenu_0.7.9-0ubuntu1~ppa1~lucid2_all.deb -O /tmp/g2gm/gnome-globalmenu_0.7.9-0ubuntu1~ppa1~lucid2_all.deb

echo ""
echo "Installing..."
sudo apt-get update
sudo dpkg -i /tmp/g2gm/libgnomenu0-2_0.7.9-0ubuntu1~ppa1~lucid2_$ARCHSN.deb
sudo dpkg -i /tmp/g2gm/libglobalmenu-gnome_0.7.9-0ubuntu1~ppa1~lucid2_$ARCHSN.deb
sudo dpkg -i /tmp/g2gm/gnome-globalmenu-common_0.7.9-0ubuntu1~ppa1~lucid2_all.deb
sudo dpkg -i /tmp/g2gm/gnome-applet-globalmenu_0.7.9-0ubuntu1~ppa1~lucid2_$ARCHSN.deb
sudo dpkg -i /tmp/g2gm/gnome-globalmenu_0.7.9-0ubuntu1~ppa1~lucid2_all.deb

echo ""
echo "Configuring..."
# Panels
gconftool-2 --load panel/panel.entries
gconftool-2 --set /apps/panel/general/toplevel_id_list --type list --list-type string "[top_panel_screen0]"
gconftool-2 --set /apps/panel/toplevels/top_panel_screen0/background/type --type string "gtk"
# Reloading Gnome Panel
killall gnome-panel

echo ""
echo "Cleaning..."
rm -rf /tmp/g2gm/

echo "Installation complete! Have fun :)"

echo ""
echo "It is recommended that you restart the X server (Control+Alt+Backspace if enabled)"
echo "Positively, if reboot the computer. Restart now?"
echo "Please, press any other key if you want to restart later [y/N]?"
read ans
case "$ans" in
	y*|Y*)
	echo "Rebooting..."
	sudo reboot
	exit 0;
esac

echo "Bye"

