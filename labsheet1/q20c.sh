#!/bin/bash
usr=`whoami`
filename="Q20c1.txt"
while read -r line; do
    n="$line"
done < $filename
path="`pwd`$n"
echo "$path"
grep -o " " $path | wc -l
