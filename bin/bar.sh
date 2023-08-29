#!/bin/dash

# ^c$var^ = fg color
# ^b$var^ = bg color

interval=0

# load colors
. ~/.local/bin/bar_themes/oceanicnext

#####-------------------------------------------------------------------------------------------------------#####

cpu() {
  cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)

  printf "^c$red^ CPU"
  printf "^c$grey_alt^ $cpu_val"
}

#####-------------------------------------------------------------------------------------------------------#####

PREFIX="^c$red^ "
FIRE="^c$red^ "

WARNING_LEVEL=80

get_cputemp()
{
  # CPU_T=$(cat /sys/devices/platform/coretemp.0/hwmon/hwmon?/temp2_input)
  # CPU_TEMP=$(expr $CPU_T / 1000)

  CPU_TEMP="$(sensors | grep temp1 | awk 'NR==1{gsub("+", " "); gsub("\\..", " "); print $2}')"

  if [ "$CPU_TEMP" -ge $WARNING_LEVEL ]; then
    PREFIX="$FIRE$PREFIX"
  fi

  echo "$PREFIX^c$grey_alt^$CPU_TEMP°C"
}

#####-------------------------------------------------------------------------------------------------------#####

pkg_updates() {
  #updates=$({ timeout 20 doas xbps-install -un 2>/dev/null || true; } | wc -l) # void
  updates=$({ timeout 20 checkupdates 2>/dev/null || true; } | wc -l) # arch
  # updates=$({ timeout 20 aptitude search '~U' 2>/dev/null || true; } | wc -l)  # apt (ubuntu, debian etc)

  if [ -z "$updates" ]; then
    printf "^c$green^  Fully Updated"
  else
    printf "^c$green^  $updates"" updates"
  fi
}

#####-------------------------------------------------------------------------------------------------------#####

battery_status() {
state=$(cat /sys/class/power_supply/BAT0/status)
if [ $state = "Charging" ]; then
    echo "^c$green^ " # charging
elif [ $state = "Discharging" ]; then
    echo "^c$green^" # discharging
elif [ $state = "idle" ]; then
    echo "^c$green^ " # idle
else
    echo "^c$green^ " # idle
fi
}

#####-------------------------------------------------------------------------------------------------------#####

battery_capacity() {
cap=$(cat /sys/class/power_supply/BAT0/capacity)
if [ $cap -ge 0 ] && [ $cap -le 20 ]; then
    echo " " ^c$grey_alt^$cap"%"
elif [ $cap -ge 21 ] && [ $cap -le 40 ]; then
    echo " " ^c$grey_alt^$cap"%"
elif [ $cap -ge 41 ] && [ $cap -le 60 ]; then
    echo " " ^c$grey_alt^$cap"%"
elif [ $cap -ge 61 ] && [ $cap -le 90 ]; then
    echo " " ^c$grey_alt^$cap"%"
elif [ $cap -ge 91 ] && [ $cap -le 100 ]; then
    echo " " ^c$grey_alt^$cap"%"
else
    echo "UNKNWN"
fi
}

#####-------------------------------------------------------------------------------------------------------#####

brightness() {
  light=$(brightnessctl -m -d amdgpu_bl1 | cut -d, -f4 | tr -d %)
echo "^c$yellow_alt^" $light #"%"
}

#####-------------------------------------------------------------------------------------------------------#####

