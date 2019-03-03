#!/bin/bash
echo "keep this in the dir where you want to change !!!"
echo " Lower to Upper : u"
echo " Upper to Lower : l"
read c
case $c in 
	-u):
	       rename 'y/a-z/A-Z/' *	
		;;
	-l):
		rename 'y/A-Z/a-z/' *
		;;

	esac
ls
