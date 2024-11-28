#include <iostream>
#define MAX_SIZE 100
using namespace std;

int readAges(int ages[]){
    int index=0;
    int age;
    cout << "Enter ages:" << endl;
    cin >> age;
    while(age>0){
        ages[index]=age;
        index = index+1;
        cin >> age;
    }
    return index;
}

int sumOfAge(int ages[], int size){
        int sum = 0;

        for (int i=0; i<size ;i++){
            sum = sum + ages[i];
            
        }
        return sum;
}

int findAvg(int ages[], int size){ 
    
    int sumAge = sumOfAge(ages, size);
    int avg = sumAge/size;
    
    return avg;
}

void functionTest(){
    
    int ages[MAX_SIZE];
    
    int size = readAges(ages);
    
    int avgOfAge = findAvg(ages, size);
    
    cout << "Average of input age: " << avgOfAge << endl;
    
}


int main()
{   
    functionTest();
    return 0;
}


