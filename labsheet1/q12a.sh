#/bin/bash
usr=`whoami`
echo "enter the file path:/home/$usr"
read path
path="/home/$usr$path"
while read -r line; 
do 
        echo "$line"
done < "$path"

