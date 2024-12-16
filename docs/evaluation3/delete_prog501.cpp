#include <iostream>
#include <cstring>
#include <memory>
#include <vector>
#include <limits> // For numeric_limits

using namespace std;

class Employee
{
private:
    unique_ptr<int> id;
    unique_ptr<int> age;
    unique_ptr<char[]> name;

public:
    Employee(int id, int age, const char *name)
        : id(make_unique<int>(id)), age(make_unique<int>(age)), name(make_unique<char[]>(strlen(name) + 1))
    {
        strcpy(this->name.get(), name);
    }

    virtual ~Employee() = default;

    virtual void swp(Employee &other)
    {
        swap(id, other.id);
        swap(age, other.age);
        swap(name, other.name);
    }

    friend ostream &operator<<(ostream &out, const Employee &employee)
    {
        out << "ID: " << *employee.id << ", Name: " << employee.name.get() << ", Age: " << *employee.age;
        return out;
    }
};

class Programmer : public Employee
{
private:
    unique_ptr<string[]> tasks;
    unique_ptr<int> taskCount;

public:
    Programmer(int v_id, int v_age, const char *v_name, vector<string> v_tasks)
        : Employee(v_id, v_age, v_name), taskCount(make_unique<int>(v_tasks.size())), tasks(make_unique<string[]>(v_tasks.size()))
    {
        for (size_t i = 0; i < v_tasks.size(); ++i)
        {
            tasks[i] = v_tasks[i];
        }
    }

    ~Programmer() override = default;

    void swp(Employee &other) override
    {
        Employee::swp(other);

        // Safely attempt downcast
        if (Programmer *prog = dynamic_cast<Programmer *>(&other))
        {
            swap(tasks, prog->tasks);
            swap(taskCount, prog->taskCount);
        }
    }

    friend ostream &operator<<(ostream &out, const Programmer &programmer)
    {
        out << static_cast<const Employee &>(programmer);
        out << ", Task Count: " << *programmer.taskCount << ", Tasks: [";
        for (int i = 0; i < *programmer.taskCount; ++i)
        {
            out << programmer.tasks[i];
            if (i < *programmer.taskCount - 1)
                out << ", ";
        }
        out << "]";
        return out;
    }
};

void readProgrammerDetails(int &id, int &age, string &name, vector<string> &tasks)
{
    cout << "ID: ";
    cin >> id;

    while (cin.fail() || id < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid positive integer for ID: ";
        cin >> id;
    }

    cout << "Age: ";
    cin >> age;

    while (cin.fail() || age <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid positive integer for Age: ";
        cin >> age;
    }

    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    int taskCount;
    cout << "Number of tasks: ";
    cin >> taskCount;

    while (cin.fail() || taskCount < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a non-negative integer for the number of tasks: ";
        cin >> taskCount;
    }

    cin.ignore();
    tasks.resize(taskCount);
    for (int i = 0; i < taskCount; ++i)
    {
        cout << "Task " << i + 1 << ": ";
        getline(cin, tasks[i]);
    }
}

int main()
{
    int N;
    cout << "Enter the number of programmers: ";
    cin >> N;

    while (cin.fail() || N <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer for the number of programmers: ";
        cin >> N;
    }

    vector<unique_ptr<Programmer>> programmers;
    programmers.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int id, age;
        string name;
        vector<string> tasks;

        cout << "\nEnter details for programmer " << i + 1 << ":\n";
        readProgrammerDetails(id, age, name, tasks);

        programmers.emplace_back(make_unique<Programmer>(id, age, name.c_str(), tasks));
    }

    cout << "\nDetails of programmers:\n";
    for (int i = 0; i < N; ++i)
    {
        cout << "Programmer " << i + 1 << ": " << *programmers[i] << endl;
    }

    return 0;
}
