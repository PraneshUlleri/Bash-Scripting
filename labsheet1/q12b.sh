#!/bin/bash
path=$1
usr=`whoami`
path="/home/$usr$path"
echo "PATH : $path"
while read -r line;
do 
	echo "$line"
done < "$path"
