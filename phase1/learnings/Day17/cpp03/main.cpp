#include <iostream>
#include <string>

using std::string;

class Patient
{
private:
    string PatientID;
    int Age;

public:
    // function prototyping or signature or declaration
    friend bool Equals(const Patient &first, const Patient &second);
    friend bool NotEquals(const Patient &first, const Patient &secondr);
    friend bool GreaterThan(const Patient &first, const Patient &secondr);
    friend bool GreaterThanEquals(const Patient &first, const Patient &secondr);
    friend bool LessThan(const Patient &first, const Patient &secondr);
    friend bool LessThanEquals(const Patient &first, const Patient &secondr);
    Patient(string p_PatientID, int p_Age);
};

bool Equals(const Patient &first, const Patient &second);
bool NotEquals(const Patient &first, const Patient &secondr);
bool GreaterThan(const Patient &first, const Patient &secondr);
bool GreaterThanEquals(const Patient &first, const Patient &secondr);
bool LessThan(const Patient &first, const Patient &secondr);
bool LessThanEquals(const Patient &first, const Patient &secondr);

class HospitalStay
{
private:
    string StayID;
    int NumberOfDays;

public:
    friend bool Equals(const HospitalStay &first, const HospitalStay &second);
    friend bool NotEquals(const HospitalStay &first, const HospitalStay &second);
    friend bool GreaterThan(const HospitalStay &first, const HospitalStay &second);
    friend bool GreaterThanEquals(const HospitalStay &first, const HospitalStay &second);
    friend bool LessThan(const HospitalStay &first, const HospitalStay &second);
    friend bool LessThanEquals(const HospitalStay &first, const HospitalStay &second);
    // constructor
    HospitalStay(string p_StayID, int p_NumberOfDays);
};

// behaviours
bool Equals(const HospitalStay &first, const HospitalStay &second);
bool NotEquals(const HospitalStay &first, const HospitalStay &second);
bool GreaterThan(const HospitalStay &first, const HospitalStay &second);
bool GreaterThanEquals(const HospitalStay &first, const HospitalStay &second);
bool LessThan(const HospitalStay &first, const HospitalStay &second);
bool LessThanEquals(const HospitalStay &first, const HospitalStay &second);

int main()
{
    Patient p1("P001", 45);
    Patient p2("P002", 50);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << Equals(p1, p2) << std::endl;                 // Output: false
    std::cout << "GreaterThan: " << GreaterThan(p1, p2) << std::endl;       // Output: false
    std::cout << "LessThanEquals: " << LessThanEquals(p1, p2) << std::endl; // Output: true

    HospitalStay hs1("HS001", 5);
    HospitalStay hs2("HS002", 7);

    std::cout << "Equals: " << Equals(hs1, hs2) << std::endl;                 // Output: false
    std::cout << "GreaterThan: " << GreaterThan(hs1, hs2) << std::endl;       // Output: false
    std::cout << "LessThanEquals: " << LessThanEquals(hs1, hs2) << std::endl; // Output: true

    return 0;
}

// function definations
bool Equals(const Patient &first, const Patient &second)
{
    return (first.Age == second.Age);
}

bool NotEquals(const Patient &first, const Patient &second)
{
    return (first.Age != second.Age);
}

bool GreaterThan(const Patient &first, const Patient &second)
{
    return (first.Age > second.Age);
}

bool GreaterThanEquals(const Patient &first, const Patient &second)
{
    return (first.Age >= second.Age);
}

bool LessThan(const Patient &first, const Patient &second)
{
    return (first.Age < second.Age);
}

bool LessThanEquals(const Patient &first, const Patient &second)
{
    return (first.Age <= second.Age);
}

Patient::Patient(string p_PatientID, int p_Age)
{
    PatientID = p_PatientID;
    Age = p_Age;
}

// ............................................................................................
// friends
bool Equals(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays == second.NumberOfDays);
}

bool NotEquals(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays != second.NumberOfDays);
}

bool GreaterThan(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays > second.NumberOfDays);
}

bool GreaterThanEquals(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays >= second.NumberOfDays);
}

bool LessThan(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays < second.NumberOfDays);
}

bool LessThanEquals(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays <= second.NumberOfDays);
}

// constructor
HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays)
{
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
}
