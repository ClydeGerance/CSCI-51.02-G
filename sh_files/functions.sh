#!/bin/bash

Hello () {

echo "Hello $1 $2"

innerfunc 

return 20

}

innerfunc () {

echo "I'm a nested function!"

}

Hello Alicia Bobby

ret=$?

echo "Return value is $ret"

