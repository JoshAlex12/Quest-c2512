#include <string>

#include "HospitalStay.h"

using std::string;

// friends
bool HospitalStayComparison::Equals(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays == second.NumberOfDays);
}

bool HospitalStayComparison::NotEquals(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays != second.NumberOfDays);
}

bool HospitalStayComparison::GreaterThan(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays > second.NumberOfDays);
}

bool HospitalStayComparison::GreaterThanEquals(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays >= second.NumberOfDays);
}

bool HospitalStayComparison::LessThan(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays < second.NumberOfDays);
}

bool HospitalStayComparison::LessThanEquals(const HospitalStay &first, const HospitalStay &second)
{
    return (first.NumberOfDays <= second.NumberOfDays);
}

// constructor
HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays)
{
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
}

// getters-setters
string HospitalStay::GetStayID()
{
    return StayID;
}
int HospitalStay::GetNumberOfDays()
{
    return NumberOfDays;
}