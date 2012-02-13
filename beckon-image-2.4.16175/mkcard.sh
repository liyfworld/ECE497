#! /bin/sh
# mkcard.sh v0.5
# (c) Copyright 2009 Graeme Gregory <dp@xora.org.uk>
# Licensed under terms of GPLv2
#
# Parts of the procudure base on the work of Denys Dmytriyenko
# http://wiki.omap.com/index.php/MMC_Boot_Format

export LC_ALL=C

if [ $# -lt 2 ]; then
	echo "Usage: $0 <device (/dev/sdxxx)> <image folder>"
	exit 1;
fi

DRIVE=$1
IMAGE_NAME=$2

if [ ! "$3" == "" ]; then
        BOOT_XM=-$3
fi

CURRENT_DIR=$PWD
MNT_BOOT=/tmp/boot
MNT_ROOT=/tmp/rootfs


if [ -d $IMAGE_NAME ]; then
  echo Using image $IMAGE_NAME
else
  echo folder $2 not exist, please provide an existing image folder name.
  exit 1
fi


if [ -b $DRIVE ]; then
  echo using device $DRIVE
else
  echo No such device $DRIVE
  exit 1
fi

if [ -f $IMAGE_NAME/rootfs.tar.gz ]; then
  echo .
else
  if [ -f $IMAGE_NAME/rootfs.tar.bz2 ]; then
    echo .
  else
    echo no rootfs tarball at $IMAGE_NAME
    exit 1
  fi
fi

mount | grep $DRIVE
if [ "$?" -eq "0" ]; then
	mount | grep $DRIVE  | sed 's/ .*//g' | xargs umount
        echo unmounted ${DRIVE}.
fi

read -p "You are about to totaly erase the device, are you sure (yes/no) ?"
[ "$REPLY" == "yes" ] || exit 1

dd if=/dev/zero of=$DRIVE bs=1024 count=1024

if [ "$?" -ne "0" ]; then
        echo Failed to dd the ${DRIVE}.
        exit 1
fi

SIZE=`fdisk -l $DRIVE | grep Disk | grep bytes | awk '{print $5}'`

echo DISK SIZE - $SIZE bytes

CYLINDERS=`echo $SIZE/255/63/512 | bc`

echo CYLINDERS - $CYLINDERS

{
echo ,9,0x0C,*
echo ,,,-
} | sfdisk -D -H 255 -S 63 -C $CYLINDERS $DRIVE

if [ "$?" -ne "0" ]; then
        echo Failed to repartition ${DRIVE} drive.
        exit 1
fi

echo done partitioning.

sleep 1

if [ -b ${DRIVE}1 ]; then
	umount ${DRIVE}1
	mkfs.vfat -F 32 -n "boot" ${DRIVE}1

	if [ "$?" -ne "0" ]; then
        	echo Failed to format ${DRIVE}1.
	        exit 1
	fi
else
	echo "Cant find boot partition " ${DRIVE}1
fi

if [ -b ${DRIVE}2 ]; then
	umount ${DRIVE}2
	mke2fs -j -L "rootfs" ${DRIVE}2

	if [ "$?" -ne "0" ]; then
       		echo Failed to format ${DRIVE}2.
	        exit 1
	fi
else
	echo "Cant find rootfs partition in " ${DRIVE}2
fi

mkdir -p $MNT_BOOT
mount ${DRIVE}1 $MNT_BOOT

if [ "$?" -ne "0" ]; then
	echo Failed to mount ${DRIVE}1.
	rmdir $MNT_BOOT
	exit 1
fi

cp $IMAGE_NAME/boot$BOOT_XM/MLO $MNT_BOOT/
cp -u $IMAGE_NAME/boot$BOOT_XM/* $MNT_BOOT/
sync
umount $MNT_BOOT
rmdir $MNT_BOOT

mkdir -p $MNT_ROOT
mount ${DRIVE}2 $MNT_ROOT

if [ "$?" -ne "0" ]; then
        echo Failed to mount ${DRIVE}2.
	rmdir $MNT_ROOT
        exit 1
fi

tar xvzf $IMAGE_NAME/rootfs.tar.gz -C $MNT_ROOT
if [ "$?" -ne "0" ]; then
	tar xvjf $IMAGE_NAME/rootfs.tar.bz2 -C $MNT_ROOT
fi

mkdir $MNT_ROOT/sys
mkdir $MNT_ROOT/proc
sync
umount $MNT_ROOT
rmdir $MNT_ROOT

echo done.
