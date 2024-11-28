#include <iostream>
using namespace std;

void printLvalue(int &x)
{
    cout << "Lvalue Reference: " << x << endl;
    cout << "Lvalue Reference: " << &x << endl;
}

void printRvalue(int &&x)
{
    cout << "Rvalue Reference: " << x << endl;
}

int main()
{
    int a = 10;     // a is an lvalue
    printLvalue(a); // Works, as 'a' is an lvalue

    printLvalue(20); // Error! 20 is an rvalue, not an lvalue

    printRvalue(20);     // Works, as 20 is an rvalue
    printRvalue(a + 10); // Works, as (a + 10) is an rvalue

    // int &&r = a;    // Error! 'a' is an lvalue, cannot bind to rvalue reference
    int &&r = 30; // Works, r is now bound to the temporary rvalue 30
    cout << "Rvalue Reference Variable: " << r << endl;

    return 0;
}
