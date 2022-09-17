#include "libraries.h"
using namespace std;

#define neherin_p 7
#define classic_p 5
#define hawaiian_p 5
#define maxicana_p 5
#define newyork_p 5
#define sicilian_p 5
#define cheesy_p 5
#define beefp_t 1.5
#define exCheese_t 1
#define blackolive_t 1
#define bacon_t 1
#define mushrooms_t 1
double balance = 0.0;
double total = 0.0;
double totalPurchase = 0.0;
int numOfPizza=0;
string pur_pizza[7];
//string pur_pizza[7]={0};
int sold[7] ={0};

void baking(); ///displays the process notes
void addCustMoney(double, double);///updating money after inserting
void insertMoney(); ///inserting the money
void GetCustomerOrder(); ///taking orders from the customer
void calculateThePrice(int, int, int,int);///calculate the payment amount according to their price
void checkBalance(double, int, int,int,int); ///checking whether the customer has money or not
void c_continueChoice();
void c_endOfProgram(); ///display exit screen
void CheckCurrentBalance(); ///calculating balance after transaction
double DisplayTheNotes();
double DisplayTheCoins();
void GetCustomerOrderReady(int, int, int, int);///calculating price, updating files
void PurchaseHistory();///updating purchasing history
double toppingsPrice(int);///returns the price of toppings

