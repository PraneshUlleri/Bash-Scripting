#!/bin/bash 
usr=`whoami`
echo "Enter the file path :/home/$usr "
read path
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

