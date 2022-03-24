# speedie's zshrc
# Make sure to edit export variables before using.

# Set color based on distro
if [[ "$(</etc/os-release)" =~ "void" ]]; then
    export PS1col="[$(tput setf 3)$(whoami)$(tput setf 6)@$(tput setf 11)$(hostname)$(tput setf 4) %d$(tput sgr0)]$ "
elif [[ "$(</etc/os-release)" =~ "gentoo" ]]; then
    export PS1col="[$(tput setf 3)$(whoami)$(tput setf 6)@$(tput setf 5)$(hostname)$(tput setf 4) %d$(tput sgr0)]$ "
elif [[ "$(</etc/os-release)" =~ "arch" ]]; then
    export PS1col="[s$(tput setf 3)$(whoami)$(tput setf 6)@$(tput setf 13)$(hostname)$(tput setf 4) %d$(tput sgr0)]$ "
elif [[ "$(</etc/os-release)" =~ "artix" ]]; then
    export PS1col="[$(tput setf 3)$(whoami)$(tput setf 6)@$(tput setf 13)$(hostname)$(tput setf 4) %d$(tput sgr0)]$ "
fi

# Features
autoload -Uz compinit
compinit
_comp_options+=(globdots)

# Export variables
export EDITOR='nvim'
export LANG="en_US.UTF-8"
export TERM='st-256color'
export PERM='doas'
export PLAYER='mpv'
export TERMINAL='~/.config/st/st' # Required to be exported by my dwm configuration!!
export BROWSER='librewolf' # Required to be exported by my dwm configuration!!
export FETCH='sfetch'
export PS1=$PS1col
export MIXER='alsamixer'
export LIST='ls'
export PKGINSTALL='$PERM emerge'
export PKGREMOVE='$PERM emerge --deselect'
export PKGCLEAN='$PERM emerge --depclean -a'
export LISTDEVICE='lsblk'
export DEVICEINFO='df'

# Web browser aliases
alias :w='$BROWSER'
alias w='$BROWSER https://searx.org'

# Editor aliases
alias vi=$EDITOR
alias nvim=$EDITOR
alias :e=$EDITOR
alias e=$EDITOR
alias :de="$PERM $EDITOR"
alias de="$PERM $EDITOR"

# sudo/doas aliases
alias sudo=$PERM
alias :r=$PERM

# fetch aliases
alias btw=$FETCH

# other
alias yt='ytfzf'

# ls aliases
alias ls='$LIST -lah --color=auto'
alias mix=$MIXER

# get aliases
alias getsfetch='rm sfetch ; curl -o sfetch https://raw.githubusercontent.com/speediegamer/sfetch/main/sfetch && chmod +x sfetch'
alias getconfig='git clone https://github.com/speediegamer/configurations'

# package installation/removal aliases
alias :i=$PKGINSTALL
alias :iu=$PKGREMOVE
alias :id=$PKGCLEAN

# list aliases
alias :l='$LIST -lah --color=auto'
alias :lb=$LISTDEVICE
alias :ld=$DEVICEINFO

# mixer aliases
alias :a=$MIXER

# General terminal command aliases
alias Q='exit'
alias :q='exit'
alias q='exit'
alias :c='clear'

# Package manager aliases
alias emerge='doas emerge'

# make aliases
alias make='make -j$(nproc)'

# application
alias rss='killall mpv ; killall newsboat ; newsboat'

# Mount commands
alias mnt='$PERM mount /dev/'

# Process aliases
alias kys='$PERM killall dwm'

# "mk" aliases
alias mkexec='chmod +x'
alias mkdir='mkdir -pv'

# youtube-dl/yt-dlp aliases
alias mp3dl='$PERM youtube-dl -x --audio-format mp3 --prefer-ffmpeg'
alias mp4dl='$PERM youtube-dl -f best --prefer-ffmpeg'

# File aliases
alias urls='$EDITOR ~/.config/newsboat/urls'
alias bashrc='$EDITOR ~/.bashrc'
alias zshrc='$EDITOR ~/.zshrc'

# Basic cd aliases
alias ..='cd ..'
alias .2='cd ../..'
alias .3='cd ../../..'
alias .4='cd ../../../..'
alias .5='cd ../../../../..'

# "GO" aliases
alias goconfig="cd ~/.config"
alias godl="cd ~/Downloads"
alias gostor="cd /mnt/storage01"
alias gostor2="cd /mnt/storage02"
alias gobin="cd /usr/bin"
alias gohome="cd ~/"
alias golocal="cd /usr/local/bin"
alias gorec="cd ~/OBS\ \Recordings"
alias goproj="cd ~/Projects"

# Funny aliases
alias winget='echo "That OS is so 1984"'

# Extraction aliases
alias untar='$PERM tar xpvf'
alias unrar='$PERM unrar x'
clear

$FETCH

