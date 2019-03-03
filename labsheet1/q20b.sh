#!/bin/bash 
usr=`whoami`
path=$1
path="/home/$usr$path"

grep -o " " $path | wc -l 
