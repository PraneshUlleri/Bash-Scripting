#!/bin/bash
COUNTER=$#
         while [  $COUNTER -le 1 ]; do
             let COUNTER=COUNTER-1 
         done
echo $COUNTER

