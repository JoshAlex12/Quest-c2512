/*
single inheritance with dynamic binding
=============================================================
one two dynamic/static objects of the Derived class 
pointed by base class pointer
and call all behaviours using Base class pointer 

Override Base Class behaviors to derived class.
Define constructors and destructors for all the classes 
Define all the fields as dynamic fields in each class 

If you use string, use c-string (don't use string class)
        ie. dynamic c-string [dynamic char array]

=======================================================================================================

Example 6: `Appliance and WashingMachine`                                          -> Josh
- `Base Class:` `Appliance`  
  - Fields: `brand`, `powerConsumption`  
  - Pure Virtual Behaviors: `turnOn()`, `turnOff()`  
- `Derived Class:` `WashingMachine`  
  - Fields: `drumCapacity`, `spinSpeed`  
Example 7: `Person and Teacher`                                                     -> Nayana
- `Base Class:` `Person`  
  - Fields: `name`, `age`  
  - Pure Virtual Behaviors: `introduce()`, `work()`  
- `Derived Class:` `Teacher`  
  - Fields: `subject`, `experienceYears`  
Example 8: `Plant and FloweringPlant`                                               -> Dhaheen
- `Base Class:` `Plant`  
  - Fields: `height`, `type`  
  - Pure Virtual Behaviors: `photosynthesize()`, `grow()`  
- `Derived Class:` `FloweringPlant`  
  - Fields: `flowerColor`, `bloomSeason`  
Example 9: `Game and BoardGame`                                                     -> Pitchumani
- `Base Class:` `Game`  
  - Fields: `name`, `playerCount`  
  - Pure Virtual Behaviors: `startGame()`, `endGame()`  
- `Derived Class:` `BoardGame`  
  - Fields: `boardSize`, `piecesCount`  
Example 10: `Instrument and Guitar`                                                  -> Bhagya
- `Base Class:` `Instrument`  
  - Fields: `type`, `material`  
  - Pure Virtual Behaviors: `play()`, `tune()`  
- `Derived Class:` `Guitar`  
  - Fields: `stringCount`, `electric`  

*/

// Example 6: `Appliance and WashingMachine`                                          -> Josh
// - `Base Class:` `Appliance`  
//   - Fields: `brand`, `powerConsumption`  
//   - Pure Virtual Behaviors: `turnOn()`, `turnOff()`  
// - `Derived Class:` `WashingMachine`  
//   - Fields: `drumCapacity`, `spinSpeed`  

#include <iostream>
#include <cstring>
using namespace std;

class Appliance{
  protected:
    char* brand;
    int* powerConsumption;
  public:
    virtual void turnOn() = 0;

    virtual void turnOff() = 0;

    Appliance(const char* v_brand, int v_powerConsumption){
      brand = new char[strlen(v_brand) + 1];
      strcpy(brand, v_brand);
      powerConsumption = new int(v_powerConsumption);
      cout << "Constructor for Appliance class with \n\tbrand: " << brand << "\n\tand power Consumption: " << *powerConsumption <<  endl;
    }

    virtual ~Appliance(){
      cout << "Destructor of Appliance class with \n\tbrand: " << brand << "\n\tand power Consumption: " << *powerConsumption <<  endl;
      delete[] brand;
      delete powerConsumption;
    }

};

class WashingMachine : public Appliance{
  private:
    int* drumCapacity;
    int* spinSpeed;

  public:
    void turnOn() override{
cout << "Turned On Washing Machine with \n\tbrand: " << brand << "\n\tand power Consumption: " << *powerConsumption << "\n\tand drum Capacity: " << *drumCapacity << "\n\tand spin Speed: " << *spinSpeed << endl;    }

    void turnOff() override{
       cout << "Turned Off Washing Machine with \n\tbrand: " << brand << "\n\tand power Consumption: " << *powerConsumption << "\n\tand drum Capacity: " << *drumCapacity << "\n\tand spin Speed: " << *spinSpeed << endl;     
    }

    WashingMachine(const char* v_brand, int v_powerConsumption, int v_drumCapacity, int v_spinSpeed) :Appliance(v_brand, v_powerConsumption) {
      drumCapacity = new int(v_drumCapacity);
      spinSpeed = new int(v_spinSpeed);
      cout << "Constructor for WashingMachine class with \n\tbrand: " << brand << "\n\tand power Consumption: " << *powerConsumption << "\n\tand drum Capacity: " << *drumCapacity << "\n\tand spin Speed: " << *spinSpeed << endl;
    }

    ~WashingMachine(){
      cout << "Destructor of WashingMachine class with \n\tbrand: " << brand << "\n\tand power Consumption: " << *powerConsumption <<  endl;
      delete drumCapacity;
      delete spinSpeed;
    }

};

int main(){
  Appliance* app1 = new WashingMachine("Bosche", 1200, 500, 100); 
  Appliance* app2 = new WashingMachine("Bajaj", 1000, 100, 500);

  // cout << "Object 1" << endl;
  app1->turnOn(); 
  app1->turnOff(); 

  app2->turnOn(); 
  app2->turnOff(); 

  delete app1;
  delete app2;

  return 0;
}