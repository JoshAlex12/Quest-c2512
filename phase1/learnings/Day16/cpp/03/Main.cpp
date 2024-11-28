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
    std::cout << "Equals: " << Equals(p1, p2) << std::endl;                 // Output: false
    std::cout << "GreaterThan: " << GreaterThan(p1, p2) << std::endl;       // Output: false
    std::cout << "LessThanEquals: " << LessThanEquals(p1, p2) << std::endl; // Output: true

    std::cout << "Equals: " << Equals(hs1, hs2) << std::endl;                 // Output: false
    std::cout << "GreaterThan: " << GreaterThan(hs1, hs2) << std::endl;       // Output: false
    std::cout << "LessThanEquals: " << LessThanEquals(hs1, hs2) << std::endl; // Output: true

    return 0;
}
