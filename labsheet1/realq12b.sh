usr=`whoami`
path=$1
path="/home/$usr$path"

echo "PATH : $path"

ls "$path"
