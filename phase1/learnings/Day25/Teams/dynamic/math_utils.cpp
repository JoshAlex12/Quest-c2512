// #include <iostream>
#include "math_utils.h"
extern "C" {
    #include <cstdio>
    int addition(int a, int b){
        printf("This is add in C");
        return a + b;
    }

    int subtract(int a, int b){
        // cout << "This is substract in C" ;
        return a - b;
    }
}