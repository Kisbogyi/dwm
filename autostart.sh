#!/bin/bash

CONFIG=/home/bandi/Configs/dwm/
#$CONFIG/bar.sh &
feh --bg-fill ~/Pictures/purple.png -Z &
setxkbmap us
dwmblocks &
exec dwm

#
#if upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep "state: .* discharging" > /dev/null
#then
#	sudo powertop --auto-tune
#fi
#
#if ! xrandr | grep "HDMI.* disconnected" > /dev/null
#then
#	xrandr --output HDMI-1-0 --mode 1920x1080 --right-of eDP
#fi


