#!/usr/bin/env bash

# Import Current Theme
source "$HOME"/.config/rofi/themes/shared/theme.bash
theme="$type/$style"

# Theme Elements
prompt='Screenshot'
mesg="Take Screenshot"

if [[ ( "$theme" == *'theme'* ) ]]; then
    list_col='5'
    list_row='1'
    win_width='300px'
fi

layout=`cat ${theme} | grep 'USE_ICON' | cut -d'=' -f2`
if [[ "$layout" == 'NO' ]]; then
    option_1=" Capture Desktop"
    option_2=" Capture Area"
    option_3=" Capture Timer"
else
    option_1=""
    option_2=""
    option_3=""
fi

# Options
#screen=""
#area=""
#timer=""

# Rofi CMD
rofi_cmd() {
    rofi -theme-str "window {width: $win_width;}" \
        -theme-str "listview {columns: $list_col; lines: $list_row;}" \
        -theme-str 'textbox-prompt-colon {str: "";}' \
        -dmenu \
        -p "$prompt" \
        -mesg "$mesg" \
        -markup-rows \
        -theme ${theme}
}

# Pass variables to rofi dmenu
run_rofi() {
    echo -e "$option_1\n$option_2\n$option_3" | rofi_cmd
}

# Variable passed to rofi
#options="$screen\n$area\n$timer"

shot-now() {
    ~/.local/bin/scripts/shot-now delay
}

shot-seldraw() {
    ~/.local/bin/scripts/shot-seldraw
}

shot-timer() {
    ~/.local/bin/scripts/shot-timer
}

# Execute Command
run_cmd() {
    if [[ "$1" == '--opt1' ]]; then
        shot-now
    elif [[ "$1" == '--opt2' ]]; then
        shot-seldraw
    elif [[ "$1" == '--opt3' ]]; then
        shot-timer
    fi
}


# Actions
chosen="$(run_rofi)"
case ${chosen} in
    $option_1)
        run_cmd --opt1
        ;;
    $option_2)
        run_cmd --opt2
        ;;
    $option_3)
        run_cmd --opt3
        ;;
esac

