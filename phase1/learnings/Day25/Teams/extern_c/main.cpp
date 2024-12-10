#include <iostream>
extern "C" {
    #include "math_utils.h"
}
using namespace std;

int main(){
    int a = add(5, 4);
    cout << a << endl;
    return 0;
}