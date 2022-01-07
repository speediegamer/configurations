# speedie's .bash_profile
# Rather pointless but might as well upload this!

if [[ -f ~/.bashrc ]] ; then
	. ~/.bashrc
fi

if shopt -q login_shell; then
    [[ -f ~/.bashrc ]] && source ~/.bashrc
    [[ -t 0 && $(tty) == /dev/tty1 && ! $DISPLAY ]] && exec startx
else
    exit 1
fi
