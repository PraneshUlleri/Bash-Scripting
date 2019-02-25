#!/bin/bash
a=$1
b=$2
if test `expr $a -l $b`
then
	mx=$a
else
	mx=$b
fi
c=1
ans=0
while [ $c -le $mx ]
do
a1=`expr $a % $c`
a2=`expr $b % $c`

if [ $a1 -eq 0 -a $a2 -eq 0 ]
then
ans=$c
fi

c=`expr $c + 1`
done
echo "GCD : $ans"
