#!/bin/bash
usr=`whoami`
echo -n "Enter the path : /home/$usr"
read path
path="/home/$usr$path"

ls -r  $path
