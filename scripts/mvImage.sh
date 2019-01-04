#!/bin/sh

date=`date +%G-%m-%d_%R`
tftp="/tftpboot/tjchoi/XGS/"
cur_path=`pwd`
output_path="output/images"
output_image="uImage"
new_image_name="uImage_xgs_tjchoi_${date}"



print_success()
{
	echo ""
	echo "##############################################"
	echo "##### Image Located in TFTP Successfully #####"
	echo "##############################################"
	mkimage -l ${tftp}${board}${revision}${output_image}
}

if [ "$1" = "asic" ];then
	board="ASIC/"

elif [ "$1" = "fpga" ];then
	board="FPGA/"

else
	echo "ERROR : wrong agument"
	echo "[arg] : 'fpga' or 'asic'"
	exit
fi

if ! [ $2 ];then
	echo "ERROR : revision argument is empty"
	exit
fi

revision=`echo $2 | tr  '[a-z]' '[A-Z]'`

image_path="${tftp}${board}${revision}"

# If directory is not exist !
if ! [ -d ${image_path} ];then  
	echo "ERROR : wrong agument"
	echo "${image_path} is not exist "
	exit
fi

cd ${output_path}

# If output image file is not exist !
if ! [ -e ${output_image} ];then
	echo "ERROR : output image is not exist !"
	exit
fi

# change output image name to new name !
mv ${output_image} ${new_image_name}

# locate image in designated tftp path
mv ${new_image_name} ${tftp}${board}${revision}

cd ${tftp}${board}${revision}

unlink ${output_image}

ln -s ${new_image_name} ${output_image}

cd ${cur_path}

ls -la ${tftp}${board}${revision} | grep 'uImage ' && print_success

