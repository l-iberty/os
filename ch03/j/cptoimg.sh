# usage: ./cptoimg.sh <src_file> <img_file>

argc=$#
if [ $argc -ne 2 ]
then echo "usage: ./cptoimg.sh <src_file> <img_file>"
else
	sudo mount -o loop $2 /mnt/floppy
	sudo cp $1 /mnt/floppy
	sudo umount /mnt/floppy
fi
