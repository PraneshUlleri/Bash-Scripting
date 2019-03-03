#!/bin/bash
COUNTER=0
         while [  $COUNTER -le $# ]; do
             let COUNTER=COUNTER+1 
         done
echo $COUNTER

