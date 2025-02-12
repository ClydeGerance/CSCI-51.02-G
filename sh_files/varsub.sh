#!/bin/bash

var="Applesx"

echo ${var:-"Apples"}
echo "I love ${var}s"

echo ${var:="Oranges"}
echo "But I also love ${var}"

echo ${var:+"Bananas"}
echo "I hate $vars"

var="kiwi"
echo ${var:+"This is the default value"}
echo "Healthiest fruit is $var"
unset var
echo ${var:?"Print this message"}
echo "I eat ${var}"
