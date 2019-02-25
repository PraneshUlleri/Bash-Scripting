#!/bin/bash
n=$1
counter=1
if test $n -eq 1 
then
	echo "0"
else
first=0
second=1
echo -n "$first $second"
((n=n-2))
while [ $counter -le $n ]
	do
	third=`echo "$first + $second" | bc`
	echo -n " $third"
	first=$second;
	second=$third;
	((counter++))
	done
fi