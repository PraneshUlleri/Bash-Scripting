#!/bin/bash
echo -n "Enter n: "
read n
x=2
while test $x -le $n
do
	c=2
	f=0
	while test $c -le `expr $x / 2`
	do

	if test `expr $x % $c` -eq 0
	then
	f=1
	fi
	c=`expr $c + 1`

	done

	if test $f -eq 1
	then
		echo -n ""
	else
		echo -n "$x " 
	fi
	
	x=`expr $x + 1` 
done
