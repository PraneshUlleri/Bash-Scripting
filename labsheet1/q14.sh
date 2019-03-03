#!/bin/bash
usr=`whoami`
echo -n "Enter the file-1 path: /home/$usr"
read path1
echo -n "Enter the file-2 path: /home/$usr"
read path2

path1="/home/$usr$path1"
path2="/home/$usr$path2"

echo "Name of new file: "
read filename
echo "dir where you want the new file <without the file name>:/home/$usr"
read path3

path3="/home/$usr$path3/$filename"

cat $path1 $path2 > $path3

cat $path3
