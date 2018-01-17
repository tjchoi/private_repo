#!/bin/sh
mode="Static"
echo $mode

set_ip_func() {

    local m="$1"

    if [ "$m" = "Static" ]
    then
        echo "I can change!"
    else
        echo "I can't change!"
    fi
    return 0;
}

set_ip_func $mode
