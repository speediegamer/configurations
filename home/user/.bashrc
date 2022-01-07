# speedie's .bashrc file
# https://github.com/speediegamer/bashrc

# Aliases
alias sudo='doas'
alias reboot='doas reboot'
alias emerge='doas echo emerge && doas emerge'
alias unmerge='doas echo emerge --unmerge && doas emerge --unmerge'
alias find='doas echo find / -iname && doas find / -iname'
alias top='doas echo bpytop && doas bpytop'
alias btw='doas hf && echo'
alias ls='doas echo ls && doas exa -a'
alias woo='doas echo emerge && doas emerge --ask'
alias based='doas echo emerge && doas emerge --ask'
alias cfg='doas echo cfg-update && doas cfg-update -u'
alias n='doas echo nano && doas nano'
alias cp='doas cp'
alias exit='exit'
# alias clear='clear && ufetch && echo'
alias nnn='doas nnn'
alias vim='nvim'

# Autostart
echo $(date)
echo ========================================
/usr/bin/ufetch
echo
