// Task
//     2.1
//         change the crud ops with HospitalStay from array of HospitalStay called `stays`
//         to vector<HospitalStay> stays.
//     2.2 vector -> deque

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> patientIDs;
vector<int> ages;

void printMenu();
void createPatient();
void displayAllPatients();
int findIndexById(const string &patientID);
void editPatientById();
void deletePatientById();

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
			cout << "Exiting the system. Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 9.\n";
		}
	} while (choice != 5);

	return 0;
}

void printMenu()
{
	cout << "\n=== Patient Management System ===\n";
	cout << "1. Create Patient\n";
	cout << "2. Display All Patients\n";
	cout << "3. Edit Patient\n";
	cout << "4. Delete Patient\n";
	cout << "5. Exit\n";
}

void createPatient()
{
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

	patientIDs.push_back(patientID);
	ages.push_back(age);

	cout << "Patient created successfully.\n";
}

void displayAllPatients()
{
	if (patientIDs.empty())
	{
		cout << "No patients available to display.\n";
		return;
	}

	cout << "---------------------------------\n";
	cout << "| Patient ID \t| Age \t|\n";
	cout << "---------------------------------\n";
	for (size_t i = 0; i < patientIDs.size(); ++i)
	{
		cout << "| " << patientIDs[i] << " \t\t| " << ages[i] << " \t|\n";
	}
	cout << "---------------------------------\n";
}

int findIndexById(const string &patientID)
{
	auto iter = find(patientIDs.begin(), patientIDs.end(), patientID);
	if (iter != patientIDs.end())
	{
		return distance(patientIDs.begin(), iter);
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

	patientIDs.erase(patientIDs.begin() + index);
	ages.erase(ages.begin() + index);

	cout << "Patient deleted successfully.\n";
}