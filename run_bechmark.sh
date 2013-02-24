#!/bin/bash

make

na=20
echo "Running test 0"
./life r $na $((5*$na)) < input-files/input-0


files[10]=1
files[20]=2
files[100]=3
files[200]=4

echo "Running test 1"
for n in 10 20 100 200
do
	./life r $n $((5*$n)) < input-files/input-1.${files[$n]}
done

echo "Running test 2"
./life r 20 $((5*20)) < input-files/input-2
