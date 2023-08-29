
export ZSH="$HOME/.oh-my-zsh"
export PATH=$HOME/.local/bin:/usr/local/bin:$PATH
export PATH=$HOME/.local/bin/scripts:$PATH
export PATH=$HOME/.local/bin:$PATH
export PATH=$HOME/.local/bin/statusbar:$PATH
export ZSH_COMPDUMP=$ZSH/cache/.zcompdump-$HOST

export TERMINAL=xterm
export EDITOR=nvim

ZSH_THEME="alanpeabody"

plugins=(git)
source ~/.oh-my-zsh/custom/plugins/fast-syntax-highlighting/fast-syntax-highlighting.plugin.zsh

export ZSH_COMPDUMP=$ZSH/cache/.zcompdump-$HOST
source $ZSH/oh-my-zsh.sh
source ~/.zplug/init.zsh
#source /usr/share/fzf/key-bindings.zsh
#source /usr/share/fzf/completion.zsh
#source /usr/share/zsh/plugins/zsh-vi-mode/zsh-vi-mode.plugin.zsh
#source "${HOME}/.zgen/zgen.zsh"

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Enable vi mode
bindkey -v
# Reverse menu with Shift+tab
bindkey '^[[Z' reverse-menu-complete

# Example aliases
 alias zshconfig="vim ~/.zshrc"
 alias vi="nvim"
 alias lc="cd .local/"
 alias rr="cd .local/src/"
 alias dwm="cd .local/src/dwm"
 alias stt="cd .local/src/st"
 alias config="cd .config"

zplug "chitoku-k/fzf-zsh-completions"
#eval "$(starship init zsh)"
#lmaofeth
