#!/bin/sh

arg_num=$#
arg_list=$*
module=
arg_miss=0

show_usage() 
{
	echo ""
	echo "[USAGE] : "
	echo "Command : build.sh [arg_1] [arg_2] ... "
	echo ""
	echo "[Args] : module name to be build."
	echo "			module lists) omcid, libonu, onud, drvonu, drvoptic, drvswitch"
	echo ""
	echo "			ex) build.sh omcid libonu "
	echo ""
	exit
}

check_module()
{
	if [ "$1" = "omcid" ];then
		module+=" omcid"

	elif [ "$1" = "libonu" ];then
		module+=" libonu"

	elif [ "$1" = "onud" ];then
		module+=" onud"

	elif [ "$1" = "drvonu" ];then
		module+=" drvonu"
		
	elif [ "$1" = "drvoptic" ];then
		module+=" drvoptic"

	elif [ "$1" = "drvswitch" ];then
		module+=" drvswitch"

	else
		echo "$1 is not a module included in this system!"
		let "arg_miss += 1"
	fi
}

# Check module name
check_module_name()
{
	if [ $arg_num -eq 0 ];then
		show_usage
	fi

	for i in $arg_list
	do
		check_module $i
	done

	if [ $arg_miss -gt 0 ]; then
		show_usage
	fi
}

build_module()
{
	for i in $module
	do
		make $i-dirclean ; make $i
	done
	
	make
}

check_module_name

build_module





