#include <iostream>
#include <string>
using namespace std;

class Store {
private:
    string location;
public:
    void open() { // Default open method
        cout << "Store at " << location << " is open (Base class)" << endl;
    }

    void open(string time) { // Overloaded method with time parameter
        cout << "Store at " << location << " opens at " << time << " (Base class)" << endl;
    }

    Store(string location) : location(location) {
        cout << "Constructor for Store class with \n\tlocation: " << location << endl;
    }

    ~Store() {
        cout << "Destructor of Store class for location: " << location << endl;
    }
};

class GroceryStore : public Store {
private:
    int inventoryCount;
public:
    void restock() { // Restock function
        cout << "GroceryStore restock function (Derived class)" << endl;
    }

    void restock(int items) { // Overloaded restock function with items count
        cout << "Restocking " << items << " items in the GroceryStore (Derived class)" << endl;
    }

    GroceryStore(string location, int inventoryCount) 
        : Store(location), inventoryCount(inventoryCount) {
        cout << "Constructor for GroceryStore Class with \n\tlocation: " 
             << location << "\n\tand inventory count: " << inventoryCount << endl;
    }

    ~GroceryStore() {
        cout << "Destructor of GroceryStore class for inventory count: " << inventoryCount << endl;
    }
};

int main() {
    cout << "Static Binding Polymorphism Demonstration:\n" << endl;

    // Base class object
    Store store("Pattom");
    store.open();
    store.open("9:00 AM"); // Overloaded method

    cout << "\n";

    // Derived class object
    GroceryStore gStore("Ullor", 150);

    // gStore.open();
    // gStore.open("10:00 AM");
    gStore.restock();
    gStore.restock(50); // Overloaded method

    return 0;
}
