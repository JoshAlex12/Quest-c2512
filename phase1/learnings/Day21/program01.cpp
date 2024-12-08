#include <iostream>

using namespace std;

int main()
{
    int id = 100;
    int* ptrId = &id;
    cout << "id=" << id << endl;
    cout << "addr of id=" << &id << endl;
    cout << "addr of id=" << ptrId << endl;
    cout << "id=" << *ptrId << endl;


    int *ptrIdNew = new int {100};
    cout << "addr of dyn mem=" << ptrIdNew << endl;
    cout << "dyn mem=" << *ptrIdNew << endl;

    delete ptrIdNew;
    ptrIdNew = nullptr; 



    return 0;
}