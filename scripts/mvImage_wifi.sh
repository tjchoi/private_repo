#!/bin/sh

date=`date +%G-%m-%d_%R`

cur_path=`pwd`

cd images

mv tjchoi_uImage uImage_wifi_tjchoi_$date

mv uImage_wifi_tjchoi_$date /tftpboot/tjchoi/wifi-CPE

cd /tftpboot/tjchoi/wifi-CPE

unlink uImage

ln -s uImage_wifi_tjchoi_$date uImage

cd $cur_path

ls -la /tftpboot/tjchoi/wifi-CPE | grep 'uImage '

