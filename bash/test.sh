#!/bin/bash
echo $$
[ -f /var/run/gentilrobot.pid ] && (echo "iojo"; echo "tat"; exit 6)
echo "after"
PWD=`dirname $0`
echo "DIR: $PWD"
A=`basename $PWD`
echo "A: $A"
/bin/bash -c 'sleep 30'

