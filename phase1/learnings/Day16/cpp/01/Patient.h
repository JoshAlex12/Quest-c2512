#pragma once

#include <string>

using std::string;

class Patient
{
	private:
		string PatientID;
		int Age;

	public:
		//function prototyping or signature or declaration
		bool Equals(const Patient &other);
		bool NotEquals(const Patient &other);
		bool GreaterThan(const Patient &other);
		bool GreaterThanEquals(const Patient &other);
		bool LessThan(const Patient &other);
		bool LessThanEquals(const Patient &other);
		Patient(string p_PatientID, int p_Age);
};
