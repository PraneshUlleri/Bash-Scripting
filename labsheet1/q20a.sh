#!/bin/bash 
usr=`whoami`
echo "path to the file : /home/$usr"
read path
path="/home/$usr$path"

grep -o " " $path | wc -l 
