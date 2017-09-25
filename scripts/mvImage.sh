#!/bin/sh

date=`date +%G-%m-%d_%k:%M`

cur_path=`pwd`

if [ "$1" = "asic" ];then
	board="ASIC"

elif [ "$1" = "fpga" ];then
	board="FPGA"

else
	echo "ERROR : wrong agument\n"
	echo "[arg] : 'fpga' or 'asic'\n"
	exit
fi

cd output/images

mv uImage uImage_xgs_tjchoi_$date

mv uImage_xgs_tjchoi_$date /tftpboot/tjchoi/XGS/$board

cd /tftpboot/tjchoi/XGS/$board

unlink uImage

ln -s uImage_xgs_tjchoi_$date uImage

cd $cur_path

ls /tftpboot/tjchoi/XGS/$board

