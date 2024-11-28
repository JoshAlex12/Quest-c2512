#pragma once

#include <string>

using std::string;

class PatientComparison;

class Patient
{
private:
	string PatientID;
	int Age;

public:
	// function prototyping or signature or declaration
	friend PatientComparison;

	// constructor
	Patient(string p_PatientID, int p_Age);

	// getters-setters
	string GetPatientID();
	int GetAge();

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