///start
void GetCustomerOrder() //1
{
    int pizzaNo,amount,toppingsNo,sauceNo;
    int choice;

    system("cls");
    cout << "Please choose one of the following: " << endl; ///customer menu
    cout << "\n1- Order Pizza." << endl;
    cout << "2- Insert Money." << endl;
    cout << "3- Balance Inquiry." << endl;
    cout << "4- Exit." << endl << endl;
    cout << "Your Choice: ";
    cin >> choice;
    if(choice == 1)
    {
        system("cls");
        string display;
        int n,count=0;
        bool fine=0;
        ifstream show;
        show.open("./Files/PriceList.dat");  ///reading from File

        cout << "Item names and prices :" << endl;
        Sleep(1000);
        cout << endl;

        while(show >> display)  ///assigning values from file into variable
        {
            n = display.size();
            cout << display << " ";
            if(display[n-1] >= '0' && display[n-1] <= '9')
            {
                count++;
                fine = 0;
            }
            if(count == 1 && fine==0)
            {
                fine = 1;
                cout << " ";
            }
            else if(count == 2)
            {
                count = 0;
                cout << endl;
            }
        }
        show.close(); ///closing the file

		cout << "List of sauce:\n1 - Tomato\n2 - Barbecue\n3 - Garlic\n4 - Chilly\n";

        cout << "\n\nPlease choose your preferable pizza: " << endl;
        cout << "Pizza Code: ";
        cin >> pizzaNo;
        cout << "Select Toppings: ";
        cin >> toppingsNo;

        if(pizzaNo != 1 && pizzaNo != 2 && pizzaNo != 3 && pizzaNo != 4 && pizzaNo != 5 && pizzaNo != 6 && pizzaNo != 7)
        {
            cout << "\nInvalid Pizza Code!" << endl;
            Sleep(1500);
            c_continueChoice();
        }
        if(toppingsNo != 1 && toppingsNo != 2 && toppingsNo != 3 && toppingsNo != 4 && toppingsNo != 5)
        {
            cout << "\nInvalid Toppings Code" << endl;
            Sleep(1500);
            c_continueChoice();
        }

        cout << "Pizza Amount: ";
        cin >> amount;
        cout << "Select Sauce of your liking: ";
        cin >> sauceNo;
        GetCustomerOrderReady(pizzaNo,amount,toppingsNo,sauceNo);   ///sends the order details
        calculateThePrice(pizzaNo,amount,toppingsNo,sauceNo);   ///sends order details to calculate the bill
    }
    else if(choice == 2)
        insertMoney();
    else if(choice == 3)
        CheckCurrentBalance();
    else if(choice == 4)
        c_endOfProgram();
    else {
        cout << "\nInvalid Input.\n";
        Sleep(1500);
        c_continueChoice();
    }
}
void checkBalance(double price, int pizzaNo, int piece,int toppingsNo,int sauceNo) ///checking if there is enough money
{
    system("cls");
    if(balance >= price)
    {
        totalPurchase += price;
        balance -= price;

        cout << "\nYour total cost is - RM" << totalPurchase << endl;
        cout << "Your balance is - RM" << balance << endl << endl;
        ///GetCustomerOrderReady(pizzaNo,piece,toppingsNo,sauceNo);
        ///c_continueChoice();
        baking();
    }
    else {
        cout << "\nThere is not enough money." << endl;
        cout << "Please insert some money." << endl;
        Sleep(2000);
        insertMoney();
    }
}
void insertMoney()  ///enables the customer to insert money if their balance is empty
{
    int choice,piece,temp;
    double coins=0.0, notes=0.0;

    system("cls");
    cout <<"\nPlease choose any of the following: " << endl;
    cout << "\n1- Notes?\n2- Coins?" << endl;   ///choosing between notes and coins for insertion
    cout << "Your Choice: ";
    cin >> choice;

    if(choice == 1){
        notes = DisplayTheNotes();
        cout << "Number of Note: ";
        cin >> piece;

        if(piece > 10 || piece < 0)
        {
            cout << "\nYou cannot insert more than 10 notes at a time." << endl;
            Sleep(1000);
            c_continueChoice();
        }
        else {
            notes = notes * (piece*1.0);
            total += notes; /// total is declared as global
        }
        cout << "\nYour balance has been updated!" << endl;
        Sleep(2000);
    }
    else if(choice == 2)
    {
        coins = DisplayTheCoins();
        cout << "Number of Coins: ";
        cin >> piece;

        if(piece > 10 || piece < 0)
        {
            cout << "\nYou cannot insert more than 10 coins at a time." << endl;    ///one cannot insert 10 notes/coins at a time
            Sleep(1000);
            c_continueChoice();
        }
        else {
            coins = coins * (piece*1.0);
            total += coins;
        }
        cout << "\nYour balance has benn updated!" << endl;
        Sleep(2000);
    }
    else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		c_continueChoice();
	}
	addCustMoney(notes,coins);      ///calls the function to add money to account
}
double DisplayTheNotes()    ///returns varieties of notes
{
	///double totalNotes = 0.0;
	string choice;
	system("cls");

	cout << "\n\nPlease Choose one of the following:" << endl;
	cout << "\n\n1- RM1\t   2- RM5\t 3- RM10" << endl;
	cout << "\n4- RM20\t   5- RM50\t 6- RM100" << endl;

	cout << "\nYour Transaction: ";
	cin >> choice;

	if(choice == "1") return 1;
	else if(choice == "2") return 5;
	else if(choice == "3") return 10;
	else if(choice == "4") return 20;
	else if(choice == "5") return 50;
	else if(choice == "6") return 100;
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		c_continueChoice();
	}
}

double DisplayTheCoins()    ///returns varieties of coins
{
	///double totalCoins = 0.0;
	string choice;
	system("cls");

	cout << "\n\nPlease Choose one of the following:" << endl;
	cout << "\n\n1- RM0.10\t 2- RM0.20\t 3- RM0.50" << endl;
	cout << "\n4- RM0.70\t 5- RM0.80\t 6- RM0.90" << endl;

	cout << "\nYour Transaction: ";
	cin >> choice;

	if(choice == "1") return 0.10;
	else if(choice == "2") return 0.20;
	else if(choice == "3") return 0.50;
	else if(choice == "4") return 0.70;
	else if(choice == "5") return 0.80;
	else if(choice == "6") return 0.90;
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		c_continueChoice();
	}
}
void calculateThePrice(int pizzaNo,int piece,int toppingsNo,int sauceNo)    ///calculates the bill according to the prices
{
    double price;
    switch(pizzaNo)
    {
    case 1:
        price = (piece * neherin_p) + toppingsPrice(toppingsNo)*piece;
        checkBalance(price,pizzaNo,piece,toppingsNo,sauceNo);
        break;
    case 2:
        price = (piece * classic_p) + toppingsPrice(toppingsNo)*piece;
        checkBalance(price,pizzaNo,piece,toppingsNo,sauceNo);
        break;
    case 3:
        price = (piece * hawaiian_p) + toppingsPrice(toppingsNo)*piece;
        checkBalance(price,pizzaNo,piece,toppingsNo,sauceNo);
        break;
    case 4:
        price = (piece * maxicana_p) + toppingsPrice(toppingsNo)*piece;
        checkBalance(price,pizzaNo,piece,toppingsNo,sauceNo);
        break;
    case 5:
        price = (piece * newyork_p) + toppingsPrice(toppingsNo)*piece;
        checkBalance(price,pizzaNo,piece,toppingsNo,sauceNo);
        break;
    case 6:
        price = (piece * sicilian_p) + toppingsPrice(toppingsNo)*piece;
        checkBalance(price,pizzaNo,piece,toppingsNo,sauceNo);
        break;
    case 7:
        price = (piece * cheesy_p) + toppingsPrice(toppingsNo)*piece;
        checkBalance(price,pizzaNo,piece,toppingsNo,sauceNo);
        break;

    }
}

