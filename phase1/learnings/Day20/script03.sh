#  Lab: find factorial using function in shell scripting.
#         function name: findFact
#         receives one arg which is number 
#         sends factorial by echoing / printing

#         And conduct call to findFact 
#             for the 1. test case 1: input data 5 
#                     2. test case 2: input data 3

#!/bin/bash
find_fact() {
    fact=1
    for (( i=1; i<=$1; i++ )); do
        # fact=$(( fact * i ))
        # fact=$(( fact * i ))
        # fact=$(expr $fact \* $i )

    done
    echo $fact
}

read -p "Enter number: " fact
value=$(find_fact $fact)
echo $value