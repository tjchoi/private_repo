#!/bin/sh

if [ "$1" = "omcid" ];then
	module="omcid"

elif [ "$1" = "libonu" ];then
	module="libonu"

elif [ "$1" = "onud" ];then
	module="onud"

elif [ "$1" = "drvonu" ];then
	module="drvonu"
	
elif [ "$1" = "drvoptic" ];then
	module="drvoptic"

elif [ "$1" = "drvswitch" ];then
	module="drvswitch"

else
	echo ""
	echo "[HELP] : "
	echo "Command : build.sh [arg_1] ([arg_2]) "
	echo ""
	echo "[Arg_1] : module name to be build."
	echo "          ex) omcid, libonu, onud, drvonu, drvoptic, drvswitch"
	echo ""
	echo "[Arg_2] : (optional) make image"
	echo "          ex) image"
	echo ""
	exit
fi

if [ "$2" = "image" ];then
	make $module-dirclean ; make $module ; make

else
	make $module-dirclean ; make $module

fi


