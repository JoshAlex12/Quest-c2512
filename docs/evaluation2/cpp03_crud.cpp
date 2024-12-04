#include <iostream>
// #include <iomanip>

using namespace std;

// *****Const.h*****
// Constants
const int MAX_PATIENTS = 100;
// *****Patient.h*****
class Patient
{
    friend class PatientManager;

private:
    string PatientID;
    int Age;
    // string PatientID;
    // int Age;
};

// *****PatientManager.h*****
class PatientManager
{
private:
    // attributes
    Patient patients[MAX_PATIENTS];
    int numPatients;

public:
    // support
    int findIndexById(string PatientID);
    // behaviours
    void create();
    void displayAll();
    void editById();
    void deleteById();
    //
    PatientManager();
};
// *****Menu.h*****
void printMenu();

// *****Main.cpp*****

int main()
{
    PatientManager manager;

    int choice; // User's menu choice

    do
    {
        printMenu(); // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu-driven functionality
        switch (choice)
        {
        case 1:
            manager.create();
            break;
        case 2:
            manager.displayAll();
            break;
        case 3:
            manager.editById();
            break;
        case 4:
            manager.deleteById();
            break;
        case 5:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

// *****PatientManager.cpp*****
/**
 * @brief Creates a new patient and stores details in arrays.
 */
void PatientManager::create()
{
    if (numPatients >= MAX_PATIENTS)
    {
        cout << "Error: Maximum patient limit reached.\n";
        return;
    }

    string PatientID;
    int Age;

    cout << "Enter Patient ID: ";
    cin >> PatientID;

    // Ensure patient ID is unique
    if (findIndexById(PatientID) != -1)
    {
        cout << "Error: Patient ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Age: ";
    cin >> Age;

    // Store the patient details
    patients[numPatients].PatientID = PatientID;
    patients[numPatients].Age = Age;
    numPatients++;

    cout << "Patient created successfully.\n";
}

/**
 * @brief Displays all existing patients in a tabular format.
 */
void PatientManager::displayAll()
{
    if (numPatients == 0)
    {
        cout << "No patients available to display.\n";
        return;
    }

    cout << "---------------------------------\n";
    cout << "|Patient ID\t|\tAge\t|\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < numPatients; i++)
    {
        cout << "|" << "\t" << patients[i].PatientID << "\t|"
             << "\t" << patients[i].Age << "\t|\n";
    }
    cout << "---------------------------------\n";
}

/**
 * @brief Finds the index of a patient by ID.
 * @param id Patient ID to search for.
 * @return Index of the patient if found, -1 otherwise.
 */
int PatientManager::findIndexById(string PatientID)
{
    for (int i = 0; i < numPatients; i++)
    {
        if (patients[i].PatientID == PatientID)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Edits an existing patient by ID.
 */
void PatientManager::editById()
{
    string PatientID;
    cout << "Enter Patient ID to edit: ";
    cin >> PatientID;

    int index = findIndexById(PatientID);
    if (index == -1)
    {
        cout << "Error: Patient ID not found.\n";
        return;
    }

    cout << "Current Details - Age: " << patients[index].Age << "\n";

    cout << "Enter New  Age: ";
    cin >> patients[index].Age;

    cout << "Patient updated successfully.\n";
}

/**
 * @brief Deletes an existing patient by ID.
 */
void PatientManager::deleteById()
{
    string PatientID;
    cout << "Enter Patient ID to delete: ";
    cin >> PatientID;

    int index = findIndexById(PatientID);
    if (index == -1)
    {
        cout << "Error: Patient ID not found.\n";
        return;
    }

    // Shift data to fill the gap
    for (int i = index; i < numPatients - 1; i++)
    {
        patients[i] = patients[i + 1];
    }
    numPatients--;

    cout << "Patient deleted successfully.\n";
}

PatientManager::PatientManager()
{
    numPatients = 0;
}
// *****Menu.cpp*****
void printMenu()
{
    cout << "\n=== Patient Management System ===\n";
    cout << "1. Create Patient\n";
    cout << "2. Display All Patients\n";
    cout << "3. Edit Patient\n";
    cout << "4. Delete Patient\n";
    cout << "5. Exit\n";
}