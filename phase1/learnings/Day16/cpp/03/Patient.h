#pragma once

#include <string>

using std::string;

class Patient
{
private:
	string PatientID;
	int Age;

public:
	// function prototyping or signature or declaration
	friend bool Equals(const Patient &first, const Patient &second);
	friend bool NotEquals(const Patient &first, const Patient &secondr);
	friend bool GreaterThan(const Patient &first, const Patient &secondr);
	friend bool GreaterThanEquals(const Patient &first, const Patient &secondr);
	friend bool LessThan(const Patient &first, const Patient &secondr);
	friend bool LessThanEquals(const Patient &first, const Patient &secondr);
	Patient(string p_PatientID, int p_Age);
};

bool Equals(const Patient &first, const Patient &second);
bool NotEquals(const Patient &first, const Patient &secondr);
bool GreaterThan(const Patient &first, const Patient &secondr);
bool GreaterThanEquals(const Patient &first, const Patient &secondr);
bool LessThan(const Patient &first, const Patient &secondr);
bool LessThanEquals(const Patient &first, const Patient &secondr);