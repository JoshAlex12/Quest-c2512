#include <iostream>
#include <string>
using namespace std;

class Store {
private:
    string location;
public:
    virtual void open() { // Virtual function
        cout << "Location: " << location << " open function (Store)" << endl;
    }

    Store(string location) : location(location) {
        cout << "Constructor for Store class with \n\tlocation: " << location << endl;
    }

    virtual ~Store() { // Virtual destructor for proper cleanup
        cout << "Destructor of Store class for location: " << location << endl;
    }
};

class GroceryStore : public Store {
private:
    int inventoryCount;
public:
    void open() override { // Overriding the open() function
        cout << "Location: GroceryStore open function (GroceryStore)" << endl;
    }

    void restock() {
        cout << "GroceryStore restock function" << endl;
    }

    GroceryStore(string location, int inventoryCount) : Store(location), inventoryCount(inventoryCount) {
        cout << "Constructor for GroceryStore Class with \n\tlocation: " << location << "\n\tand inventory count: " << inventoryCount << endl;
    }

    ~GroceryStore() {
        cout << "Destructor of GroceryStore class for inventory count: " << inventoryCount << endl;
    }
};

int main() {
    cout << "Dynamic object initialization:\n" << endl;

    Store* st = new Store("Sreekariyam");
    Store* gs = new GroceryStore("Manvila", 200); // Base class pointer to derived object

    st->open(); // Calls Store::open()
    gs->open(); // Calls GroceryStore::open() due to runtime polymorphism

    delete st;
    delete gs;

    return 0;
}
