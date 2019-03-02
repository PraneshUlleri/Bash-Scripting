#!/bin/bash
usr=`whoami`
echo "enter the dir: /home/$usr"
read path
path="/home/$usr$path"

echo "PATH : $path"

ls "$path"	
