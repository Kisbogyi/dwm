#!/bin/bash

CONFIG=/home/bandi/Tools/Configs/dwm/
#$CONFIG/bar.sh &

# if [[ $(xrandr | grep "HDMI-1-0 connected" | cut -d " " -f 1-2) ]]; then 
         # xrandr --output HDMI-1-0 --mode 3840x2160 --right-of eDP;
# fi
feh --bg-fill ~/Rice/wallpaper/wallpaper_earth.png
xss-lock --transfer-sleep-lock -- i3lock -k -i ~/Rice/wallpaper/wallpaper_earth.png -t --nofork &
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


