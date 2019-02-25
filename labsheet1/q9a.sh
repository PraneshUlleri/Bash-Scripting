#!/bin/bash
echo -n "Enter x1: "
read x1
echo -n "Enter y1: "
read y1
echo -n "Enter x2: "
read x2
echo -n "Enter y2: "
read y2
echo -n "Vector product : "
echo "$x1 * $x2 + $y1 * $y2 " | bc