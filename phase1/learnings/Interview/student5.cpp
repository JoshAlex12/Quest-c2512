// Fibonacii series

#include <iostream>
using namespace std;

void fib(int n){
    int term1 = 0;
    int term2 = 1;
    int nextTerm = 0;

    cout << term0 << "," << term1 << ",";

    for (int i = 1; i <= n; i++){
        cout << term1 << " ";
        nextTerm = term1 + term2;
        term1 = term2;

        term0 = term0 + term1;
        term1 = term0 + term1;
        cout << term0 << "," << term1 << ",";
    }
}


void printFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm = 0;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        cout << t1 << " ";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    cout << endl;
}


int main(){
    int numberOfTerms;
    cout << "Enter number of terms: "; cin >> numberOfTerms;
    printFibonacci(numberOfTerms);

    return 0;

}