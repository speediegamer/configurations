# speedie's .xinitrc

~/.config/slstatus/slstatus & # Execute slstatus

feh --bg-scale ~/Pictures/.wallpaper.png # Set wallpaper

pipewire & # Enable Pipewire for audio

echo 0 | doas tee /sys/module/hid_apple/parameters/fnmode # Fix for Keychron keyboards on Linux
# Replace 'doas' with 'sudo' if you're using that!!

picom --experimental-backend &

# Mount my drives
doas mount /dev/sda6 /mnt/storage01 # Mounting my drives in the .xinitrc as I prefer it FYI.
doas mount /dev/sdc1 /mnt/storage02

# !!Keep any new lines above this, dumbass self!!
~/.config/dwm/dwm # Execute dynamic window manager!

