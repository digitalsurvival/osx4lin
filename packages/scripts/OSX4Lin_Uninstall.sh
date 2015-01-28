#!/bin/sh 
 
# OSX4Lin Uninstaller 
 
echo 
echo "*************************************" 
echo " Welcome to OSX4Lin v1.0 Uninstaller " 
echo "*************************************" 
echo 
echo Send hatemail to Michael Thompson via actionscripted@gmail.com 
echo
echo "This will completely remove all files added by running" 
echo "the OSX4Lin v1.0 Installer and reset system settings to" 
echo "Ubuntu defaults." 
echo 
echo "You may be asked to provide your root password. This is" 
echo "because there were files placed in system directories" 
echo "that cannot be fixed without root access." 
#echo 
#echo "The following directories and files will be removed/restored:" 
#echo " $HOME/.themes/OSX4Lin*" 
#echo " $HOME/.icons/OSX4Lin*" 
#echo " $HOME/.emerald/theme/OSX4Lin*" 
#echo " $HOME/.xmms/Skins/OSX4Lin*" 
#echo " $HOME/.bmp/Skins/OSX4Lin*" 
#echo " $HOME/OSX4Lin*" 
#echo " /usr/share/gdm/themes/OSX4Lin*" 
#echo " /usr/share/sounds/OSX4Lin*" 
#echo " /usr/share/backgrounds/OSX4Lin*" 
#echo " /usr/share/pixmaps/pidgin/" 
echo 
echo "Are you sure you want to remove OSX4Lin? [y/n]" 
read like_the_fonz 
echo 
 
echo "When you ran the OSX4Lin Installer, did you give it root access? [y/n]" 
echo "If you're not sure, type 'y'." 
read remove_root_shizzle 
echo 
 
if [ $like_the_fonz = y -o $like_the_fonz = Y ]; then 
echo "Removing and restoring files..." 
rm -rf $HOME/.themes/OSX4Lin* 
rm -rf $HOME/.icons/OSX4Lin* 
rm -rf $HOME/.emerald/theme/OSX4Lin* 
rm -rf $HOME/.emerald/themes/*OSX4Lin* 
rm -rf $HOME/.xmms/Skins/OSX4Lin* 
rm -rf $HOME/.bmp/Skins/OSX4Lin* 
# The tar.gz is really just a tar, and it's file-system relative... 
if [ $remove_root_shizzle = y -o $remove_root_shizzle = Y ]; then 
tar -xf $HOME/OSX4Lin*/Backup/pidgin_backup.tar.gz 
sudo cp -r ./usr / 
rm -rf ./usr 
rm -rf $HOME/OSX4Lin* 
sudo rm /usr/share/backgrounds/OSX4Lin* 
sudo rm -rf /usr/share/gdm/themes/OSX4Lin* 
sudo rm -rf /usr/share/sounds/OSX4Lin* 
fi 
echo 'Done.' 
echo 
 
echo "Repairing system settings..." 
# certain settings are fixed automatically with the file removal/repair 
gconftool-2 --type string --set /desktop/gnome/interface/gtk_theme "Human" 
gconftool-2 --type string --set /apps/metacity/general/theme "Human" 
gconftool-2 --type string --set /apps/metacity/general/button_layout "menu:minimize,maximize,close" 
gconftool-2 --type string --set /desktop/gnome/interface/toolbar_style "both" 
gconftool-2 --type string --set /desktop/gnome/interface/icon_theme "Human" 
echo 'Done.' 
 
echo 
echo "*** ALL SET! *** " 
echo 
echo "The fonts installed by OSX4Lin were not removed for" 
echo "safety's sake but can be removed from here:" 
echo " $HOME/fonts/" 
echo 
echo "Additionally, the AWN plugin for Pidgin was not removed but" 
echo "can be deleted from here:" 
echo " $HOME/.purple/plugins/pidgin_awn.so" 
echo 
else 
echo "Exiting without making any changes..." 
fi 
 
echo 