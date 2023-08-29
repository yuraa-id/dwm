#!/usr/bin/env bash

rofi_command="rofi -theme themes/style-2.rasi"

# Theme Elements
prompt='Applications'
mesg='Take Screenshots'

# Options
screen=""
area=""
timer=""

# Rofi CMD
rofi_cmd() {
    rofi -theme-str "window {width: $win_width;}" \
        -theme-str "listview {columns: $list_col; lines: $list_row;}" \
        -theme-str 'textbox-prompt-colon {str: "";}' \
        -dmenu \
        -p "$prompt" \
        -mesg "$mesg" \
        -markup-rows \
        -theme ${theme}
}

# Variable passed to rofi
options="$screen\n$area\n$timer"

chosen="$(echo -e "$options" | $rofi_command -dmenu -selected-row 1)"
case $chosen in
    $screen)
        ~/.local/bin/scripts/shot-now delay
        ;;
    $area)
        ~/.local/bin/scripts/shot-seldraw
        ;;
    $timer)
        ~/.local/bin/scripts/shot-timer
        ;;
esac