#include <iostream>
#include <iomanip>
#include <string>

using std::string;

class Patient
{
private:
    string PatientID;
    int Age;

public:
    // function prototyping or signature or declaration
    friend class PatientComparison;

    // constructor
    Patient(string p_PatientID, int p_Age);
};

class PatientComparison
{
public:
    static bool Equals(const Patient &first, const Patient &second);
    static bool NotEquals(const Patient &first, const Patient &secondr);
    static bool GreaterThan(const Patient &first, const Patient &secondr);
    static bool GreaterThanEquals(const Patient &first, const Patient &secondr);
    static bool LessThan(const Patient &first, const Patient &secondr);
    static bool LessThanEquals(const Patient &first, const Patient &secondr);
};

int main()
{
    Patient p1("P001", 45);
    Patient p2("P002", 50);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << PatientComparison::Equals(p1, p2) << std::endl;                 // Output: false
    std::cout << "GreaterThan: " << PatientComparison::GreaterThan(p1, p2) << std::endl;       // Output: false
    std::cout << "LessThanEquals: " << PatientComparison::LessThanEquals(p1, p2) << std::endl; // Output: true

    return 0;
}

// function definations
bool PatientComparison::Equals(const Patient &first, const Patient &second)
{
    return (first.Age == second.Age);
}

bool PatientComparison::NotEquals(const Patient &first, const Patient &second)
{
    return (first.Age != second.Age);
}

bool PatientComparison::GreaterThan(const Patient &first, const Patient &second)
{
    return (first.Age > second.Age);
}

bool PatientComparison::GreaterThanEquals(const Patient &first, const Patient &second)
{
    return (first.Age >= second.Age);
}

bool PatientComparison::LessThan(const Patient &first, const Patient &second)
{
    return (first.Age < second.Age);
}

bool PatientComparison::LessThanEquals(const Patient &first, const Patient &second)
{
    return (first.Age <= second.Age);
}

Patient::Patient(string p_PatientID, int p_Age)
{
    PatientID = p_PatientID;
    Age = p_Age;
}
