#!/bin/bash
trap "echo GOT SIGINT" INT

./a.out
echo "TOTO"
./a.out
echo "TATA"
