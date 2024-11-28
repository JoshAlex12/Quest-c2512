#pragma once

#include <string>

using std::string;

class HospitalStayComparison;

class HospitalStay
{
private:
    string StayID;
    int NumberOfDays;

public:
    friend HospitalStayComparison;

    // constructor
    HospitalStay(string p_StayID, int p_NumberOfDays);
};

class HospitalStayComparison
{
public:
    // behaviours
    static bool Equals(const HospitalStay &first, const HospitalStay &second);
    static bool NotEquals(const HospitalStay &first, const HospitalStay &second);
    static bool GreaterThan(const HospitalStay &first, const HospitalStay &second);
    static bool GreaterThanEquals(const HospitalStay &first, const HospitalStay &second);
    static bool LessThan(const HospitalStay &first, const HospitalStay &second);
    static bool LessThanEquals(const HospitalStay &first, const HospitalStay &second);
};
