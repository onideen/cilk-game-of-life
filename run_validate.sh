#!/bin/bash

make

na=20
echo "Running test 0"
./life_debug r $na $((5*$na)) < input-files/input-0 |./validate $na 5*$na 0


files[10]=1
files[20]=2
files[100]=3
files[200]=4

echo "Running test 1"
for n in 10 20 100 200
do
	./life_debug r $n $((5*$n)) < input-files/input-1.${files[$n]} |./validate $n 5*$n 1
done

echo "Running test 2"
./life_debug r 20 $((5*20)) < input-files/input-2 |./validate 20 5*20 2
