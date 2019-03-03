#!/bin/bash

usr=`whoami`

echo "Name of the users: "
w
echo " "
echo "Name of the current user"
whoami
echo " "
echo "Current Shell "
echo $SHELL
echo " "
echo "Operating System Type"
lsb_release -a
echo " "
echo "Current Path: "
$PATH
echo " "
echo "Current Working Dir:"
echo $PWD
echo " "
echo "Available Shells: "
cat /etc/shells
echo " "
echo "Additional Info's :"
hostnamectl
echo " "
echo "Setting path:"
echo "(y or n ?)"
read c
if [ $c=='y' ]
then 
	
	echo "setting new path:"
	echo -n "enter the path : /home/$usr"
	read path1
	export PATH=$PATH:/home/$usr$path1
fi

