#!/bin/bash
a=$2
op=$1
b=$3
#echo "$# $0 $1 $2"
case $op in
	-a): 
		ans=`echo "$a+$b" | bc`
		;;
	-s): 
		ans=`echo "$a-$b" | bc`
		;;
	-m):
		ans=`echo "$a*$b" | bc`
		;;
	-c):
		ans=`echo "scale=3; $a/$b" | bc -l`
		;;
	-r):
		ans=`echo "$a%$b" | bc`
		;;
	*):
		echo "Invalid operator"
		ans="Invalid"
		;;
esac
echo "Answer: $ans"