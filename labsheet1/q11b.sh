#!/bin/bash 
path=$1
usr=`whoami`
path="/home/$usr$path"
echo " "
echo "PATH : $path"
echo " "
echo -n "number of line: "
wc -l  < "$path"
echo -n "number of words: "
wc -w < "$path"
echo -n "number of character: "
wc -c < "$path"

