#include <iostream>
using namespace std;

class Nums{
    private:
        int num;
    public:

        friend ostream& operator<<(ostream& output, const Nums& obj);
    
        Nums operator+(const Nums& other){
            Nums obj(0);

            obj.num = this->num + other.num;
            cout << "this: " << this << endl;
            cout << "*this: " << *this << endl;

            return obj;
        }

        Nums():num(0) {};


        Nums(int num) : num(num){
            cout << "Nums constructor" << endl;
        };
        ~Nums(){
            cout << "Nums destructor" << endl;
        };
};

ostream& operator<<(ostream& output, const Nums& obj){
    output << obj.num;
    return output;
}

int main(){
    Nums obj1; //(1);
    Nums obj2(2);

    cout << "Printing: " << obj1 << endl;
    cout << "Addition: " << obj1 + obj2 << endl;

    return 0;
}