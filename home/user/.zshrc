# speedie's zshrc
#
#
#
# Set color based on distro
if [[ "$(< /etc/os-release)" =~ "void" ]]; then
    export PS1col="[$(tput setf 3)$(whoami)$(tput setf 6)@$(tput setf 11)$(hostname)$(tput setf 4) %d$(tput sgr0)]$ "
elif [[ "$(< /etc/os-release)" =~ "gentoo" ]]; then
    export PS1col="[$(tput setf 3)$(whoami)$(tput setf 6)@$(tput setf 5)$(hostname)$(tput setf 4) %d$(tput sgr0)]$ "
elif [[ "$(< /etc/os-release)" =~ "arch" ]]; then
    export PS1col="[s$(tput setf 3)$(whoami)$(tput setf 6)@$(tput setf 13)$(hostname)$(tput setf 4) %d$(tput sgr0)]$ "
elif [[ "$(< /etc/os-release)" =~ "artix" ]]; then
    export PS1col="[$(tput setf 3)$(whoami)$(tput setf 6)@$(tput setf 13)$(hostname)$(tput setf 4) %d$(tput sgr0)]$ "
fi

# Export variables
export EDITOR='nvim'
export LANG=en_US.UTF-8
export TERM='st-256color'
export PERM='doas'
export PLAYER='mpv'
export TERMINAL='st'
export BROWSER='librewolf'
export FETCH="sfetch"
export PS1="$PS1col"
export MIXER="alsamixer"
export LIST="ls" # Just in case I use exa
export PKGINSTALL="$PERM emerge "
export PKGREMOVE="$PERM emerge --deselect"
export PKGCLEAN="$PERM emerge --depclean -a"
export LISTDEVICE="lsblk"
export DEVICEINFO="df"

# Aliases
alias vi=$EDITOR
alias nvim=$EDITOR
alias sudo=$PERM
alias btw=$FETCH
alias ls='$LIST -lah --color=auto'
alias mix=$MIXER
alias getsfetch='rm sfetch ; curl -o sfetch https://raw.githubusercontent.com/speediegamer/sfetch/main/sfetch && chmod +x sfetch'
alias getconfig='git clone https://github.com/speediegamer/configurations'
alias :q='exit'
alias q='exit'
alias :w='librewolf https://searx.org'
alias w='librewolf https://searx.org'
alias :e=$EDITOR
alias e=$EDITOR
alias make='make -j$(nproc)'
alias :de=$PERM $EDITOR
alias de=$PERM $EDITOR
alias :i=$PKGINSTALL
alias :iu=$PKGREMOVE
alias :id=$PKGCLEAN
alias :l='$LIST -lah --color=auto'
alias :lb=$LISTDEVICE
alias :ld=$DEVICEINFO
alias :a=$MIXER
alias :c='clear'
alias :r=$PERM
alias Q='exit'
alias rss='killall mpv ; killall newsboat ; newsboat'
alias mnt='doas mount /dev/'
alias zshrc='nvim ~/.zshrc'
alias bashrc='nvim ~/.bashrc'
alias urls='nvim ~/.config/newsboat/urls'
alias kys='doas killall dwm'
alias mkexec='chmod +x'
alias mp3dl='doas youtube-dl -x --audio-format mp3 --prefer-ffmpeg'
alias mp4dl='doas youtube-dl -f best --prefer-ffmpeg'
alias ..='cd ..'
alias .2='cd ../..'
alias .3='cd ../../..'
alias .4='cd ../../../..'
alias .5='cd ../../../../..'
alias mkdir='mkdir -pv'
alias winget='echo "That OS is so 1984"'
alias btop='btop --utf-force'
alias goconfig="cd ~/.config"
alias godl="cd ~/Downloads"
alias gostor="cd /mnt/storage01"
alias gostor1="cd /mnt/storage01"
alias gostor2="cd /mnt/storage02"
alias gobin="cd /usr/bin"
alias gohome="cd ~/"
alias golocal="cd /usr/local/bin"
alias gorec="cd ~/OBS\ \Recordings"
alias goproj="cd ~/Projects"
alias untar='doas tar xpvf'
alias unrar='doas unrar x'
clear

$FETCH

