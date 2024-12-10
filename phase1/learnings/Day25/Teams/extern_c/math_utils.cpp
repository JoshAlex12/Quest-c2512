#include <stdio.h>

extern "C"{
#include "math_utils.h"
    int addition(int a, int b){
        // printf("This is add in C");
        return a + b;
    }

    int subtract(int a, int b){
        printf("This is substract in C");
        return a - b;
    }
}