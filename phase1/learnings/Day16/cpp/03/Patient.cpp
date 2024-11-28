#include <string>

#include "Patient.h"

using std::string;

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
