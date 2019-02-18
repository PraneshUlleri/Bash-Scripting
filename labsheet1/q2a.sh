#!/bin/bash
echo "| Operation | Code |"
echo "| Add       |  -a  |"
echo "| Subtract  |  -s  |"
echo "| Multiply  |  -m  |"
echo "| Quotiet   |  -c  |"
echo "| Reminder  |  -m  |"
read op
echo -n "Enter first number: "
read a
echo -n "Enter Second number: "
read b
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
