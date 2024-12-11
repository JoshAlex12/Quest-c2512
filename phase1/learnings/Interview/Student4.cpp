// Find a particular word in a string and replace it with another word.

#include <iostream>
using namespace std;

int main(){
    char arr[20];
    char var;
    cout << "Enter string: "; cin >> arr;
    cout << "Enter character to be changed: "; cin >> var;

    int i = 0;

    while (arr[i] != '\0'){
        if (arr[i] == var){
            arr[i] = 'z';
        }
        i++;
    }
    cout << arr;

    for (char vari : arr){
        cout << vari;
    }
}