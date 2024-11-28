#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    int StudentID;
    string Name;
    static int numberOfStudents;

    // Constructor declaration
    Student(int p_StudentID, string p_Name);

    // Static member function to return the number of students
    static int f_numberOfStudents();
};

// Initialize the static member variable
int Student::numberOfStudents = 0;

// Constructor definition
Student::Student(int p_StudentID, string p_Name)
{
    StudentID = p_StudentID;
    Name = p_Name;
    numberOfStudents++; // Increment the static member for each student created
}

// Static function definition
int Student::f_numberOfStudents()
{
    return numberOfStudents;
}

int main()
{
    // Creating Student objects
    Student std1(100, "Dhaheen");
    Student std2(200, "Pitchumani");

    // Displaying Student details
    cout << "Student 1 ID: " << std1.StudentID << ", Name: " << std1.Name << endl;
    cout << "Student 2 ID: " << std2.StudentID << ", Name: " << std2.Name << endl;

    cout << Student::numberOfStudents << endl;
    cout << Student::Name << endl;

    // Accessing static member function to get the number of students
    cout << "Number of Students: " << Student::f_numberOfStudents() << endl;

    return 0;
}
