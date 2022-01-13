#!/bin/bash
#
#               _
# ___ _ __   __| |
#/ __| '_ \ / _` |
#\__ \ |_) | (_| |
#|___/ .__/ \__,_|
#    |_|
#
# speedie's configuration installer version 0.1
#
# -- by speedie
#
# https://tinyurl.com/spdconfig
# https://github.com/speediegamer/configurations
###################################################
user="$(whoami)"

if [ -f "/etc/doas.conf" ]; then
    perms=doas
else 
    perms=sudo
fi

echo "speedie's configuration installer: version 0.1"
echo "Before continuing, please make sure you meet these requirements:"
echo
echo "- Logged in as the user who will be using all the software"
echo "- Git available and usable"
echo "- Do not run with doas/sudo"
echo "- If running Arch Linux, make sure base-devel is installed"
sleep 3

echo "Starting installation"

echo "Using $perms, is this correct?"

echo "NOTE: You must install the software itself and the config dependencies yourself!!"

cd ~/ && mkdir .config && echo "Create .config directory"

$perms git clone https://github.com/speediegamer/configurations && echo "Repository cloned"

cd configurations && echo "Changed directory to clone"

cd .config && $perms cp -r * /home/$user/.config && echo "Cloned .config"

cd .. && echo "Changed directory to previous"

cd home/user && echo "Changed directory to home/user"

$perms cp -r * /home/$user && echo "Copied dotfiles from home/user to your user"

cd .. && cd .. && echo "Changed directory to previous"

cd usr/bin && echo "Changed directory to usr/bin"

$perms cp -r * /usr/bin && echo "Cloned usr/bin"

cd /home/$user/.config/dwm && echo "Changed directory to ~/.config/dwm"

echo "Compiling dwm"

$perms make && echo "Compiled dwm"

cd .. && cd slstatus && echo "Changed directory to ~/.config/slstatus"

echo "Compiling slstatus"

$perms make && echo "Compiled slstatus"

cd .. && cd dmenu && echo "Changed directory to ~/.config/dmenu"

echo "Compiling dmenu"

$perms make && echo "Compiling dmenu"

cd .. && cd st && echo "Changed directory to ~/.config/st"

echo "Compiling st"

$perms make && echo "Compiled st"

sleep 2

clear

echo "Finished compiling everything"

echo "Have a good day!"
sleep 3





