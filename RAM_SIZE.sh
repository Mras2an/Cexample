#!/bin/sh

# RAM size for elf file 

size=0

nm --print-size --size-sort --radix=d src/main | cut -c11-18 > RAM.txt

while read line  
do
   size=$(echo $line $size | awk '{ printf "%d\n", $1 + $2 }')
done < RAM.txt

echo "Size RAM = " $size "Octet(s)"
size=$(echo $size 1024 | awk '{ printf "%d\n", $1 / $2 }')
echo "Size RAM = " $size "Ko"

