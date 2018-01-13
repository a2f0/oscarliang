#!/bin/bash
#this will get the i2c clock frequcncy of a Pi-3 model B
#tested o debian stretch
var="$(xxd /sys/class/i2c-adapter/i2c-1/of_node/clock-frequency | awk -F': ' '{print $2}')"
var=${var//[[:blank:].\}]/}
printf "%d\n" 0x$var
