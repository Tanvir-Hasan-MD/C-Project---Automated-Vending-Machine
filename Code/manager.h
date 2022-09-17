#include "libraries.h"
using namespace std;
void GetManagerDetails(); ///login page for the manager which requires username and password
void CheckPasswordLength(string,string); ///checks whether the password has length of 6
void CheckUsernameAndPassword(string,string); ///checks whether the username and password matches the actual ones
void DisplayTransactions(); ///displays and calls functions according to options chosen by the manager
int CheckPizzaName(string); ///checks whether pizza exists, if it does returns the sequence number
int CheckToppingsName(string); ///checks whether toppings exists, if it does returns the sequence number
int CheckSauceName(string); ///checks whether sauce exists, if it does returns the sequence number
void RefillTheMachine(); ///refills the machine using file
void continueChoice(); ///asks whether you want to continue or not
void endOfProgram(); ///shows conclusion and terminates
void DisplayItemAmount(); ///reads from file and displays the product amounts
void DisplaySalesHistory(); ///reads from Sales.dat and shows last purchase history

void GetManagerDetails()
{
    string username,password;

    system("cls");

    cout << "Welcome to the manager section" << endl;
    cout << endl;
    cout << "Please Type valid Username And Password: " << endl;
    cout << endl;
    cout << "Username: ";
    cin >> username;    ///takes username as input
    cout << "Password: ";
    cin >> password;    ///takes password as input

    CheckPasswordLength(username,password);     ///calls the function to check password's length
}
void CheckPasswordLength(string user,string pass)
{
    if(pass.size() != 6)
    {
    	cout << endl;
        cout << "Invalid Password" << endl;
        cout << "Insert another password with length of 6 digits" << endl;
        Sleep(1000);
        GetManagerDetails();    ///if the conditions weren't met, calls the main manager function
    }
    else CheckUsernameAndPassword(user,pass);      ///otherwise check username and password validity
}
void CheckUsernameAndPassword(string user,string pass)
{
    string managerName[4] = {"Nahreen","Nadia","Jaki","Tanvir"};
    string managerPass[4] = {"123456","654321","456789","987654"};

    if(user == *(managerName+0) && pass == *(managerPass+0))    ///compares username and password
    {
        ///system("cls");
        cout << "\t\t\t\tWelcome Nahreen" << endl;
        Sleep(3000);
        DisplayTransactions();
    }
    else if(user == *(managerName+1) && pass == *(managerPass+1))
    {
        ///system("cls");
        cout << "\t\t\t\tWelcome Nadia" << endl;
        Sleep(3000);
        DisplayTransactions();
    }
    else if(user == *(managerName+2) && pass == *(managerPass+2))
    {
        ///system("cls");
        cout << "\t\t\t\tWelcome Jaki" << endl;
        Sleep(3000);
        DisplayTransactions();
    }
    else if(user == *(managerName+3) && pass == *(managerPass+3))
    {
        ///system("cls");
        cout << "\t\t\t\tWelcome Tanvir" << endl;
        Sleep(3000);
        DisplayTransactions();
    }
    else {
        cout << endl << "Invalid Username Or Password" << endl;
        cout << endl << "Please Insert Again. Thank you!" << endl;
        Sleep(3000);
        GetManagerDetails();
    }
}
void DisplayTransactions()
{
    int select;
    system("cls");
    cout << "Select a service mentioned below: " << endl;
    cout << "\n1: Sales History." << endl;
    cout << "2: Refill the machine." << endl;
    cout << "3: Exit!" << endl;
    cout << "\nYour choice(Enter Codes Only): " << endl;
    cin >> select;

    ///Transaction(select);
    int seek;

	if(select == 1) DisplaySalesHistory();      ///shows display previous sales history
	else if(select == 2){
		///Refill the machine with maximum 15 pizza for each type.
		///Give the manager the ability to take a look for the brands which need to refill.
		system("cls");

		cout << "\nPlease Choose One of the following: " << endl;
		cout << "\n1- Items Amount" << endl;
		cout << "2- Refill The Machine" << endl;
		cout << "\nYour choice(Enter Codes Only): ";
		cin >> seek;

		if(seek == 1) DisplayItemAmount();  ///calls the function to view items
		else if(seek == 2) RefillTheMachine();  ///calls the function to refill the machine
		else{
			cout << "\nInvalid Input" << endl;
			Sleep(2000);
			continueChoice();
		}
	}
	else if(select == 3){ ///exits to the last screen
		Sleep(2000);
		endOfProgram();
	}
	else {
        cout << "\nInvalid Input" << endl;
        Sleep(1000);
        DisplayTransactions();      ///if select is invalid then show the transaction manu again
	}
}
void DisplayItemAmount()
{
    string display;
    int choice;
    int n,count=0;
    bool fine=0;

    system("cls");

    ifstream show;
    show.open("./Files/PizzaCapacity.dat");

    cout << "Item Amount:" << endl;
    Sleep(1000);
    cout << "Pizza-\n";
    cout << endl;
    while(show >> display)
    {
        n = display.size();
        cout << display << " ";
        if(display[n-1] >= '0' && display[n-1] <= '9')
        {
            count++;
            fine = 0;
        }
        if(count == 1 && fine==0) ///displays '-' after first element of the string
        {
            fine = 1;
            cout << "- ";
        }
        else if(count == 2)
        {
            count = 0;
            cout << endl;
        }
    }
    show.close();

    display.clear(); ///clears the string
    count=0;
    fine = 0;

    Sleep(700);

    show.open("./Files/ToppingsCapacity.dat");
    cout <<"\nToppings-\n";
    cout << endl;
    while(show >> display)
    {
        n = display.size();
        cout << display << " ";
        if(display[n-1] >= '0' && display[n-1] <= '9')
        {
            count++;
            fine = 0;
        }
        if(count == 1 && fine==0) ///displays '-' after first element of the string
        {
            fine = 1;
            cout << "- "; ///escape sequence to escape a space
        }
        else if(count == 2)
        {
            count = 0;
            cout << endl;
        }
    }
    show.close();

    display.clear(); ///clears the string
    count=0;
    fine = 0;

    Sleep(700);

    show.open("./Files/SauceCapacity.dat");
    cout <<"\nSauce-\n";
    cout << endl;
    while(show >> display)
    {
        n = display.size();
        cout << display << " ";
        if(display[n-1] >= '0' && display[n-1] <= '9')
        {
            count++;
            fine = 0;
        }
        if(count == 1 && fine==0) ///displays '-' after first element of the string
        {
            fine = 1;
            cout << "- "; ///escape sequence to escape a space
        }
        else if(count == 2)
        {
            count = 0;
            cout << endl;
        }
    }
    show.close();

    Sleep(700);
    cout << "\nPlease choose One of the following: " << endl;
    cout << "\n1: Refill The Machine." << endl;
    cout << "2: Continue." << endl;
    cout << "\nYour Transaction: ";
    cin >> choice;

    if(choice == 1){
        Sleep(1000);
        RefillTheMachine();
    }
    else if(choice == 2){
        Sleep(1000);
        DisplayTransactions();
    }
    else {
        cout << "Invalid Input!! :(" << endl;
        Sleep(1000);
        continueChoice();
    }

}
void RefillTheMachine()
{
    system("cls");

    string pizza_crust[] = {"NeherinSpecialPremium","ClassicChicken","Hawaiian","Maxicana","NewYorkStyle","Sicilian","Cheesy"};
    string pizza_toppings[] = {"BeefPepperoni","ExtraCheese","BlackOlives","Bacon","Mushrooms"};
    string pizza_sauce[] = {"Tomato","Barbecue","Garlic","Chilly"};

    int pizza[7]={0},toppings[5]={0},sauce[4]={0};     /// for storing amount of items from .Files
    string s,pizzaName,toppingsName,sauceName;
    int n, m, pizzaCode, toppingsCode, sauceCode, amount, value, choice;



    cout << "Please Choose Which item you want to refill:\n";
    cout << "1- Pizza Crust" << endl;
    cout << "2- Pizza Toppings" << endl;
    cout << "3- Sauce" << endl;
    cout << "\nYour Choice: ";
    cin >> choice;

    if(choice != 1 && choice !=2 && choice !=3)
    {
        cout << "Invalid Input\n";
        Sleep(500);
        continueChoice();
    }
    ///pizza refillment
    cout << "**Note: Enter Name of the types!!" << endl;
    if(choice == 1)
    {
        ifstream pFile;
        pFile.open("./Files/PizzaCapacity.dat");    ///opening the file
        cout << "\nPlease enter the type of the Pizza: " ;
        cin >> pizzaName;
        pizzaCode = CheckPizzaName(pizzaName);

        cout << "Amount(Num): ";
        cin >> amount;
        value = amount;

        int i=0;
        while(pFile >> n >> s >> *(pizza+i))    ///assigning data from file into variables
        {
            if(n == pizzaCode){
                if(value + *(pizza+i) <= 15)
                {
                    cout << "\nThe pizza's amount has been updated." << endl;
                    *(pizza+i) += value;
                    cout << "This type contains " << *(pizza+i) << " pieces of pizza now!" << endl;
                }
                else if(15 - *(pizza+i) != 0){
                    cout << "\nYou can refill this type with" << 15- *(pizza+i) << " only!" << endl;
                    Sleep(1000);
                    continueChoice();
                }
                else if(15 - *(pizza+i) == 0)
                {
                    cout << "\nThis type has 15 pieces already!!" << endl;
                    cout << "You cannot refill this type." << endl;
                    Sleep(1000);
                    continueChoice();
                }
            }
            i++;
        }
        pFile.close();      ///closing the file

        ofstream pFileWrite;
        pFileWrite.open("./Files/PizzaCapacity.dat");   ///opening the file to write/update
        i=0;
        while(pFileWrite.is_open())     ///loop will run till the file is open
        {
            if(i == 7) break;
            pFileWrite << i+1 << " " << *(pizza_crust+i) << " " << *(pizza+i) << endl;    ///updating
            i++;
        }
        pFileWrite.close();     ///closing the file
    }
    ///s.clear();

    ///toppings refillment

    if(choice == 2)
    {
        ifstream tFile;
        tFile.open("./Files/ToppingsCapacity.dat");
        cout << "\nPlease enter the type of the toppings: " ;
        cin >> toppingsName;
        toppingsCode = CheckToppingsName(toppingsName);

        cout << "Amount(Grams): ";
        cin >> amount;
        value = amount;

        int i=0;
        while(tFile >> n >> s >> *(toppings+i)) ///assigning data from file into variables
        {
            if(n == toppingsCode){
                if(value + *(toppings+i) <= 1050)
                {
                    cout << "\nThe toppings amount has been updated." << endl;
                    *(toppings+i) += value;
                    cout << "This type contains " << *(toppings+i) << "gm of toppings now!" << endl;
                }
                else if(1050 - *(toppings+i) != 0){
                    cout << "\nYou can refill this type with" << 1050-*(toppings+i) << "gm only!" << endl;
                    Sleep(1000);
                    continueChoice();
                }
                else if(1050 - *(toppings+i) == 0)
                {
                    cout << "\nThis type has 1050gm already!!" << endl;
                    cout << "You cannot refill this type." << endl;
                    Sleep(1000);
                    continueChoice();
                }
            }
            i++;
        }
        tFile.close();

        ofstream tFileWrite;
        tFileWrite.open("./Files/ToppingsCapacity.dat");
        i=0;
        while(tFileWrite.is_open())
        {
            if(i == 5) break;
            tFileWrite << i+1 << " " << *(pizza_toppings+i) << " " << *(toppings+i) << endl;
            i++;
        }
        tFileWrite.close();
    }
    s.clear();

    ///sauce refillment
    if(choice == 3)
    {
        ifstream sFile;
        sFile.open("./Files/SauceCapacity.dat");
        cout << "\nPlease enter the type of the sauce: " ;
        cin >> sauceName;
        sauceCode = CheckSauceName(sauceName);

        cout << "Amount(Num): ";
        cin >> amount;
        value = amount;

        int i=0;
        while(sFile >> n >> s >> *(sauce+i)) ///assigning data from file into variables
        {
            if(n == sauceCode){
                if(value + *(sauce+i) <= 500)
                {
                    cout << "\nThe sauce's amount has been updated." << endl;
                    *(sauce+i) += value;
                    cout << "This type contains " << *(sauce+i) << "pieces of packets of sauce now!" << endl;
                }
                else if(500 - *(sauce+i) != 0){
                    cout << "\nYou can refill this type with" << 500-*(sauce+i) << "pieces of packets only!" << endl;
                    Sleep(1000);
                    continueChoice();
                }
                else if(500 - *(sauce+i) == 0)
                {
                    cout << "\nThis type has 500 pieces already!!" << endl;
                    cout << "You cannot refill this type." << endl;
                    Sleep(1000);
                    continueChoice();
                }
            }
            i++;
        }
        sFile.close();

        ofstream sFileWrite;
        sFileWrite.open("./Files/SauceCapacity.dat");
        i=0;
        while(sFileWrite.is_open())
        {
            if(i == 4) break;
            sFileWrite << i+1 << " " << *(pizza_sauce+i) << " " << *(sauce+i) << endl;
            i++;
        }
        sFileWrite.close();
    }
    Sleep(1500);
    continueChoice();
}
int CheckPizzaName(string pizzaName)
{
    if(pizzaName == "NeherinSpecialPremium") return 1;      ///checking the string and returning integer values
    else if(pizzaName == "ClassicChicken") return 2;
    else if(pizzaName == "Hawaiian") return 3;
    else if(pizzaName == "Maxicana") return 4;
    else if(pizzaName == "NewYorkStyle") return 5;
    else if(pizzaName == "Sicilian") return 6;
    else if(pizzaName == "Cheesy") return 7;
    else {
        cout << "\nInvalid pizza name! :(" << endl;
        Sleep(1500);
        ///continueChoice();
        RefillTheMachine();
    }
}
int CheckToppingsName(string toppingsName)
{
//    for(int i=0; i<toppingsName.size(); i++)
//    {
//        toppingsName[i] = towlower(toppingsName[i]); ///changing into lowercase letters if there's any uppercase letter
//    }
    if(toppingsName == "BeefPepperoni") return 1;
    else if(toppingsName == "ExtraCheese") return 2;
    else if(toppingsName == "BlackOlives") return 3;
    else if(toppingsName == "Bacon") return 4;
    else if(toppingsName == "Mushrooms") return 5;
    else {
        cout << "\nInvalid topping name! :(" << endl;
        Sleep(1500);
        ///continueChoice();
    	RefillTheMachine();
	}
}
int CheckSauceName(string sauceName)
{
//    for(int i=0; i<sauceName.size(); i++)
//    {
//        sauceName[i] = towlower(sauceName[i]); ///changing into lowercase letters if there's any uppercase letter
//    }
    if(sauceName == "Tomato") return 1;
    else if(sauceName == "Barbecue") return 2;
    else if(sauceName == "Garlic") return 3;
    else if(sauceName == "Chilly") return 4;
    else {
        cout << "\nInvalid sauce name! :(" << endl;
        Sleep(1500);
        ///continueChoice();
        RefillTheMachine();
    }
}