volume() {
ou_mute=$(pamixer --get-mute)
in_mute=$(pamixer --source 1 --get-mute)
ou_vol=$(pamixer --get-volume)
in_vol=$(pamixer --source 1 --get-volume)
jack_stat=$(~/.local/bin/dwmstatus_module/has_headphone)

if   [ $jack_stat = "yes" ]; then
    icon_ou_on="^c$dwm_alt^󰋋"
    icon_ou_off="^c$dwm^󰋐"
elif [ $jack_stat = "no"  ]; then
    icon_ou_on="^c$dwm_alt^ "
    icon_ou_off="^c$dwm^ "
fi
#icon_in_on=""
#icon_in_off=""

if   ([ $ou_mute = "true"  ] || [ $ou_mute = "off" ]); then #&& ([ $in_mute = "true"  ] || [ $in_mute = "off" ]); then
    printf "$icon_ou_off Ø $icon_in_off Ø" 
elif ([ $ou_mute = "true"  ] || [ $ou_mute = "off" ]); then #&& ([ $in_mute = "false" ] || [ $in_mute = "on"  ]); then
    printf "$icon_ou_off Ø $icon_in_on ^c$grey_alt^$in_vol"
elif ([ $ou_mute = "false" ] || [ $ou_mute = "on"  ]); then #&& ([ $in_mute = "true"  ] || [ $in_mute = "off" ]); then
    printf "$icon_ou_on ^c$grey_alt^$ou_vol" #$icon_in_off Ø"
elif ([ $ou_mute = "false" ] || [ $ou_mute = "on"  ]); then #&& ([ $in_mute = "false" ] || [ $in_mute = "on"  ]); then
    printf "$icon_ou_on ^c$grey_alt^$ou_vol $icon_in_on ^c$grey_alt^$in_vol"
else
    printf "$icon_ou_off ERROR"
fi
}

#####-------------------------------------------------------------------------------------------------------#####

mem() {
  printf "^c$blue^ ^b$black^  "
  printf "^c$blue^ $(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)"
}

#####-------------------------------------------------------------------------------------------------------#####

wlan_net () {
wlan_card='wlp2s0'
wlanmon_card=$(ip a s | grep $wlan_card'mon' | awk 'NR%1==0 {print $2}' | sed 's/://g')
if [ $wlanmon_card ]; then
    printf " MONITOR"
fi

wlan_online=$(iw $wlan_card link | grep 'Connected' | awk 'NR%1==0 {print $1}')
wlan_offline=$(iw $wlan_card link | grep 'Not' | awk 'NR%1==0 {print $1}')
internet=$(wget -qO- ifconfig.co)
internet_logo=""
if [ $internet ]; then
    internet_logo="󱄀 "
else
    internet_logo=" "
fi

if [ $wlan_online ]; then
    wlan_do=$(ifstat2 -i $wlan_card 1 1 | awk 'NR%3==0 {print $1}')
    wlan_up=$(ifstat2 -i $wlan_card 1 1 | awk 'NR%3==0 {print $2}')
    printf "^c$white^ $internet_logo ^c$green^ ^c$grey_alt^%3s ^c$green^ ^c$grey_alt^%3s\\n" \
    $(numfmt --to=none $wlan_do) \
    $(numfmt --to=none $wlan_up)
elif [ $wlan_offline ];then
    printf " OFFLINE"
else
    printf " NOADPTR"
fi
}

#####-------------------------------------------------------------------------------------------------------#####

clock() {
	printf "^c$white^  "
	printf "^c$white^$(date "+%b %d | %I:%M%p")"
}

#clock() {
#    clock=$(date '+%I')

#case "$clock" in
#    "00") icon="🕛" ;;
#    "01") icon="🕐" ;;
#    "02") icon="🕑" ;;
#    "03") icon="🕒" ;;
#    "04") icon="🕓" ;;
#    "05") icon="🕔" ;;
#    "06") icon="🕕" ;;
#    "07") icon="🕖" ;;
#    "08") icon="🕗" ;;
#    "09") icon="🕘" ;;
#    "10") icon="🕙" ;;
#    "11") icon="🕚" ;;
#    "12") icon="🕛" ;;
#esac
#
#date "+%b %d $icon%I:%M%p"
#}

#####-------------------------------------------------------------------------------------------------------#####

separator() {
    printf "^c$grey_dwm^ "
}

#####-------------------------------------------------------------------------------------------------------#####

while true; do

  [ $interval = 0 ] || [ $(($interval % 3600)) = 0 ] && updates=$(pkg_updates)
  interval=$((interval + 1))

  sleep 1 && xsetroot -name "$(separator) $(wlan_net) $(volume)  $(brightness)  $(battery_status) $(battery_capacity) $(clock) $(separator)"
done
