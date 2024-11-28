#include <iostream>
#include <iomanip>

#include "Patient.h"
#include "HospitalStay.h"

int main()
{
    Patient p1("P001", 45);
    Patient p2("P002", 50);

    HospitalStay hs1("HS001", 5);
    HospitalStay hs2("HS002", 7);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << PatientComparison::Equals(p1, p2) << std::endl;                 // Output: false
    std::cout << "GreaterThan: " << PatientComparison::GreaterThan(p1, p2) << std::endl;       // Output: false
    std::cout << "LessThanEquals: " << PatientComparison::LessThanEquals(p1, p2) << std::endl; // Output: true

    std::cout << "Equals: " << HospitalStayComparison::Equals(hs1, hs2) << std::endl;                 // Output: false
    std::cout << "GreaterThan: " << HospitalStayComparison::GreaterThan(hs1, hs2) << std::endl;       // Output: false
    std::cout << "LessThanEquals: " << HospitalStayComparison::LessThanEquals(hs1, hs2) << std::endl; // Output: true

    return 0;
}
