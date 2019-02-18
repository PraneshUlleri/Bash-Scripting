#!/bin/bash 
echo "Enter length:" 
read length 
echo "Enter breadth: " 
read breadth 
area=`echo "$length*$breadth" | bc -l` 
perimeter=`echo "2*($length+$breadth)" | bc -l` 
echo "Area : $area" 
echo "Perimeter : $perimeter" 
echo "Enter radius of the circle: " 
read radius 
pi=3.14 
area=`echo "$pi*$radius*$radius" | bc -l` 
perimeter=`echo "2*$pi*$radius" | bc -l` 
echo "Area : $area" 
echo "Perimeter : $perimeter" 
 
 
