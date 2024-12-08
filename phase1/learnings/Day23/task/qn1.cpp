/*
Examples for diamond problem in inheritance:
=============================================================
These class structures represent the diamond problem,
where the `final derived class` 
inherits ambiguously 
from two intermediate classes 
that share a common base class.
=============================================================
Create one static object for final-derived class
and call all behaviours
and 
one dynamic object for final-derived class 
and call all behaviours

Define constructors and destructors for all the classes 

=======================================================================================================

Example 6: `Media Content`                                                                              -> Dhaheen
- `Base Class:` Media `{field: title, behavior: play()}`
- `Derived Class 1:` Video `{field: resolution, behavior: display()}`
- `Derived Class 2:` Audio `{field: bitrate, behavior: listen()}`
- `Final Derived Class:` Movie `{field: duration, behavior: stream()}`
Example 7: `Electronic Gadgets`                                                                         -> Nayana
- `Base Class:` Gadget `{field: brand, behavior: powerOn()}`
- `Derived Class 1:` Phone `{field: carrier, behavior: makeCall()}`
- `Derived Class 2:` Camera `{field: resolution, behavior: takePhoto()}`
- `Final Derived Class:` Smartphone `{field: osVersion, behavior: browseWeb()}`
Example 8: `Organization Roles`                                                                         -> Josh
- `Base Class:` Employee `{field: empID, behavior: logHours()}`
- `Derived Class 1:` Developer `{field: programmingLanguage, behavior: writeCode()}`
- `Derived Class 2:` Tester `{field: testingTools, behavior: runTests()}`
- `Final Derived Class:` DevTester `{field: skillLevel, behavior: debug()}`
Example 9: `Gaming Characters`                                                                          -> Pitchumani
- `Base Class:` Character `{field: health, behavior: move()}`
- `Derived Class 1:` Warrior `{field: weaponType, behavior: attack()}`
- `Derived Class 2:` Mage `{field: spellType, behavior: castSpell()}`
- `Final Derived Class:` BattleMage `{field: hybridSkill, behavior: fight()}`
Example 10: `Food Production`                                                                             -> Bhagya
- `Base Class:` Food `{field: expirationDate, behavior: consume()}`
- `Derived Class 1:` Dairy `{field: fatContent, behavior: refrigerate()}`
- `Derived Class 2:` Bakery `{field: flourType, behavior: bake()}`
- `Final Derived Class:` Cheesecake `{field: layerCount, behavior: serve()}`

*/

// Example 8: `Organization Roles`                                                                      -> Josh                                                                    
// - `Base Class:` Employee `{field: empID, behavior: logHours()}`
// - `Derived Class 1:` Developer `{field: programmingLanguage, behavior: writeCode()}`
// - `Derived Class 2:` Tester `{field: testingTools, behavior: runTests()}`
// - `Final Derived Class:` DevTester `{field: skillLevel, behavior: debug()}`

#include <iostream>
#include <string>
using namespace std;

class Employee{
    private:
        int empID;
    public:
        void logHours(){
            cout << "EmpID: " << empID << " logHours function" << endl;
        }

        Employee(int empID) : empID(empID){
            cout << "Constructors of Employee Class with \n\tempID: " << empID << endl;
        }

        virtual ~Employee(){
            cout << "Destructors of Employee Class" << endl;
        }
};

class Developer : virtual public Employee {
    private:
        string programmingLanguage;
    public:
        void writeCode(){
            cout << "Developer writeCode function" << endl;
        }

        Developer(int empID, string programmingLanguage) : Employee(empID), programmingLanguage(programmingLanguage) {
            cout << "Constructors of Developer Class with \n\tempID: " << empID << "\n\tand programming language: " << programmingLanguage << endl;
        }

        virtual ~Developer(){
            cout << "Destructors of Developer Class" << endl;
        }
};

class Tester : virtual public Employee {
    private:
        string testingTools;
    public:
        void runTests(){
            cout << "Tester runTests function" << endl;
        }

        Tester(int empID, string testingTools) : Employee(empID), testingTools(testingTools) {
            cout << "Constructors of Tester Class with \n\tempID: " << empID << "\n\tand test tools: " << testingTools << endl;
        }

        virtual ~Tester(){
            cout << "Destructors of Tester Class" << endl;
        }
};

class DevTester : public Developer, public Tester {
    private:
        int skillLevel;
    public:
        void debug(){
            cout << "DevTester debug function" << endl;
        }

        DevTester(int empID, string programmingLanguage, string testingTools, int skillLevel) : Employee(empID), Developer(empID, programmingLanguage), Tester(empID, testingTools), skillLevel(skillLevel){
            cout << "Constructors of DevTester Class with \n\tempID: " << empID << "\n\tand programming language: " << programmingLanguage << "\n\tand test tools: " << testingTools << "\n\tand skill level: " << skillLevel << endl;
        }

        virtual ~DevTester(){
            cout << "Destructors of DevTester Class" << endl;
        }
};

int main(){
    
    cout << "Dynamic object initialization:\n" << endl;

    Employee* dt2 = new DevTester(102, "Java", "Cypress", 0);
    dt2->logHours();

    // You cant access the following functions
    // dt2->writeCode();
    // dt2->runTests();
    // dt2->debug();

    delete dt2;

    cout << "\n==========================================================\n" << endl;

    cout << "\nStatic object initialization:\n" << endl;
    DevTester dt1(101, "C++", "Selenium", 2);

    dt1.debug();
    dt1.runTests();
    dt1.writeCode();
    dt1.logHours();

    return 0;
}