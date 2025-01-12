#include <iostream>
#include <cmath>
#include <climits>
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

int findSumOfAge(int ages[], int size){
        int sum = 0;

        for (int i=0; i<size ;i++){
            sum = sum + ages[i];
            
        }
        return sum;
}


int findAvg(int ages[], int size){ 
    
    int sumAge = findSumOfAge(ages, size);
    int avg = (int)sumAge/size;
    
    return avg;
}

bool isPrime(int age){
    if (age < 2)
    {
        return false;
    }

    int squareRoot = sqrt(age);

    for (int i = 2; i <= squareRoot; i++)
    {
        if ((age % i) == 0)
        {
            return false;
        }
    }
    
    return true;
}


int findSumOfPrime(int ages[], int size){
    int sum = 0;

    for (int i = 0; i < size; i++){
        if (isPrime(ages[i])){
            sum = sum + ages[i];
        }
    }
    return sum;
}

bool isTeenage(int age){

    if ((age >= 13) && (age <= 19)){
        return true;
    }
    else{
        return false;
    }
}

int findSumOfTeenage(int ages[] , int size){
    int sumOfTeenage = 0;
    for(int i=0 ; i < size ; i++)
    {
        if(isTeenage(ages[i]))
        {
            sumOfTeenage = sumOfTeenage+ages[i];
        }
    }
    return sumOfTeenage;
}

int findMinAge(int ages[], int size){
    int min = INT_MAX;

    for (int i = 0; i < size; i++){
        if (ages[i] < min){
            min = ages[i];
        }
    }
    return min;  
}

bool isOddAge(int age){
        
    if ((age % 2) == 0){         
        return false;
    }
    return true;
}

int sumOfOddAge(int ages[], int size){
    int sum = 0;

    for(int i = 0; i < size; i++){
        if (isOddAge(ages[i])){
            sum = sum + ages[i];
        }
    }
    return sum;
}



int findSecondMaxAdultAge(int ages[], int size){
    int firstMax = 0, secondMax = 0;

    for (int i = 0; i < size; i++)
    {
        if (ages[i] >= 18 && ages[i] > firstMax)
        {
            firstMax = ages[i];
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        if ((ages[i] >= 18) && (ages[i] > secondMax) && (ages[i] < firstMax))
        {
            secondMax = ages[i];
        }
    }	
    
    return secondMax;
}


void functionTest(){
    
    int ages[MAX_SIZE];
    
    int size = readAges(ages);
    
    int avgOfAge = findAvg(ages, size);
    cout << "Average of input age: " << avgOfAge << endl;
    
    int primeAgeSum = findSumOfPrime(ages, size);
    cout << "Sum of prime age: " << primeAgeSum << endl;
    
    int teenSum = findSumOfTeenage(ages, size);
    cout << "Sum of teenagers age: " << teenSum << endl;
    
    int minimumAge = findMinAge(ages, size);
    cout << "Minimum age: " << minimumAge << endl;
    
    int oddAgeSum = sumOfOddAge(ages, size);
    cout << "Sum of odd age: " << oddAgeSum << endl;
    
    int secondMaxAdultAge = findSecondMaxAdultAge(ages, size);
    cout << "Second maximum adult age: " << secondMaxAdultAge << endl;
    
    if(isPrime(minimumAge)){
        cout << "Minimum age is prime" << endl;
    }
    else{
        cout << "Minimum age is not prime" << endl;
        
    }
}


int main()
{   
    functionTest();
    return 0;
}