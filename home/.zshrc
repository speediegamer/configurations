# speedie's zshrc
# Requires a few things before using:
# Run curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh && cp -r ~/.oh-my-zsh ~/.config/zsh && chsh /bin/sh && zsh
autoload -Uz compinit 

compinit
_comp_options+=(globdots) 

ZSH_CUSTOM=~/.config/zsh
ZSH_THEME="essembeh"

export EDITOR='nvim'
export LANG=en_US.UTF-8
export ZSH="$HOME/.config/zsh"
export TERM='st-256color'

source ~/zsh-snap/znap.zsh
source $ZSH/oh-my-zsh.sh

zstyle ':omz:update' mode disabled

plugins=(git)

HYPHEN_INSENSITIVE="false"
CASE_SENSITIVE="false"

# Aliases
alias vim='doas nvim' # neovim is based but vim is easier to type
alias sudo='doas' # sudo is for normies, do not use
alias btw='sfetch' # sfetch is my fetch script (https://github.com/speediegamer/sfetch)
alias ls='ls -lah --color=auto'
alias mix='alsamixer' # alsamixer is my mixer
alias :q='exit'
alias :w='doas nvim'
alias :e='doas nvim'
alias kys='doas killall dwm'
alias mkexec='doas chmod +x'
alias mp3dl='youtube-dl -x --audio-format mp3 --prefer-ffmpeg'
alias mp4dl='youtube-dl -f best https://www.youtube.com/watch?v=7E-cwdnsiow'
alias ..='cd ..'
alias .2='cd ../..'
alias .3='cd ../../..'
alias .4='cd ../../../..'
alias .5='cd ../../../../..'
alias mkdir='mkdir -pv'
alias winget='echo "That OS is so 1984"'
alias btop='btop --utf-force'
alias goconfig="cd ~/.config"

sfetch || ufetch || neofetch || clear
