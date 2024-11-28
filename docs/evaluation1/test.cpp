#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

bool isValid(int id) {
	if ((id<0)) {
		return false;
	}
	return true;

}

int ifExist(int id, int bookingId[], int counter) {
	for (int i = 0; i < counter; i++) {
		if (bookingId[i] == id) {
			return i;
		}
	}
	return -1;
}

void createBooking(int bookingId[], int ticketAmount[], int foodAmount[], int &bookingsCounter) {

	if (bookingsCounter >= MAX_SIZE) {

		cout << "Booking Limit exceeded!";
		return;
	}

	int id;

	cout << "Enter Booking Id: ";
	cin >> id;
	if (isValid(id)) {
		if(ifExist(id, bookingId, bookingsCounter) == -1 ) {
			int amountOfTicket,amountOfFood;

			cout << "Enter Ticket amount: ";
			cin >> amountOfTicket;
			cout << "Enter Food amount: ";
			cin >> amountOfFood;

			bookingId[bookingsCounter] = id;
			ticketAmount[bookingsCounter] = amountOfTicket;
			foodAmount[bookingsCounter] = amountOfFood;

			cout << "Booking added successfully..";

			bookingsCounter++ ;
		}
		else {
			cout << "Booking Id already exists!";
		}
	}
	else {
		cout << "Enter valid BookingID.";
	}
	cout << "\n";
}

void editBooking(int bookingId[], int ticketAmount[], int foodAmount[], int counter) {
	int id;
	cout << "Enter the Booking Id: ";
	cin >> id;

	int i = ifExist(id, bookingId, counter);
	if (i!=-1) {



		cout << "Current Ticket Amount: " << ticketAmount[i]<< endl;
		cout << "Current Food Amount: " << foodAmount[i]<< endl;

		cout << "Enter new Ticket Amount: ";
		cin >> ticketAmount[i];
		cout << "Enter new Food Amount: ";
		cin >> foodAmount[i];


		cout << "Booking updated successfully ";

	}

	else {
		cout << "Booking id does not exists.";
	}
	cout << "\n";
}

void deleteBooking(int bookingId[], int ticketAmount[], int foodAmount[], int &counter) {

	int id;
	cin >> id;
	int index=ifExist(id, bookingId, counter);

	if (index!=-1) {

		for (int i = index; i < counter; i++) {

			bookingId[i] = bookingId[i + 1];
			ticketAmount[i] =ticketAmount[i + 1];
			foodAmount[i] = foodAmount[i + 1];

		}
		counter--;
		cout << "Data for the BookingId: " << id << " has been removed." << endl;
	}
	else {
		cout << "Enter Valid BookingID";
	}
	cout << "\n";

}

void displayBooking(int bookingId[], int ticketAmount[], int foodAmounts[], int size) {
	if (size>0) {
		cout<< "Booking ID\t" << "Ticket Amount\t" << "Food Amount\t\n" << endl;
		for (int i = 0; i < size; i++)
		{
			cout  << bookingId[i] <<"\t\t" << ticketAmount[i] <<"\t\t"<< foodAmounts[i]<<"\n"<< endl;
		}

	}
	else {
		cout << "No Data to be retrieved.";
	}
	cout<<"\n";
}

void printMenu() {
	cout << "Menu:\n";
	cout << "1. Create Booking\n";
	cout << "2. Display All Bookings\n";
	cout << "3. Edit Booking\n";
	cout << "4. Delete Booking\n";
	cout << "5. Exit\n";
}

int main() {
	cout << "\n=== Railway Ticket Booking Management System ===\n";

	// Arrays to hold booking details
	int bookingId[MAX_SIZE] = {0};
	int ticketAmount[MAX_SIZE] = {0};
	int foodAmount[MAX_SIZE] = {0};

	int numBookings = 0; // Counter for current bookings

	int choice; // User's menu choice

	do {
		printMenu(); // Display menu
		cout<<"\n";
		cout << "Enter your choice: ";
		cin >> choice;

		// Menu-driven functionality
		switch (choice) {
		case 1:
			cout << "\n";
			createBooking(bookingId, ticketAmount, foodAmount, numBookings);
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			displayBooking(bookingId, ticketAmount, foodAmount, numBookings);
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			editBooking(bookingId, ticketAmount, foodAmount, numBookings);
			cout << "\n";
			break;
		case 4:
			cout << "\n";
			deleteBooking(bookingId, ticketAmount, foodAmount, numBookings);
			cout << "\n";
			break;
		case 5:
			cout << "\n";
			cout << "Exiting the system. Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 5.\n";
		}
	} while (choice != 5);

	return 0;
}

