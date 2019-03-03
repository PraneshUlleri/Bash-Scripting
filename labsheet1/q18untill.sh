 #!/bin/bash 
 COUNTER=1
 until [  $COUNTER -ge $# ]; 
 do     
# echo "1"
     	 let COUNTER=COUNTER+1
 done
 
echo $COUNTER
