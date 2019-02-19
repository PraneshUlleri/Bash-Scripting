#!/bin/bash
echo -n "Enter the number: "
read n
echo -n "Enter the limit: "
read l
counter=1
while [ $counter -le $l ]
	do
    a=`echo "$n * $counter" | bc -l`
	echo "$n * $counter = $a"
    ((counter++))
    done
