# speedie's .bashrc file
# https://github.com/speediegamer/bashrc

# Aliases
alias sudo='doas'
alias reboot='doas reboot'
alias emerge='doas emerge'
alias unmerge='doas emerge --unmerge'
alias find='whereis'
alias top='doas bpytop'
alias btw='hf'
alias fm='f'
alias ls='exa --git -a'
alias woo='doas emerge'
alias cri='doas emerge --unmerge'
alias based='doas emerge'
alias unbased='doas emerge --unmerge'
alias cfg='doas cfg-update -u'
alias cp='doas cp'
alias vim='nvim'
alias mix='pulsemixer'
alias to='rtorrent'
alias nano='vim'
alias unrar='unrar e'
alias cp='cp -g'
alias st='~/.config/st/st'
alias dwm='~/.config/dwm/dwm'
alias slstatus='~/.config/slstatus/slstatus'
alias dmenu='~/.config/dmenu/dmenu'

alias godl='cd ~/Downloads'
alias godoc='cd ~/Documents' 
alias go='cd'
alias godie='killall dwm'
alias kys='killall dwm'
alias goconfig='cd ~/.config'
alias make='make && rm config.h'
alias gitupdate='doas gitupdate'

alias winget='echo That OS is so 1984!'
alias discord='~/.config/surf/surf https://discord.gg/channels/@me'
alias youtube='~/.config/surf/surf https://youtube.com'
alias google='~/.config/surf/surf https://duckduckgo.com'
alias clonest='git clone https://git.suckless.org/st'

# Autostart
clear
/usr/bin/ufetch
echo

# Powerline
function _update_ps1() {
    PS1=$(powerline-shell $?)
}

if [[ $TERM != linux && ! $PROMPT_COMMAND =~ _update_ps1 ]]; then

    PROMPT_COMMAND="_update_ps1; $PROMPT_COMMAND"
fi
