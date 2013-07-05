#!/bin/bash

echo "1 is $1"

VAR="global"

func() {
	#export VAR="local"
	echo "I am a function"	

	return 0;
} > out

func 

echo "fund returned $?, VAR is $VAR"


