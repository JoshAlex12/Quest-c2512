#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constants
const int MAX_PATIENTS = 100;

// Data Storage
string patientIDs[MAX_PATIENTS];
int ages[MAX_PATIENTS];
int numPatients = 0;

// Function Prototypes
void printMenu();
void createPatient();
void displayAllPatients();
int findIndexById(string patientID);
void editPatientById();
void deletePatientById();
int findMinAgeIndex();
int findMaxAgeIndex();
int findSecondMinAgeIndex();
int findSecondMaxAgeIndex();

int main()
{
    int choice;

    do
    {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createPatient();
            break;
        case 2:
            displayAllPatients();
            break;
        case 3:
            editPatientById();
            break;
        case 4:
            deletePatientById();
            break;
        case 5:
            if (numPatients > 0)
            {
                int minIndex = findMinAgeIndex();
                cout << "Patient with Patient ID: " << patientIDs[minIndex] << " has MIN age with age: " << ages[minIndex] << endl;
            }
            else
            {
                cout << "No patients available.\n";
            }
            break;
        case 6:
            if (numPatients > 0)
            {
                int maxIndex = findMaxAgeIndex();
                cout << "Patient with Patient ID: " << patientIDs[maxIndex] << " has MAX age with age: " << ages[maxIndex] << endl;
            }
            else
            {
                cout << "No patients available.\n";
            }
            break;
        case 7:
            if (numPatients > 1)
            {
                int secondMinIndex = findSecondMinAgeIndex();
                cout << "Patient with Patient ID: " << patientIDs[secondMinIndex] << " has 2nd Min age with age: " << ages[secondMinIndex] << endl;
            }
            else
            {
                cout << "Not enough patients for this operation.\n";
            }
            break;
        case 8:
            if (numPatients > 1)
            {
                int secondMaxIndex = findSecondMaxAgeIndex();
                cout << "Patient with Patient ID: " << patientIDs[secondMaxIndex] << " has 2nd MAX age with age: " << ages[secondMaxIndex] << endl;
            }
            else
            {
                cout << "Not enough patients for this operation.\n";
            }
            break;
        case 9:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 9.\n";
        }
    } while (choice != 9);

    return 0;
}

void printMenu()
{
    cout << "\n=== Patient Management System ===\n";
    cout << "1. Create Patient\n";
    cout << "2. Display All Patients\n";
    cout << "3. Edit Patient\n";
    cout << "4. Delete Patient\n";
    cout << "5. Find Min Age\n";
    cout << "6. Find Max Age\n";
    cout << "7. Find Second Min Age\n";
    cout << "8. Find Second Max Age\n";
    cout << "9. Exit\n";
}

void createPatient()
{
    if (numPatients >= MAX_PATIENTS)
    {
        cout << "Error: Maximum patient limit reached.\n";
        return;
    }

    string patientID;
    int age;

    cout << "Enter Patient ID: ";
    cin >> patientID;

    if (findIndexById(patientID) != -1)
    {
        cout << "Error: Patient ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Age: ";
    cin >> age;

    patientIDs[numPatients] = patientID;
    ages[numPatients] = age;
    numPatients++;

    cout << "Patient created successfully.\n";
}

void displayAllPatients()
{
    if (numPatients == 0)
    {
        cout << "No patients available to display.\n";
        return;
    }

    cout << "-------------------------\n";
    cout << "| Patient ID \t| Age \t|\n";
    cout << "-------------------------\n";
    for (int i = 0; i < numPatients; i++)
    {
        cout << "| " << patientIDs[i] << " \t\t| " << ages[i] << " \t|\n";
    }
    cout << "-------------------------\n";
}

int findIndexById(string patientID)
{
    for (int i = 0; i < numPatients; i++)
    {
        if (patientIDs[i] == patientID)
        {
            return i;
        }
    }
    return -1;
}

void editPatientById()
{
    string patientID;
    cout << "Enter Patient ID to edit: ";
    cin >> patientID;

    int index = findIndexById(patientID);
    if (index == -1)
    {
        cout << "Error: Patient ID not found.\n";
        return;
    }

    cout << "Current Age: " << ages[index] << "\n";
    cout << "Enter New Age: ";
    cin >> ages[index];

    cout << "Patient updated successfully.\n";
}

void deletePatientById()
{
    string patientID;
    cout << "Enter Patient ID to delete: ";
    cin >> patientID;

    int index = findIndexById(patientID);
    if (index == -1)
    {
        cout << "Error: Patient ID not found.\n";
        return;
    }

    for (int i = index; i < numPatients - 1; i++)
    {
        patientIDs[i] = patientIDs[i + 1];
        ages[i] = ages[i + 1];
    }
    numPatients--;

    cout << "Patient deleted successfully.\n";
}

int findMinAgeIndex()
{
    int minIndex = 0;
    for (int i = 1; i < numPatients; i++)
    {
        if (ages[i] < ages[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxAgeIndex()
{
    int maxIndex = 0;
    for (int i = 1; i < numPatients; i++)
    {
        if (ages[i] > ages[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findSecondMinAgeIndex()
{
    int minIndex = findMinAgeIndex();
    int secondMinIndex = (minIndex == 0) ? 1 : 0;

    for (int i = 0; i < numPatients; i++)
    {
        if (i != minIndex && ages[i] < ages[secondMinIndex])
        {
            secondMinIndex = i;
        }
    }
    return secondMinIndex;
}

int findSecondMaxAgeIndex()
{
    int maxIndex = findMaxAgeIndex();
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

    for (int i = 0; i < numPatients; i++)
    {
        if (i != maxIndex && ages[i] > ages[secondMaxIndex])
        {
            secondMaxIndex = i;
        }
    }
    return secondMaxIndex;
}
