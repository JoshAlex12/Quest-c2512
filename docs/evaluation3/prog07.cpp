// Task
//     2.1
//         change the crud ops with HospitalStay from array of HospitalStay called `stays`
//         to vector<HospitalStay> stays.
//     2.2 vector -> deque


#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

// Data Storage
deque<string> patientIDs;
deque<int> ages;

// Function Prototypes
void printMenu();
void createPatient();
void displayAllPatients();
int findIndexById(const string& patientID);
void editPatientById();
void deletePatientById();
void findMinAge();
void findMaxAge();
void findSecondMinAge();
void findSecondMaxAge();

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
			if (ages.empty())
			{
				cout << "No patients available.\n";
			}
			else {
				findMinAge();
			}
			break;
		case 6:
			if (ages.empty())
			{
				cout << "No patients available.\n";
			}
			else {
				findMaxAge();
			}
			break;
		case 7:
			if (ages.size() < 2)
			{
				cout << "Not enough patients for this operation.\n";
			}
			else {
				findSecondMinAge();
			}

			break;
		case 8:
			if (ages.size() < 2)
			{
				cout << "Not enough patients for this operation.\n";
			}
			else {
				findSecondMaxAge();
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
		cout << "| " << patientIDs[i] << " \t| " << ages[i] << " \t|\n";
	}
	cout << "---------------------------------\n";
}

int findIndexById(const string& patientID)
{
	auto it = find(patientIDs.begin(), patientIDs.end(), patientID);
	if (it != patientIDs.end())
	{
		return distance(patientIDs.begin(), it);
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

void findMinAge()
{
	auto minIt = min_element(ages.begin(), ages.end());
	int index = distance(ages.begin(), minIt);
	cout << "Patient with Min Age: " << patientIDs[index] << " with Age " << *minIt << "\n";
}

void findMaxAge()
{


	auto maxIt = max_element(ages.begin(), ages.end());
	int index = distance(ages.begin(), maxIt);
	cout << "Patient with Max Age: " << patientIDs[index] << " with Age " << *maxIt << "\n";
}

void findSecondMinAge()
{


	deque<int> sortedAges = ages;
	sort(sortedAges.begin(), sortedAges.end());
	int secondMinAge = sortedAges[1];

	auto it = find(ages.begin(), ages.end(), secondMinAge);
	int index = distance(ages.begin(), it);
	cout << "Patient with 2nd Min Age: " << patientIDs[index] << " with Age " << secondMinAge << "\n";
}

void findSecondMaxAge()
{


	deque<int> sortedAges = ages;
	sort(sortedAges.rbegin(), sortedAges.rend());
	int secondMaxAge = sortedAges[1];

	auto it = find(ages.begin(), ages.end(), secondMaxAge);
	int index = distance(ages.begin(), it);
	cout << "Patient with 2nd Max Age: " << patientIDs[index] << " with Age " << secondMaxAge << "\n";
}
