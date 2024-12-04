#include <iostream>
#include <iomanip>

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

public:
    bool GreaterThan(const Patient &other);
    bool LessThan(const Patient &other);
    // getters-setters
    string GetPatientID();
    int GetAge();
};

// *****PatientManager.h*****
class PatientManager
{
    friend class PatientAggregator;
    friend int main();

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
//*****PatientAggregator.h*****
class PatientAggregator
{
public:
    int findMin(PatientManager &manager);
    int findMax(PatientManager &manager);
    int findSecondMin(PatientManager &manager);
    int findSecondMax(PatientManager &manager);
};
// *****Menu.h*****
void printMenu();

// *****Main.cpp*****

int main()
{
    PatientManager manager;
    PatientAggregator aggregator;

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
            std::cout << "Patient with Min Age: "
                      << manager.patients[aggregator.findMin(manager)].GetPatientID()
                      << " with Age "
                      << manager.patients[aggregator.findMin(manager)].GetAge()
                      << std::endl;
            break;
        case 6:
            std::cout << "Patient with Max Age: "
                      << manager.patients[aggregator.findMax(manager)].GetPatientID()
                      << " with Age "
                      << manager.patients[aggregator.findMax(manager)].GetAge()
                      << std::endl;
            break;
        case 7:
            std::cout << "Patient with 2nd Min Age: "
                      << manager.patients[aggregator.findSecondMin(manager)].GetPatientID()
                      << " with Age "
                      << manager.patients[aggregator.findSecondMin(manager)].GetAge()
                      << std::endl;
            break;
        case 8:
            std::cout << "Patient with 2nd Max Age: "
                      << manager.patients[aggregator.findSecondMax(manager)].GetPatientID()
                      << " with Age "
                      << manager.patients[aggregator.findSecondMax(manager)].GetAge()
                      << std::endl;
            break;
        case 9:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 9);

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
    cout << "5. Find Min Age\n";
    cout << "6. Find Max Age\n";
    cout << "7. Find Second Min Age\n";
    cout << "8. Find Second Max Age\n";
    cout << "9. Exit\n";
}

//*****Patient.cpp*****
bool Patient::GreaterThan(const Patient &other)
{
    return (Age > other.Age);
}

bool Patient::LessThan(const Patient &other)
{
    return (Age < other.Age);
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
//*****PatientAggregator.cpp*****
// Function to find the index of the Patient with the minimum years of Stay
int PatientAggregator::findMin(PatientManager &manager)
{
    Patient *arr = manager.patients;
    int n = manager.numPatients;
    //
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
int PatientAggregator::findMax(PatientManager &manager)
{
    Patient *arr = manager.patients;
    int &n = manager.numPatients;
    //
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
int PatientAggregator::findSecondMin(PatientManager &manager)
{
    Patient *arr = manager.patients;
    int &n = manager.numPatients;
    //
    int minIndex = findMin(manager);
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
int PatientAggregator::findSecondMax(PatientManager &manager)
{
    Patient *arr = manager.patients;
    int &n = manager.numPatients;
    //
    int maxIndex = findMax(manager);
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