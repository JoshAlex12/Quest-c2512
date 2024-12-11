#include <iostream>
#include <cstring>
using namespace std;


// abstract class
// inherit that class
// exception handling
// polymorphism implement


class University{
    public: 
        virtual int attendance() = 0;
        virtual void hello() = 0;

    University(){cout << "University constructor" << endl;}
    
    virtual ~University(){cout << "University destructor" << endl;}
};

class College : public University{
    private: 
        char* name;

    public:
        int attendance() override {
            cout << "College attendance function called" << endl;
            return 0;
        }
    College(){cout << "College constructor" << endl;}
    
    ~College(){cout << "College destructor" << endl;}

};

int main(){
    University* uni = new College;
    int a = uni->attendance();
    delete uni;
}