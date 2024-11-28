#include <iostream>
#include "Patient.h"

int main()
{
    Patient p1("P001", 45);
    Patient p2("P002", 50);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << Equals(p1, p2) << std::endl;                 // Output: false
    std::cout << "GreaterThan: " << GreaterThan(p1, p2) << std::endl;       // Output: false
    std::cout << "LessThanEquals: " << LessThanEquals(p1, p2) << std::endl; // Output: true

    return 0;
}
