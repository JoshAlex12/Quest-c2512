#!/bin/bash
read -p "Enter number: " num
tenPercent=$((( num / 100 ) * 10))
twentyPercent=$(expr  $num / 100  \* 20)
let thirtyPercent=num/100*30

newNum=$(( num + tenPercent ))
echo "10% increased of $num is $newNum."

newNumTwenty=$(( num + twentyPercent ))
echo "20% increased of $num is $newNumTwenty."

let newNumThirty=num+thirtyPercent
echo "30% increased of $num is $newNumThirty."
