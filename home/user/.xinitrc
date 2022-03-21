# speedie's .xinitrc
# https://github.com/speediegamer/configurations

~/.config/slstatus/slstatus & # Execute slstatus

xclip &

picom &

xrdb ~/.Xresources

#xsetroot -solid '#222222' # Old is #222222

setwallpaper-wm & 

modprobe vboxdrv

# !!Keep any new lines above this, dumbass self!!
~/.config/dwm/dwm # Execute dynamic window manager!

