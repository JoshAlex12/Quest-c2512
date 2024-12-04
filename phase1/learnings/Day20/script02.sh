#!/bin/bash
find_sum() {
    sum=$(( $1 + $2 ))
    echo "Sum: $sum"
    echo $sum
}

read -p "Enter first number: " num1
read -p "Enter second number: " num2
value=$(find_sum $num1 $num2)
echo $value