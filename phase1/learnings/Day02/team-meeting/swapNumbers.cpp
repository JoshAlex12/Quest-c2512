#include <iostream>
using namespace std;

void swapNums(int &num1,int &num2){
    int temp=num1;
    num1=num2;
    num2=temp;
}

void swapNumsTest(){
    int num1,num2;
    cout << "Enter number 1:";
    cin >> num1;
    cout << "Enter number 2:";
    cin >> num2;
    swapNums(num1,num2);
    cout << "Number 1:" << num1;
    cout << "\nNumber 2:" << num2;
}


int main()
{
    swapNumsTest();

    return 0;
}
