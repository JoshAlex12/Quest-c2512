// Write a class Shape and find out the area and 
// using inheritance take three classes Rectangle, triangle, Square.

#include <iostream>
using namespace std;

class Shape{
    public:
        virtual float area() = 0;

        Shape(){
            cout << "Constructor Shape" << endl;
        }

        virtual ~Shape(){
            cout << "Destructor Shape" << endl;
        }; 
};

class Rectangle : public Shape {
    protected:
        int length;
        int breadth;

    public:

        float area(){
            return length * breadth;
        }

        Rectangle(int p_length, int p_breadth){
            length = p_length;
            breadth = p_breadth;
            cout << "Constructor Rectangle" << endl;
        }

        Rectangle(){
            cout << "Constructor Rectangle" << endl;
            cout << "Enter length: "; cin >> length;
            cout << "Enter breadth: "; cin >> breadth;
        }

        ~Rectangle(){cout << "Destructor Rectangle" << endl;};
};


class Entho : public Rectangle{
    private:

    public: 
        float area(){
            return length * breadth;
        }

        Entho(){cout << "Constructor Entho" << endl;};
        ~Entho(){cout << "Destructor Entho" << endl;};
};

int main(){
    // cout << "Using parent pointer to derived class: Shape* shape1 = new Rectangle(5.0, 3.0)" << endl;
    // Shape* shape1 = new Rectangle(5.0, 3.0);
    // cout << "Area of Rectangle: " << shape1->area() << endl;
    // delete shape1;

    cout << "Using parent pointer to derived class: Shape* shape1 = new Entho(5.0, 3.0)" << endl;
    Shape* shape1 = new Entho(5.0, 3.0);
    cout << "Area of Rectangle: " << shape1->area() << endl;
    delete shape1;

    cout << "\nWithout using pointers: Rectangle rect2(1, 2)" << endl;
    Rectangle rect2(1, 2);
    cout << "Area of rectangle" << rect2.area() << endl;

    return 0;
}