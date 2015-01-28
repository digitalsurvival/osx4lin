#!/bin/sh

echo "*************************************"
echo "  Welcome to OSX4Lin v1.0 Installer  "
echo "*************************************"
echo
echo
echo

echo "Installing OSX4Lin UI..."
tar -xzf GTK/OSX4Lin_GTK_v1.0_RC.tar.gz -C ~/.themes/
tar -xzf GTK/OSX4Lin_GTK_Graphite_v1.0_RC.tar.gz -C ~/.themes/
tar -xzf GTK/OSX4Lin_MacMenu_v1.0_RC.tar.gz -C ~/.themes/
tar -xzf GTK/OSX4Lin_MacMenu_Graphite_v1.0_RC.tar.gz -C ~/.themes/
tar -xzf GTK/OSX4Lin_Meta_v1.0_RC.tar.gz -C ~/.themes/

gconftool-2 --type string --set /desktop/gnome/interface/gtk_theme "OSX4Lin_GTK_v1.0_RC"
gconftool-2 --type string --set /apps/metacity/general/theme "OSX4Lin_GTK_v1.0_RC"
gconftool-2 --set /apps/metacity/general/button_layout --type string "close,minimize,maximize:menu"
gconftool-2 --type boolean --set /desktop/gnome/interface/menus_have_icons "true"
gconftool-2 --type string --set /desktop/gnome/interface/toolbar_style "icons"

echo "Done!"
echo 

echo "Installing OSX4Lin Icons..."
tar -xzf Icons/OSX4Lin_Icons_v1.0_RC.tar.gz -C ~/.icons/
gconftool-2 --type string --set /desktop/gnome/interface/icon_theme "OSX4Lin_Icons_v1.0_RC"


echo "Done!"
echo 

echo "Installing OSX4Lin Cursors..."
tar -xzf Cursors/OSX4Lin_Cursors_v1.0_RC.tar.gz -C ~/.icons/

echo "Done! Please enable the cursor theme from Appearances."
echo 

echo "Installing OSX4Lin Emerald Window Borders..."
tar -xzf Emerald/OSX4Lin_Emerald_v1.0_RC.tar.gz -C ~/.emerald/themes
tar -xzf Emerald/OSX4Lin_Graphite_Emerald_v1.0_RC.tar.gz -C ~/.emerald/themes
tar -xzf Emerald/OSX4Lin_Emerald_v1.0_RC.tar.gz -C ~/.emerald/theme

echo "Done!"
echo 

echo "Installing OSX4Lin misc. components..."
mkdir -p ~/.purple/plugins
cp Pidgin/pidgin_awn.so ~/.purple/plugins/
mkdir -p ~/.xmms/Skins
mkdir -p ~/.bmp/Skins
cp MP/OSX4Lin_MP_v1.0_RC.tar.gz ~/.xmms/Skins/
cp MP/OSX4Lin_MP_v1.0_RC.tar.gz ~/.bmp/Skins/
gconftool-2 --type boolean --set /apps/gnome-session/options/show_splash_screen FALSE
#gconftool-2 --type string --set /apps/panel/toplevels/top_panel_screen0/background/image "~/.themes/OSX4Lin_GTK_v1.0_RC/gtk-2.0/Panel/panel-bg-trans.png"
mkdir -p ~/.fonts
tar -xzf Fonts/fonts.tar.gz -C ~/.fonts/
mkdir -p ~/OSX4Lin_v1.0_RC/GRUB
mkdir -p ~/OSX4Lin_v1.0_RC/Usplash
mkdir -p ~/OSX4Lin_v1.0_RC/AWN
mkdir -p ~/OSX4Lin_v1.0_RC/Mozilla
mkdir -p ~/OSX4Lin_v1.0_RC/Rhythmbox_AWN

cp GRUB/*.* ~/OSX4Lin_v1.0_RC/GRUB/
cp Usplash/*.* ~/OSX4Lin_v1.0_RC/Usplash/

cp AWN/*.* ~/OSX4Lin_v1.0_RC/AWN
cp Mozilla/*.* ~/OSX4Lin_v1.0_RC/Mozilla
cp Rhythmbox_AWN/*.* ~/OSX4Lin_v1.0_RC/Rhythmbox_AWN

echo
echo "The following componenets require root access. You can opt out of installing them as they can be manually installed as well."
echo "Would you like to install these components [y/n]? "
read ans

if [ $ans = y -o $ans = Y ]; then

echo "Installing OSX4Lin GDM Login Theme and Sounds..."
sudo tar -xzf GDM/OSX4Lin_GDM_v1.0_RC.tar.gz -C /usr/share/gdm/themes/
sudo tar -xzf Sounds/OSX4Lin_Sounds_v1.0_RC.tar.gz -C /usr/share/sounds/
sudo tar -xzf Sounds/OSX4Lin_Pidgin-Sounds_v1.0_RC.tar.gz -C /usr/share/sounds/

echo
echo "Setting GDM Theme"
echo 

THEME_DIR=/usr/share/gdm/themes
THEMES=OSX4Lin_GDM_v1.0_RC
N=`echo $THEMES | wc -w`
sudo sed -i.old s/GraphicalTheme=.*/GraphicalTheme=`echo $THEMES | cut -d ' ' -f $N`/  /etc/gdm/gdm.conf

THEME_DIR=~/.themes
THEMES=OSX4Lin_GTK_v1.0_RC
N=`echo $THEMES | wc -w`
sudo sed -i.old s/GtkTheme=.*/GtkTheme=`echo $THEMES | cut -d ' ' -f $N`/  /etc/gdm/gdm.conf
echo
echo "Done!"
echo "Please assign the sounds to events manually. All sounds are saved in /usr/share/sounds"
echo 
echo

echo "Installing OSX4Lin Backgrounds..."
sudo cp Wallpapers/*.* /usr/share/backgrounds
gconftool-2 --type string --set /desktop/gnome/background/picture_filename "/usr/share/backgrounds/OSX4Lin_Wallpaper1.jpg"

echo "Done!"
echo

echo
echo "Installing Pidgin theme..."
mkdir -p ~/OSX4Lin_v1.0_RC/Backup
tar -cf ~/OSX4Lin_v1.0_RC/Backup/pidgin_backup.tar.gz /usr/share/pixmaps/pidgin/
sudo tar -xzf Pidgin/OSX4Lin_Pidgin_v1.0_RC.tar.gz -C /usr/share/pixmaps/

echo "Done!"
echo "The current Pidgin theme has been backed up as ~/OSX4Lin_v1.0_RC/Backup/pidgin_backup.tar.gz"
echo "Note that OSX4Lin_v1.0_RC will be in your home folder"
echo "Please enable the Pidgin AWN plugin from within Pidgin and place a launcher for Pidgin on AWN"
echo

else

echo "Components requiring root access not installed. Kindly install them manually"

fi

echo "****************************************"
echo "     OSX4Lin installation complete!"
echo "  Please refer to the documentation for"
echo "   advanced installation instructions"
echo "   (for installing usplash, grub etc.)"
echo " For best results, log off and log back"
echo "   in for all changes to be effected"
echo "****************************************"

echo
key=""
echo -n "Press any key to continue..."
stty -icanon
key=`dd count=1 2>/dev/null`
stty icanon
echo