void baking()       ///displays the process notes
{
	///system("cls");
	cout << "Please Wait While Your Pizza Is Being Prepared ^_^" << endl << endl;
	Sleep(500);
	cout << "Gathering Ingredients";
	for(int i=1; i<5; i++)
	{
		Sleep(800);
		cout << ".";
	}
	Sleep(1500);
	cout << "\nBaking";
	for(int i=1; i<5; i++)
	{
		Sleep(800);
		cout << ".";
	}
	Sleep(1500);
	cout << "\nBaking Done!! Now commencing packaging";
	for(int i=1; i<5; i++)
	{
		Sleep(800);
		cout << ".";
	}
	Sleep(1500);
	cout << "Your Pizza Is Ready!! ^_^" << endl;
	Sleep(2000);
	c_endOfProgram();
}
void CheckCurrentBalance(){
	system("cls");
	cout << "\nYour Current Balance is: RM" << balance << endl;
	Sleep(2000);
	c_continueChoice();
}
double toppingsPrice(int toppingsNo) ///returns toppings prices
{
    double price=0.0;
    if(toppingsNo == 1) return 1.5;
    else if(toppingsNo == 2) return 1.0;
    else if(toppingsNo == 3) return 1.0;
    else if(toppingsNo == 4) return 1.0;
    else if(toppingsNo == 5) return 1.0;
}
void GetCustomerOrderReady(int pizzaNo,int piece,int toppingsNo,int sauceNo)    ///updates files
{
    string pizzaName;
    int code_p;
    string pizza_crust[7] = {"NeherinSpecialPremium","ClassicChicken","Hawaiian","Maxicana","NewYorkStyle","Sicilian","Cheesy"};
    int amount[7] = {0};

    ///checking availability
    ifstream check;
    check.open("./Files/PizzaCapacity.dat");
    int i=0;
    while(check >> code_p >> pizzaName >> *(amount+i))
    {
        if(code_p == pizzaNo && *(amount+i) >= piece)
        {
            *(amount+i) -= piece;
            *(sold+i) += piece;
            *(pur_pizza+i) = *(pizza_crust+i);
        }
        else if(*(amount+i) < piece && code_p == pizzaNo && *(amount+i) != 0)
        {
            cout << "\nSorry, there are only " << *(amount+i) << " pieces in stock." << endl;
            c_continueChoice();
        }
        else if(code_p == pizzaNo && *(amount+i) == 0)
        {
            cout << "\nOOPS!!\nSold Out!! >.<" << endl;
            c_continueChoice();
        }
        i++;
    }
    check.close();

    ///updating amount after purchase
    ofstream update;
    update.open("./Files/PizzaCapacity.dat");
    i=0;
    while(update.is_open())
    {
        if(i==7) break;
        update << i+1 << " " << *(pizza_crust+i) << " " << *(amount+i);
        update << endl;
        i++;
    }
    update.close();

    ///toppings
    string toppingsName;
    int code_tp;
    int amount_t[5] = {0};
    string pizza_toppings[] = {"BeefPepperoni","ExtraCheese","BlackOlives","Bacon","Mushrooms"};

    ifstream t_check;
    t_check.open("./Files/ToppingsCapacity.dat");
    i=0;
    while(t_check >> code_tp >> toppingsName >> *(amount_t+i))
    {
        if(code_tp == toppingsNo && *(amount_t+i) >= 50)
        {
            *(amount_t+i) -= 50;
        }
        else if(*(amount_t+i) < 50 && code_tp == toppingsNo && *(amount_t+i) != 0)
        {
            cout << "\nSorry, there are only " << *(amount_t+i) << " grams of toppings in stock." << endl;
            c_continueChoice();
        }
        else if(code_tp == toppingsNo && *(amount_t+i) == 0)
        {
            cout << "\nOOPS!!\nSold Out!! >.<" << endl;
            c_continueChoice();
        }
        i++;
    }
    t_check.close();

    ///updating amount after purchase
    ofstream t_update;
    t_update.open("./Files/ToppingsCapacity.dat");
    i=0;
    while(t_update.is_open())
    {
        if(i==5) break;
        t_update << i+1 << " " << *(pizza_toppings+i) << " " << *(amount_t+i);
        t_update << endl;
        i++;
    }
    t_update.close();

    ///sauce
    string sauceName;
    int code_s;
    int amount_s[4] = {0};
    string pizza_sauce[] = {"Tomato","Barbecue","Garlic","Chilly"};

    ifstream s_check;
    s_check.open("./Files/SauceCapacity.dat");
    i=0;
    while(s_check >> code_s >> sauceName >> *(amount_s+i))
    {
        if(code_s == sauceNo && *(amount_s+i) >= 2)
        {
            *(amount_s+i) -= 2;
        }
        else if(*(amount_s+i) < 2 && code_s == sauceNo && *(amount_s+i) != 0)
        {
            cout << "\nSorry, there are only " << *(amount_s+i) << " grams of toppings in stock." << endl;
            c_continueChoice();
        }
        else if(code_s == sauceNo && *(amount_s+i) == 0)
        {
            cout << "\nOOPS!!\nSold Out!! >.<" << endl;
            c_continueChoice();
        }
        i++;
    }
    s_check.close();

    ///updating amount after purchase
    ofstream s_update;
    s_update.open("./Files/SauceCapacity.dat");
    i=0;
    while(s_update.is_open())
    {
        if(i==4) break;
        s_update << i+1 << " " << *(pizza_sauce+i) << " " << *(amount_s+i);
        s_update << endl;
        i++;
    }
    s_update.close();
}
void addCustMoney(double notes, double coins)   ///adds money to account
{
    balance += notes + coins;
	GetCustomerOrder();
}
void PurchaseHistory()  ///shows previous purchase history after updating the file
{
    ofstream write;
    write.open("./Files/Sales.dat");
    int i=0;
    while(write.good())
    {
        if(i==7) break;
        if(*(sold+i) != 0)
        {
            write << *(pur_pizza+i) << ": " << *(sold+i) << "Piece(s)" << endl;
        }
        i++;
    }
    write << "The total sales for this operation: RM" << total-balance << "." << endl;
    write << endl;
    write.close();
}
//Display after every transaction to check if the user want to do anything else of not.
void c_continueChoice(){
	string choice;

	cout << "\nDo you want to continue (Y/N): ";
	cin >> choice;
	if (choice == "Y" || choice == "y") GetCustomerOrder();
	else if (choice == "N" || choice == "n"){
		Sleep(2000);
		c_endOfProgram();
	}
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		c_continueChoice();
	}
}

//When the user want to exit the program those massages will be displayed
//and the program will finish immediately.
void c_endOfProgram(){
	PurchaseHistory();
	system("cls");
	cout << "\n\n\n\t\t\tThank you for using N-N Mini Instant Pizza Vending Machine" << endl;
	cout << "\n\t\t\t\t\t\tHave a nice day." << endl;
	cout << "\t\t\t\t\t\tSee you soon." << endl;
	Sleep(2000);
}




















