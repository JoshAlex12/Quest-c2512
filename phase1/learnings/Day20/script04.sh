#!/bin/bash

# Define an array
fruits=("apple" "banana" "cherry")

# Access elements of the array
echo "First fruit: ${fruits[0]}"
echo "Second fruit: ${fruits[1]}"
echo "Third fruit: ${fruits[2]}"

echo "Number of fruits: ${#fruits[@]}"
# Loop through array elements
for fruit in "${fruits[@]}"; do
    echo "Fruit: $fruit"
done  