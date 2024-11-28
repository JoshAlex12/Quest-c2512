#include <string>

#include "Patient.h"

using std::string;

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

// getters-setters
string Patient::GetPatientID()
{
	return PatientID;
}
int Patient::GetAge()
{
	return Age;
}