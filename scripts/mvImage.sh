#!/bin/sh

date=`date +%G-%m-%d_%R`

cur_path=`pwd`

if [ "$1" = "asic" ];then
	board="ASIC"

elif [ "$1" = "fpga" ];then
	board="FPGA"

else
	echo "ERROR : wrong agument"
	echo "[arg] : 'fpga' or 'asic'"
	exit
fi

cd output/images

mv uImage uImage_xgs_tjchoi_$date

mv uImage_xgs_tjchoi_$date /tftpboot/tjchoi/XGS/$board

cd /tftpboot/tjchoi/XGS/$board

unlink uImage

ln -s uImage_xgs_tjchoi_$date uImage

cd $cur_path

ls -la /tftpboot/tjchoi/XGS/$board | grep 'uImage '

mkimage -l /tftpboot/tjchoi/XGS/$board/uImage


