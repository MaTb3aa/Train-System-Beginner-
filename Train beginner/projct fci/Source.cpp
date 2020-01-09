#include<iostream>
using namespace std;
struct  carriage{
	int numper;
	int classe;
	int price;

};
bool book_a_ticket(carriage car[], bool arr[1000][30], int NumOfCar){
	a:
	int classe;
	cout << "enter carriage class:";
	cin >> classe;
	cout << "the recante carriage in these class is:   ";
	for (int i = 0; i < NumOfCar; i++){
		if (car[i].classe == classe){
			
			cout << i+1 << "     " ;
		}
	}
	cout << "\n******************" << endl;
	cout << "Enter Carriage Numper :";

	int car_num;
	cin >> car_num;

	if (car_num <= NumOfCar&&car_num>0){
		cout << "Enter seat Numper :";
		int set_num;
		cin >> set_num;
		if (set_num <= 0 || set_num>30){
			cout<< "incorrect name of seat" << endl;
			cout << "******************************************************************" << endl;
			goto a;
		}
		car_num--;
		set_num--;
		if (arr[car_num][set_num] == 1){
			cout << "\nthis seat are resrved " << endl;

			cout << "\n******************************************************************" << endl;
			return 0;

		}
		else
			arr[car_num][set_num] = 1;
		cout << "successful booking" << endl;
		cout << "******************************************************************" << endl;
		return 1;
	}
	else cout << "incorrect name of carriage" << endl;
	cout << "\n******************************************************************" << endl;
	return 0;

}
void cansel_a_ticket(carriage car[], bool arr[1000][30], int NumOfCar){
	int car_num;

	cout << "enter car numper :";
	cin >> car_num;
	if (car_num <= NumOfCar&&car_num>0){
		int set_num;
	p:
		cout << "enter seat numper:";
		cin >> set_num;
		if (set_num <= 0 || set_num>30){
			cout << "un correct name of seat" << endl;
			cout << "******************************************************************" << endl;
			goto p;
		}
		car_num--;
		set_num--;
		arr[car_num][set_num] = 0;
		cout << "succesful canseling" << endl;
		cout << "******************************************************************" << endl;
	}
	else
	{
		cout << "un correct name of carriage" << endl;
		cout << "\n******************************************************************" << endl;
	}
}
void show_available_seats(carriage car[], bool arr[1000][30], int NumOfCar){
	int car_num;
	cout << "enter numper of carriage you need to see its free seat :";
	cin >> car_num;

	if (car_num <= NumOfCar&&car_num>0){
		cout << "the free seat is :" << endl;
		int p4 = 1;
		car_num--;
		for (int i = 0; i < 30; i++){

			if (arr[car_num][i] == 0){
				cout << i + 1 << "    ";
				if (p4 % 4 == 0){ cout << endl; }
				p4++;
			}
		}
		cout << "\n******************************************************************" << endl;
	}
	else{
		cout << "un correct name of carriage" << endl;
		cout << "\n******************************************************************" << endl;
	}
}
void  print_profits(carriage car[], bool arr[1000][30], int NumOfCar){
	int profits = 0;
	for (int i = 0; i < NumOfCar; i++){
		for (int j = 0; j < 30; j++){
			if (arr[i][j] == 1){

				profits = profits + (car[i].price);
				cout << "you booked in car of class " << car[i].classe << " and with price of " << car[i].price << endl;


			}
		}
	}cout << "Total profits = " << profits << endl;
	cout << "******************************************************************" << endl;
}

int main() {
start:
	int NumOfCar = 0;
	cout << "Enter the number of carriages:";

	cin >> NumOfCar;
	if (NumOfCar == 0) {
		cout << "you can not do eny opration with 0 car" << endl;
		goto start;
	}
	carriage* car = new carriage[NumOfCar];

	for (int i = 0; i < NumOfCar; i++) {
		car[i].numper = i + 1;
		cout << "Carriage#" << i + 1 << ":\n" << "Enter class: ";
		cin >> car[i].classe;
		cout << "Enter price: ";
		cin >> car[i].price;
		/*	for (int d = 0; d>

			cin >> car[i].price;
		}*/
	}
	bool arr[1000][30] = { 0 };
	cout << "******************************************************************" << endl;
	int chois;
	point1:
		cout << "Enter 1 to book a ticket." << endl;
		cout << "Enter 2 to cancel a ticket.\n";
		cout << "Enter 3 to show available seats.\n";
		cout << "Enter 4 to print profits in detail.\n";
		cout << "Enter 0 to exit.\n";
		cout << "Your choice:";
		cin >> chois;
		cout << "******************************************************************" << endl;
		if (chois == 1) {
		point2:
			bool x = 0;

			x = book_a_ticket(car, arr, NumOfCar);
			if (x == 0) {
				int y;
				cout << "enter 1 to enter an other seat." << endl;
				cout << "enter 2 to see the show available seats." << endl;
				cout << "Enter any kay to\" Return to the list\"." << endl;
				cout << "your chooes:";
				cin >> y;
				cout << "******************************************************************" << endl;
				if (y == 1)
					goto point2;
				else if (y == 2)

					goto point3;
				else  goto point1;
			}
			else goto point1;
		}
		else if (chois == 2) {

			cansel_a_ticket(car, arr, NumOfCar);
			goto point1;
		}
		else if (chois == 3) {
		point3:
			show_available_seats(car, arr, NumOfCar);
			goto point1;
		}
		else if (chois == 4) {

			print_profits(car, arr, NumOfCar);
			goto point1;
		}
		else if (chois == 0) {
			goto point0;
		}
		else {
			int x;
			cout << "RONG ANSER!!" << endl;
			cout << "Enter 1 to\" Return to the list\"." << endl;
			cout << "Enter eny kay to\"EXIT\"." << endl;
			cout << "Your choice:";
			cin >> x;
			cout << "******************************************************************" << endl;
			if (x == 1) { goto point1; }
			else
				goto point0;
			{

			}

		}
	point0:

		delete[] car;



		system("pause");

		return 0;
	
}
