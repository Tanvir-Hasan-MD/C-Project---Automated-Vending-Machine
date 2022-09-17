/*
   TEAM N-N
1. ZANNAT NAHREEN - 1632738
2. NOWSHIN NADIA - 1714160
3. HASAN MD. TANVIR - 1716763
4. JAKI FAYEK ALVI RAHMAN - 1721485
*/
#include "libraries.h"
#include "manager.h"
#include "customer.h"
using namespace std;

void instructions();
void openingTheProgram();

int main()
{
    instructions();
    openingTheProgram();
}
void instructions(){
	cout << "\n\n\n\t\t\tWelcome to N-N Instant Mini Pizza Vending Machine." << endl;
	Sleep(400);
	cout<<  "\n\n\t\t\tHope You Will Be satisfied with our service."<<endl;
	Sleep(400);
	cout <<"\nInstructions:" << endl;
	Sleep(400);
	cout << "1- Manager:" << endl;
	Sleep(400);
    cout << " - You have to login to your account using your username and password." << endl;
    Sleep(400);
    cout << " - Manager should make sure that the Capitalization(case Sensitive) in username is right." << endl;
    Sleep(400);
	cout << " - Password should contain 6 digits or more." << endl;
	Sleep(400);
	cout << " - You can Refill this Vending machine with any amount from 1-15 pizzas, 1-1050 grams of toppings and 500 packets of sauce" << endl;
	Sleep(400);
	cout << " - You can check how much pizza,toppings and sauce are remaining in the machine." << endl;
	Sleep(400);


	cout << "\n2- Customer:" << endl;
	Sleep(400);
	cout << " - You can buy pizza with any amount you want but not exceed 15(Maximum) Pizza." << endl;
	Sleep(400);
	cout << " - If you don't have enough money, you have to insert some money acceptable by the machine." << endl;
	Sleep(400);
	cout << " - You can insert money in either coins or notes." << endl;
	Sleep(400);
	cout << " - Once you finish your transactions you can check your Balance." << endl;
	Sleep(400);

	cout << "\n\t\t\t\t Please Press 'Enter' to continue.." << endl;
	cin.get();
	system("cls"); ///page break
}

void openingTheProgram(){

	system("cls");

    string choice;

	cout << "\n\n\t\t\t\tWelcome to N-N Instant Mini Pizza Vending Machine." << endl;
	cout << "\nPlease use one of the following transactions: " << endl;
	cout << endl;

	cout << "1 - Customer" << endl;
	cout << "2 - Manager" << endl;
	cout << endl;
	cout << "Your transaction: ";

	cin >> choice;
	//Checking the input whether is it valid or not.
	if (choice != "1" && choice != "2"){
		cout << "\nInvalid Input" << endl;
		openingTheProgram();
	}


    if(choice == "1")
		GetCustomerOrder();
	 if(choice == "2")
		GetManagerDetails();
}

