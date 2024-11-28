#include <iostream>
#include <string>
#include <climits>

using std::string;

class Patient
{
private:
    string PatientID;
    int Age;

public:
    // function prototyping or signature or declaration
    bool Equals(const Patient &other);
    bool NotEquals(const Patient &other);
    bool GreaterThan(const Patient &other);
    bool GreaterThanEquals(const Patient &other);
    bool LessThan(const Patient &other);
    bool LessThanEquals(const Patient &other);

    // constructor
    Patient(string p_PatientID, int p_Age);

    // getters-setters
    string GetPatientID();
    int GetAge();
};

// ..............................................................................................................
int findMinAge(Patient arr[], int n);
int findMaxAge(Patient arr[], int n);
int findSecondMinAge(Patient arr[], int n);
int findSecondMaxAge(Patient arr[], int n);
// ..............................................................................................................

int main()
{
    Patient Patients[] = {
        Patient("P001", 45),
        Patient("P002", 50),
        Patient("P003", 15),
        Patient("P004", 20),
        Patient("P005", 30)};

    std::cout << std::boolalpha;

    int n_Patients = sizeof(Patients) / sizeof(Patients[0]);

    std::cout << " Patient with Min Age: " << Patients[findMinAge(Patients, n_Patients)].GetPatientID() << " with Age " << Patients[findMinAge(Patients, n_Patients)].GetAge() << std::endl;
    std::cout << " Patient with Max Age: " << Patients[findMaxAge(Patients, n_Patients)].GetPatientID() << " with Age " << Patients[findMaxAge(Patients, n_Patients)].GetAge() << std::endl;
    std::cout << " Patient with 2nd Min Age: " << Patients[findSecondMinAge(Patients, n_Patients)].GetPatientID() << " with Age " << Patients[findSecondMinAge(Patients, n_Patients)].GetAge() << std::endl;
    std::cout << " Patient with 2nd Max Age: " << Patients[findSecondMaxAge(Patients, n_Patients)].GetPatientID() << " with Age " << Patients[findSecondMaxAge(Patients, n_Patients)].GetAge() << std::endl;

    return 0;
}

// ..............................................................................................................
// Function to find the index of the Patient with the minimum years of Stay
int findMinAge(Patient arr[], int n)
{
    int minIndex = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i].LessThan(arr[minIndex]))
        {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to find the index of the Patient with the maximum years of Stay
int findMaxAge(Patient arr[], int n)
{
    int maxIndex = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i].GreaterThan(arr[maxIndex]))
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to find the index of the Patient with the second minimum years of Stay
int findSecondMinAge(Patient arr[], int n)
{
    int minIndex = findMinAge(arr, n);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;

    for (int i = 0; i < n; ++i)
    {
        if (i != minIndex)
        {
            if (arr[i].LessThan(arr[secondMinIndex]))
            {
                secondMinIndex = i;
            }
        }
    }
    return secondMinIndex;
}

// Function to find the index of the Patient with the second maximum years of Stay
int findSecondMaxAge(Patient arr[], int n)
{
    int maxIndex = findMaxAge(arr, n);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

    for (int i = 0; i < n; ++i)
    {
        if (i != maxIndex)
        {
            if (arr[i].GreaterThan(arr[secondMaxIndex]))
            {
                secondMaxIndex = i;
            }
        }
    }
    return secondMaxIndex;
}
// ..............................................................................................................

// function definations
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

// getters-setters
string Patient::GetPatientID()
{
    return PatientID;
}
int Patient::GetAge()
{
    return Age;
}
