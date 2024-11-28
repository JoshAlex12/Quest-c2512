#include<iostream>

using namespace std;

struct student{
	int id;
	char name[255];
};

int main(){

	student student1;

	cout << "Enter student1's id: "; cin >> student1.id;
	cout << "Enter student1's name: "; cin >> student1.name;


	cout << "Student1 id: " << student1.id;
	cout << "Student1 name: " << student1.name;

	return 0;
}
