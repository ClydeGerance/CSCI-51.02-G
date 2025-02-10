#!/bin/bash

while getopts "abdfx" j 
do
	case $j in
		a|b) echo "First 2 letters of the Greek alphabet";;
		d) echo "Doctor!";;
		x) echo "Marks the spot"
		   echo $1$2;;
	esac
done

