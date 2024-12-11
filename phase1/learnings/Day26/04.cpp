#include<iostream>
using namespace std;



// double findSum(double arr[], int size) {
//     double result = 0.0f;
//     for(auto e : arr) {
//         result = result + e;
//     }
//     return result;
// }


template <class T, class U>
T findSum(T arr[], U size){
    T result = {};
    for (U i; i < size; i++){
        result = result + arr[i];
    }
    return result;
}

int main(){
    float arr[] = {1.0f, 2.0f, 3.0f, 4.0f};
    cout << "Sum of array values: " << findSum<float, int>(arr, 4) << endl;
}