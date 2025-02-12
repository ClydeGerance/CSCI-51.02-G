#!/bin/bash

unset var  # Ensure var is unset

echo "${var:-default}"  # Expands to "default", but does not assign it
echo "var after :- : $var"

echo "${var:=assigned}"  # Expands to "assigned" and assigns it to var
echo "var after := : $var"

echo "${var:+replacement}"  # Expands to "replacement" because var is set
echo "var after :+ : $var"

unset var  # Unset again
echo "${var:?Error: var is not set}"  # Exits script with error if var is unset
