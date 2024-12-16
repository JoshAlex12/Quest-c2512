#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
using namespace std;

int main()

{
    vector<float> vect1;
    cout << "vector max_size:" << vect1.max_size() << endl;

    deque<float> deq;
    cout << "Deque max_size:" << deq.max_size() << endl;
    // vector<float> vect2;
    // cout << "max_size:" << vect2.max_size() << endl;

    list<float> lst;
    cout << "List max_size:" << lst.max_size() << endl;

    set<float> sett;
    cout << "Set max_size:" << sett.max_size() << endl;

    return 0;
}
