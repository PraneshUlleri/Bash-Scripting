#!/bin/bash
declare -A mat
rows=$1
coloumns=$2
arr=($@)
k=2
for((i=0;i<rows;i++))
do
	for((j=0;j<coloumns;j++))
	do
		mat[$i,$j]=${arr[$k]}
		k=`expr $k + 1`
	done
done
echo "Transpose"
for((i=0;i<rows;i++))
do
	for((j=0;j<coloumns;j++))
	do
		echo -n "${mat[$j,$i]} "
	done
	echo ""
done