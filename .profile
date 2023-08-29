#!/bin/sh
export PATH=$HOME/.local/bin:/usr/local/bin:$PATH
export PATH=$HOME/.local/bin/scripts:$PATH
export PATH=$HOME/.local/bin:$PATH

powerkit &
xset -b &
picom &
bar.sh &
#dwmstatus &
nitrogen --restore &
/usr/lib/mate-polkit/polkit-mate-authentication-agent-1 &
