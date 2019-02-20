#!/bin/bash
filename="Q3c.txt"
while read -r line; do
    n="$line"
done < $filename
l=10
counter=1
while [ $counter -le $l ]
	do
    a=`echo "$n * $counter" | bc -l`
	echo "$n * $counter = $a"
    ((counter++))
    done
