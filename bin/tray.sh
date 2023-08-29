#!/usr/bin/env bash

## Author  : Aditya Shakya (adi1090x)
## Github  : @adi1090x
#
## Applets : Run Applications as Root

# Import Current Theme
source "$HOME"/.config/rofi/applets/shared/theme.bash
theme="$type/$style"

# Theme Elements
prompt=" $(cat /sys/class/power_supply/BAT0/capacity)% | 󱧦 $(uptime -p | sed -e 's/up //;s/ hours,/h/;s/ minutes/m/')"
mesg=$(date +" %d/%m %H:%M")

if [[ "$theme" == *'type-1'* ]]; then
	list_col='1'
	list_row='5'
	win_width='400px'
elif [[ ( "$theme" == *'type-2'* ) ]]; then
	list_col='5'
	list_row='1'
	win_width='670px'
fi

# Options
layout=`cat ${theme} | grep 'USE_ICON' | cut -d'=' -f2`
if [[ "$layout" == 'NO' ]]; then
	option_1="  Network"
	option_2="  Bluetooth"
	option_3="  Sound"
	option_4="  Power Menu"
	option_5="  configure"
else
	option_1=""
	option_2=""
	option_3=""
	option_4=""
	option_5=""
fi

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

# Pass variables to rofi dmenu
run_rofi() {
	echo -e "$option_1\n$option_2\n$option_3\n$option_4\n$option_5" | rofi_cmd
}

network() {
	st -e nmtui
}

bluetooth() {
	rofi-bluetooth -theme themes/bluetooth.rasi
}

powermenu() {
	powermenu.sh
}

sound() {
	pavucontrol
}

configure() {
	 st -e nvim .local/src/dwm/config.def.h
}

# Execute Command
run_cmd() {
	polkit_cmd="pkexec env PATH=$PATH DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY"
	if [[ "$1" == '--opt1' ]]; then
		network
	elif [[ "$1" == '--opt2' ]]; then
		bluetooth
	elif [[ "$1" == '--opt3' ]]; then
		pavucontrol
	elif [[ "$1" == '--opt4' ]]; then
		powermenu
	elif [[ "$1" == '--opt5' ]]; then
		configure
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
    $option_4)
		run_cmd --opt4
        ;;
    $option_5)
		run_cmd --opt5
        ;;
esac

