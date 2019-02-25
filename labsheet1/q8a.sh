#!/bin/bash
declare -A mat
echo -n "Enter rows : "
read rows
echo -n "Enter coloumns: "
read coloumns
for((i=0;i<rows;i++))
do
	for((j=0;j<coloumns;j++))
	do
		echo -n "Enter mat[$i,$j] element: "
		read temp
		mat[$i,$j]=$temp
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