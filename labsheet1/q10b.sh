#!/bin/bash
usr=`whoami`
i=0
path="/home/$usr"
for var in "$@"
do
   if test $i -eq 0
   then
   	path="$path$var"
   else
   	fp=$var
   	fp="/home/$usr$fp"
	`mv $fp $path`
   fi 
   ((++i))
done
#'mv $path $arg`