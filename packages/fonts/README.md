### Fonts

Converting this document to be Gentoo friendly...

As root, open an nautilus window and type "fonts:///" in the location bar. Now copy all the .ttf files there. Open a terminal windows and type: "fc-cache -f -v". Restart and you can now use OSX fonts. My font settings are shown in the "MyFonts.png" file.

Note in newer versions of GNOME fonts:/// no longer works. Create a directory called .fonts in your home folder and place all the .ttf/fonts there.

=====

For other fonts and tweaking, follow this guide. This guide has been taken from Ubuntuforums.org. OSX4Lin is in no way associated with this guide.

=====
I tweaked the fontconfig XML files so that fonts look like on Windows. This code is borrowed from PC-BSD. First, let's install the Microsoft fonts. You have 2 ways of doing so:

Either download the fonts into your home directory and install them on your system:

"sudo tar xvjpf msfonts.tbz -C /usr/share/fonts/truetype/"

Or, enable non-free, universe and multiverse repositories and install the Microsoft fonts:

"sudo apt-get install msttcorefonts"

You now have the Microsoft fonts installed. Let's configure your system now.

Download the xml files and extract the file into /etc/fonts/ as root:

sudo tar xvjpf fontconfig.tbz -C /etc/fonts/

Log out from Ubuntu and relog in.

It's a lot more complex than disabling anti-aliasing at small font sizes
Take a backup of /etc/fonts folder and whatever you modify here first, in case you may want to revert.

=====
Please backup all files before deleting/replacing/overwriting the original files. Take all precautions. Proceed at your own risk.