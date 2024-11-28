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
    bool Equals(const Patient &other);
    bool NotEquals(const Patient &other);
    bool GreaterThan(const Patient &other);
    bool GreaterThanEquals(const Patient &other);
    bool LessThan(const Patient &other);
    bool LessThanEquals(const Patient &other);
    Patient(string p_PatientID, int p_Age);
};

int main()
{
    Patient p1("P001", 45);
    Patient p2("P002", 50);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << p1.Equals(p2) << std::endl;                 // Output: false
    std::cout << "GreaterThan: " << p1.GreaterThan(p2) << std::endl;       // Output: false
    std::cout << "LessThanEquals: " << p1.LessThanEquals(p2) << std::endl; // Output: true

    return 0;
}

// function definations
bool Patient::Equals(const Patient &other)
{
    return (Age == other.Age);
}

bool Patient::NotEquals(const Patient &other)
{
    return (Age != other.Age);
}

bool Patient::GreaterThan(const Patient &other)
{
    return (Age > other.Age);
}

bool Patient::GreaterThanEquals(const Patient &other)
{
    return (Age >= other.Age);
}

bool Patient::LessThan(const Patient &other)
{
    return (Age < other.Age);
}

bool Patient::LessThanEquals(const Patient &other)
{
    return (Age <= other.Age);
}

Patient::Patient(string p_PatientID, int p_Age)
{
    PatientID = p_PatientID;
    Age = p_Age;
}
