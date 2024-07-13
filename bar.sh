#!/bin/bash

sleep 0.1
xrandr --output HDMI-1-0 --mode 1920x1080 --left-of eDP
feh --bg-fill ~/Pictures/CassiopeaA.png -Z
while true; do
	if upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep "state: .* discharging" > /dev/null
	then
		discharge="$(upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep "energy-rate: " | sed 's/ *energy-rate: *//')"
	fi

	battery="$(upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep "percentage:"| sed 's/ *percentage: *//')"
	xsetroot -name "$discharge 🔋 $battery $(date)" 
	sleep 1
done
