/*
// Coding Question: 1.1
    Employee {id, age, name} //id, age, name are value objects
    Employee e1(101,22,"Athira"),e2(102,23,"Bhagya");
    cout << e1 << endl; //101 22 Athira
    cout << e2 << endl; //102 23 Bhagya
    e1.swap(e2);
    cout << e1 << endl; //102 23 Bhagya
    cout << e2 << endl; //101 22 Athira
    //1.2 "id, age, name" as dynamic memory using new and delete
    //1.3 Programmer { string* tasks; int taskCount; } : Employee | tasks is the multiple tasks - array of task
        swap function overloadable
        here, create the dynamic programmer object assigned to employee pointer.
        field 'tasks' is dynamic memoery.
        operator << overloadable, swap is overridden.
    //1.4 replace dynamic fields as smart pointers
        prove that Employee virtual destructor is not needed.
        create the dynamic programmer object assigned to employee smart pointer
    //1.5 construct array of N programmers. read programmers from keyboard.
        cin >> var; // overload operator>> in employee and programmer
*/

#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    int id;
    int age;
    char *name;

public:
    Employee(int id, int age, const char *name) : id(id), age(age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    int getId()
    {
        return this->id;
    }

    int getAge()
    {
        return this->age;
    }

    char *getName()
    {
        return this->name;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setName(char *name)
    {
        delete[] name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void swap(Employee &other)
    {
        int temp = other.getId();
        other.setId(this->id);
        this->id = temp;

        temp = other.getAge();
        other.setAge(this->age);
        this->age = temp;

        char *temp = other.getName();
        other.setName(this->name);
        this->name = temp;
    }
};

ostream &operator<<(ostream &output, Employee &other)
{
    output << "ID: " << other.getId() << ", " << "Age: " << other.getAge() << ", " << "Name: " << other.getName();
    return output;
}

int main()
{
    Employee e1(101, 22, "Athira"), e2(102, 23, "Bhagya");
    cout << e1 << endl;
    cout << e2 << "\n"
         << endl;

    e1.swap(e2);

    cout << e1 << endl;
    cout << e2 << endl;

    return 0;
}