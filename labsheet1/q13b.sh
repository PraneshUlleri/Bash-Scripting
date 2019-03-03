#!bin/bash
path=$1
searchword=$2
usr=`whoami`
path="/home/$usr$path"

echo "PATH : $path"

echo "\"$searchword\" search result here"
grep -n "$searchword" $path
