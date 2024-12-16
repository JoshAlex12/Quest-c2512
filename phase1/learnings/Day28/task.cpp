// Obj:
/*
read n temperatures -> float
in vector
sort using set (remove duplicate)
set to stack
read from stack to get reverse data
*/

#include <iostream>
#include <set>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int numberOfTemp;
    cout << "Enter number of temperature: ";
    cin >> numberOfTemp;
    vector<float> temperature;
    cout << "Enter temperatures: " << endl;

    for (int i = 0; i < numberOfTemp; i++)
    {
        float sal;
        cout << "Temperature at " << i << ": ";
        cin >> sal;
        temperature.push_back(sal);
    }

    cout << endl;
    cout << "Temperature Vector: ";
    for (auto ITER = temperature.begin(); ITER != temperature.end(); ITER++)
    {
        cout << *ITER << " ";
    }
    cout << endl;

    set<float> temperatureSet;
    for (int i = 0; i < numberOfTemp; i++)
    {
        temperatureSet.insert(temperature.at(i));
    }

    cout << endl;
    cout << "Temperature Set:";
    for (auto ITER = temperatureSet.begin(); ITER != temperatureSet.end(); ITER++)
    {
        cout << *ITER << " ";
    }
    cout << endl;

    stack<float> temperatureStack;
    for (auto ITER = temperatureSet.begin(); ITER != temperatureSet.end(); ITER++)
    {
        temperatureStack.push(*ITER);
    }

    cout << endl;
    cout << "Temperature Stack(in reverse order): ";
    while (!temperatureStack.empty())
    {
        cout << temperatureStack.top() << " ";
        temperatureStack.pop();
    }
    cout << endl;
    return 0;
}