// #include <iostream>
// using namespace std;

// class Student{
//     private:
//         char* name;

//     public:
//         Student(char* name) : name(name){};
//         ~Student(){};

//         void prnt(){
//             cout << name << endl;
//         }

// };

// int main(){
//     char arr[] = "hello";
//     Student obj(arr);
//     obj.prnt();
// }

#include <iostream>
#include <cstring>
using namespace std;

class Student{
    private:
        char* var;

    public:
        Student(const char* other){
            var = new char[strlen(other)+1];
            strcpy(var, other);
            cout << "Newly initialized var: " << var << endl;
        }

        void prnt(){
            cout << "Address of obj var:" << &var << endl;
        }

        ~Student(){

            delete[] var;
        }
};

int main(){
    char arr[] = "Hello";
    Student obj(arr);
    obj.prnt();
    cout << "Address of outer arr[]: " << &arr << endl;

    

}
















