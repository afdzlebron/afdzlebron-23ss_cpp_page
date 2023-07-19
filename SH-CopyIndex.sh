#!/bin/bash

# n=$1
n=10

for ((i=1; i<=n; i++))
do
    num=$(printf "%02d" $i)
    cp index.html "blatt${num}.html"
done

