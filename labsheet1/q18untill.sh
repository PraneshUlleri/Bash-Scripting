 #!/bin/bash 
 COUNTER=$#
 until [  $COUNTER -le 1 ]; 
 do     
     let COUNTER-=1
 done
 
echo $COUNTER
