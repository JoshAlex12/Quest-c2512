/*
single inheritance using static binding:
=============================================================
Create two static objects for Both Base and Derived class
and call all behaviours
and 
one two dynamic objects for Base and Derived class 
and call all behaviours

Define constructors and destructors for all the classes 

=======================================================================================================

Example 6: `Banking System`                                                                      -> Dhaheen
- `Base Class:` Account `{field: accountNumber, behavior: deposit()}`
- `Derived Class:` SavingsAccount `{field: interestRate, behavior: calculateInterest()}`
Example 7: `Animal Kingdom`                                                                      -> Nayana
- `Base Class:` Animal `{field: species, behavior: eat()}`
- `Derived Class:` Bird `{field: wingSpan, behavior: fly()}`
Example 8: `Retail System`                                                                         -> Josh
- `Base Class:` Store `{field: location, behavior: open()}`  
- `Derived Class:` GroceryStore `{field: inventoryCount, behavior: restock()}`  
Example 9: `Gaming System`                                                                       -> Bhagya
- `Base Class:` Character `{field: health, behavior: move()}`
- `Derived Class:` Warrior `{field: weaponType, behavior: attack()}`
Example 10: `Transportation Network`                                                            -> Pitchumani
- `Base Class:` Vehicle `{field: registrationNumber, behavior: refuel()}`  
- `Derived Class:` Bicycle `{field: gearCount, behavior: pedal()}`  

*/

// Example 8: `Retail System`                                                                         -> Josh
// - `Base Class:` Store `{field: location, behavior: open()}`  
// - `Derived Class:` GroceryStore `{field: inventoryCount, behavior: restock()}`  

#include <iostream>
#include <string>
using namespace std;

class Store{
    private:
        string location;
    public:
        void open(){
            cout << "Location: " << location << " open function" << endl;
        }

        Store(string location) : location(location){
            cout << "Constructor for Store class with \n\tlocation: " << location << endl;
        }
        
        ~Store(){
            cout << "Destructor of Store class for location: " << location << endl;
        }
};

class GroceryStore : public Store{
    private: 
        int inventoryCount;
    public: 
        void restock(){
            cout << "GroceryStore restock function" << endl;
        }
        
        GroceryStore(string location, int inventoryCount) : Store(location), inventoryCount(inventoryCount) {
                cout << "Constructor for GroceryStore Class with \n\tlocation: " << location << "\n\tand inventory count: " << inventoryCount << endl;
        }
        
        ~GroceryStore(){
            cout << "Destructor of GroceryStore class for inventory count: " << inventoryCount << endl;
        }
};

int main(){

    cout << "Dynamic object initialization:\n" << endl;

    Store* st = new Store("Sreekariyam");
    GroceryStore* gs = new GroceryStore("Manvila", 200);

    st->open();
    gs->open();
    gs->restock();

    delete st;
    delete gs;

    cout << "\n==========================================================\n" << endl;

    cout << "\nStatic object initialization:\n" << endl;
    
    Store store("Pattom");
    GroceryStore gStore("Ullor", 100);

    store.open();
    gStore.open();
    gStore.restock();


    return 0;
}