void DisplaySalesHistory()
{
    string s;
    int n,choice;

    system("cls");
    ifstream sales;
    sales.open("./Files/Sales.dat");        ///opening sales files to read

    while(sales >> s) ///assigning values of the sales.dat into string s
    {
        n = s.size();
        cout << s << " ";
        if(s[n-1] == ')')
            cout << endl;
        if(s[n-1] == '.')
            cout << endl << endl;
    }
    sales.close();
    cout << "\nPlease choose one of the following: " << endl;
    cout << "\n1- Clear the history" << endl;
    cout << "2- Continue" << endl;
    cout << "Your Choice(Enter Codes Only): ";
    cin >> choice;

    if(choice == 1){
        ofstream cl;
        cl.open("./Files/Sales.dat",ofstream::out); /// clear sales history
        cl.close();
        cout << "**Sales History Cleared!!\n\n";
        Sleep(1500);
        continueChoice();
    }
    else if(choice == 2)
    {
        Sleep(1500);
        DisplayTransactions();
    }
    else {
        cout << "Invalid Input" << endl;
        Sleep(1500);
        continueChoice();
    }
}
void continueChoice(){
	string choice;

	cout << "\nDo you want to continue (Y/N): ";
	cin >> choice;
	if (choice == "Y" || choice == "y") DisplayTransactions();
	else if (choice == "N" || choice == "n"){
		endOfProgram();
	}
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(1000);
		continueChoice();
	}
}
void endOfProgram(){
	system("cls");
	cout << "Thank you for your kindness sir." << endl;
	cout << "\nHave a nice day." << endl;
	cout << "\nSee you soon." << endl;
}






















