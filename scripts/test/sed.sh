#!/bin/sh
#val="192.168.1.81,00:00:00:00:00:01,test1;192.168.1.82,00:00:00:00:00:02,test2;192.168.1.83,00:00:00:00:00:03,test3"

val="192.168.1.81,00:00:00:00:00:01,test1"

num=$(echo $val | sed 's/[^;]//g' | wc -c)
echo $num

for i in $(seq 1 $num); do
	ip=$(echo $val | cut -f $i -d ';' | cut -f 1 -d ',')
	mac=$(echo $val | cut -f $i -d ';' | cut -f 2 -d ',')
	comment=$(echo $val | cut -f $i -d ';' | cut -f 3 -d ',')
	
	if [ "$ip" != "" -a "$mac" != "" ]; then
		#config-udhcpd.sh -S $ip $mac $comment
		echo $ip $mac $comment
	fi
done

