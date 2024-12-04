#!/bin/bash
getopts "f:s:t:" opt;
if [ $opt = "f" ]; then
    num1=$OPTARG;
else 
    echo "Error: -f option not found";
    exit 1;
fi

getopts "f:s:t:" opt;
if [ $opt = "s" ]; then
    num2=$OPTARG;
else 
    echo "Error: -s option not found";
    exit 1;
fi

getopts "f:s:t:" opt;
if [ $opt = "t" ]; then
    num3=$OPTARG;
else 
    echo "Error: -t option not found";
    exit 1;
fi

s=$((num1 + num2 + num3));
echo "Sum of $num1, $num2, $num3: $s";