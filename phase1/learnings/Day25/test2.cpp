//Examples for constructors and destructors
#include <iostream>
#include <iomanip>
#include <string>
//
using std::cout;
using std::endl;
using std::string;
//"************"HospitalStay.h"************
class HospitalStay {
    private:
        string StayID;
        int NumberOfDays;
    public:
        //behaviours
        void print();
        //constructor
        HospitalStay(); //no arg constructor
        HospitalStay(string p_StayID, int p_NumberOfDays); //args constructor
        HospitalStay(const HospitalStay& hs); //copy constructor
 
        //destructor
        ~HospitalStay();
};
//"************"Main.cpp"************
int main() {

    HospitalStay hs3("HS003", 3);
    HospitalStay hs4(hs3);



    
    hs3.print(); // Output: [StayID: HS003, NumberOfDays: 3]
    hs4.print(); // Output: [StayID: HS003, NumberOfDays: 3]

    return 0;
}
//************"HospitalStay.cpp"************
//behaviours
void HospitalStay::print() {
    cout << "[StayID: " << StayID 
         << ", NumberOfDays: " << NumberOfDays 
         << "]" << endl;
}
//constructor
HospitalStay::HospitalStay() {
    StayID = "";
    NumberOfDays = 0;
    cout << "[No Args Constructor]Constructed of StayID=" << StayID << endl;
}

HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays) {
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
    cout << "[Args Constructor]Constructed of StayID=" << StayID << endl;
}

HospitalStay::HospitalStay(const HospitalStay& other) {
    this->StayID = other.StayID;
    cout << "this-> StayID: " << this->StayID << endl;
    cout << "&(this->StayID): " << &(this->StayID) << endl;

    // cout << "other.StayID: " << other.StayID << endl;
    // cout << "&(other.StayID): " << &(other.StayID) << endl;


    this->NumberOfDays = other.NumberOfDays;
    cout << "[Copy Constructor]Constructed of StayID=" << StayID << endl;
}

HospitalStay::~HospitalStay() {
    cout << "[Destructor]Destroying of StayID=" << StayID << endl;
}