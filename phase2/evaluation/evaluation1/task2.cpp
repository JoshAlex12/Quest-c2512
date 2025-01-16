#include <iostream>
#include <vector>
#include <thread>

using namespace std;
int numFindSum, numFindMinInFirstHalf, numFindMaxInSecondHalf;

class Patient {
private: 
    string PatientID;
    int Age;

public:
    Patient(string p_PatientID, int p_Age) : PatientID(p_PatientID), Age(p_Age) {}

    int getAge() {
        return Age;
    }
};

void findSum(vector<Patient>& vec) {
    int sum = 0;
    
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i].getAge();
    }
    numFindSum = sum;
}

void findMinInFirstHalf(vector<Patient>& vec) {
    
    int minAge = vec[0].getAge();
    int end = vec.size() / 2;

    for (int i = 1; i < end; i++) {
        if (vec[i].getAge() < minAge) {
            minAge = vec[i].getAge();
        }
    }
    numFindMinInFirstHalf = minAge;
}

void findMaxInSecondHalf(vector<Patient>& vec) {
    
    
    int start = vec.size() / 2;
    int maxAge = vec[start].getAge();

    for (int i = start+1; i < vec.size(); i++) {
        if (vec[i].getAge() > maxAge) {
            maxAge = vec[i].getAge();
        }
    }
    numFindMaxInSecondHalf = maxAge;
}

int main() {
    vector<Patient> vect = {
        Patient("P001", 50),
        Patient("P002", 23),
        Patient("P003", 10),
        Patient("P004", 85),
        Patient("P005", 5)
    };

    thread threadSum(findSum, ref(vect)); 
    thread threadFindMinInFirstHalf(findMinInFirstHalf, ref(vect));
    thread threadFindMaxInSecondHalf(findMaxInSecondHalf, ref(vect));

    threadSum.join();
    threadFindMinInFirstHalf.join();
    threadFindMaxInSecondHalf.join();

    cout << "Sum of ages: " << numFindSum << endl;
    cout << "Min age in first half: " << numFindMinInFirstHalf << endl;
    cout << "Max age in second half: " << numFindMaxInSecondHalf << endl;    
}
