#include <string>

#include "Patient.h"

using std::string;

//function definations
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
