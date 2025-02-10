#!/bin/bash

a=10
b=0

if [ $a == $b ]
then
	echo "a is equal to b"
elif [ $a -gt 1  ]
then
	echo "a is greater than 1"
elif [ $a -lt 1 ]
then
	echo "a is less than 1"
else
	echo "None of the condition is true"
fi
