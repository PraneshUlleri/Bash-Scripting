#!/bin/bash
echo "Enter Destinaton with,/home/usr will added : "
read path
usr=`whoami`
path="/home/$usr$path"
#echo "$path"
echo -n "Number of files: "
read n
i=1
while [ $i -le $n ]
do
	echo -n "Enter file path for file $i,/home/usr will be added : "
	read fp
	fp="/home/$usr$fp"
	`mv $fp $path`
	((i++))
done
