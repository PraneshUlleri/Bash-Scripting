#!/bin/bash
echo -n "Enter number: "
read number
i=2  
f=0 
while test $i -le `expr $number / 2`  
do
  
if test `expr $number % $i` -eq 0  
then
f=1 
fi
   
i=`expr $i + 1` 
done
if test $f -eq 1  
then
echo "Not a Prime Number"
else
echo "Prime Number"
fi
