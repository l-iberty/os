argc=$#
if [ $argc -ne 2 ]
then echo "usage: $0 <src_file> <img_file>"
else
	dd if=$1 of=$2 bs=512 count=1 conv=notrunc
fi
