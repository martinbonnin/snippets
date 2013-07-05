#!/bin/bash
OPTIONS="a=\"a a\" b=b"
echo $OPTIONS
eval ./a.out $OPTIONS
./a.out $OPTIONS

