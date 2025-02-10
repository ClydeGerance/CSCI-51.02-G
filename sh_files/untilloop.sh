#!/bin/bash

a=0

until [ $a -gt 11 ]
do 
	echo $a
	a=`expr $a + 1`
done
