# speedie's zshrc
# Requires a few things before using:
# Run curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh && cp -r ~/.oh-my-zsh ~/.config/zsh && chsh /bin/zsh && zsh
autoload -Uz compinit 

compinit
_comp_options+=(globdots) 

ZSH_CUSTOM=~/.config/zsh
ZSH_THEME="essembeh"

export EDITOR='doas nvim'
export LANG=en_US.UTF-8
export ZSH="$HOME/.config/zsh"
export TERM='st-256color'
export sudo='doas'
export PERM='doas'


source ~/zsh-snap/znap.zsh
source $ZSH/oh-my-zsh.sh

zstyle ':omz:update' mode disabled

plugins=(git)

HYPHEN_INSENSITIVE="false"
CASE_SENSITIVE="false"

# Aliases
alias vi='nvim'
alias vim='nvim' # neovim is based but vim is easier to type
alias sudo='doas' # sudo is for normies, do not use
alias btw='sfetch' # sfetch is my fetch script (https://github.com/speediegamer/sfetch)
alias ls='ls -lah --color=auto'
alias mix='alsamixer || pulsemixer' # alsamixer is my mixer
alias getsfetch='rm sfetch ; curl -o sfetch https://raw.githubusercontent.com/speediegamer/sfetch/main/sfetch && chmod +x sfetch'
alias getconfig='git clone https://github.com/speediegamer/configurations'
alias :q='exit'
alias q='exit'
alias :w='librewolf https://searx.org'
alias w='librewolf https://searx.org'
alias :e='nvim'
alias e='nvim'
alias make='make -j20'
alias :de='doas nvim'
alias de='doas nvim'
alias :ip='emerge --ask'
alias :i='doas emerge --ask'
alias :iu='doas emerge --deselect'
alias :id='doas emerge --depclean -a'
alias :l='ls -lah --color=auto'
alias :lb='lsblk'
alias :ld='df'
alias :a='alsamixer || pulsemixer'
alias :c='clear'
alias :r='doas'
alias mnt='doas mount /dev/'
alias zshrc='nvim ~/.zshrc'
alias bashrc='nvim ~/.bashrc'
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
alias gorec="cd OBS\ \Recordings"
alias untar='doas tar xpvf'
alias unrar='doas unrar x'

sfetch || clear
