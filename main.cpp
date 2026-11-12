#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Bank
{
private:
    string bankName = "UNIBANK";

    string accountHolderName;
    string accountNumber;
    string password;
    string email;
    string phoneNumber;
    string address;
    double balance = 0;
    int age;

public:
    void saveFile();
    void getFile();
    void mainMenu();
    void generateAccountNumber();

    void createAccount();
    void login();
    void ourTeam();

    //--------------------

    void depositMoney();
    void withdrawMoney();
    void CheckBalance();
    void AccountDetails();
    void UpdateAccountDetails();
    void allTransactionHistory();
};

void Bank::mainMenu()
{
    int choice;

    cout << "\n===========================================\n";
    cout << "             " << bankName << endl;
    cout << "           Bank Management System\n";
    cout << "\n===========================================\n";
    cout << "1.  Create New Account\n";
    cout << "2.  Log in your existing account\n";
    cout << "3.  About Project\n";
    cout << "4.  Our Team\n";
    cout << "5.  Exit\n";

    cout << "---------------------------------------------\n";
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        createAccount();
        break;

    case 2:
        login();
        break;

    case 3:
        mainMenu();
        break;

    case 4:
        ourTeam();
        break;

    case 5:
        cout << "\nThank You For using UNI BANK.\n";
        return;

    default:
        cout << "\nInvalid choice! Try again.\n";
        mainMenu();
    }
};

void Bank::generateAccountNumber()
{
    ifstream file("accounts.txt");

    string data;
    int count = 0;

    while (getline(file, data))
    {
        count++;
    }
    file.close();
    accountNumber = to_string(1000 + count);
};

void Bank::createAccount()
{
    cout << "\n===========================================\n";
    cout << "              CREATE ACCOUNT\n";
    cout << "\n===========================================\n";

    cin.ignore();

    cout << "Enter Your Name : ";
    getline(cin, accountHolderName);

    cout << "Enter Your Age : ";
    cin >> age;
    cin.ignore();

    cout << "Enter Your Email : ";
    getline(cin, email);

    cout << "Enter Your Phone Number : ";
    getline(cin, phoneNumber);

    cout << "Enter Your address : ";
    getline(cin, address);

    cout << "Create your Password : ";
    getline(cin, password);

    balance = 0;
    generateAccountNumber();
    saveFile();

    cout << "\nAccount Created Succfully";
    cout << "\nYour Account namber : " << accountNumber << endl;

    mainMenu();
};

void Bank::saveFile()
{
    ofstream file("accounts.txt", ios::app);

    if (file.is_open())
    {
        file << accountNumber << "|"
             << accountHolderName << "|"
             << password << "|"
             << balance << "|"
             << email << "|"
             << phoneNumber << "|"
             << address << "|"
             << age << endl;

        file.close();
        cout << "\nAccount Information Saved Successfully!\n";
    }
    else
    {
        cout << "\nFile Open process failed....\n";
    }
};

void Bank::login()
{

    string inAccountNumber, inPassword;

    cout << "\n===========================================\n";
    cout << "                   LOGIN\n";
    cout << "\n===========================================\n";

    cin.ignore();

    cout << "Enter your Account Number : ";
    getline(cin, inAccountNumber);

    cout << "Enter your Password : ";
    getline(cin, inPassword);

    ifstream file("accounts.txt");
    if (!file.is_open())
    {
        cout << "\nAccount.txt not found";
        mainMenu();
        return;
    }

    string fAccountNumber;
    string fName;
    string fPassword;
    string fBalance;
    string fEmail;
    string fPhone;
    string fAddress;
    string fAge;

    bool loginSuccess = false;

    while (getline(file, fAccountNumber, '|'))
    {
        getline(file, fName, '|');
        getline(file, fPassword, '|');
        getline(file, fBalance, '|');
        getline(file, fEmail, '|');
        getline(file, fPhone, '|');
        getline(file, fAddress, '|');
        getline(file, fAge);

        if (inAccountNumber == fAccountNumber && inPassword == fPassword)
        {
            accountNumber = fAccountNumber;
            accountHolderName = fName;
            password = fPassword;
            balance = stod(fBalance);
            email = fEmail;
            phoneNumber = fPhone;
            address = fAddress;
            age = stoi(fAge);

            loginSuccess = true;
            break;
        }
    }

    file.close();

    if (loginSuccess)
    {

        cout << "\n--------------------------------------------\n";
        cout << "             Login Successful.......\n";
        cout << "\n--------------------------------------------\n";

        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Number : " << accountHolderName << endl;
        cout << "Balance        : " << balance << " BDT\n";
    }

    else
    {
        cout << "\nInvalid Account Number or Password!\n";
    }

    mainMenu();
};

void Bank::ourTeam()
{
    cout << "\n===========================================\n";
    cout << "                  OUR TEAM\n";
    cout << "===========================================\n";

    cout << "1. Ashik Khan  | ID: 049\n";
    cout << "2. Najmul      | ID: 075\n";
    cout << "3. Boishaki    | ID: 001\n";

    cout << "===========================================\n";

    mainMenu();
}

int main()
{
    Bank bank;
    bank.mainMenu();
    return 0;
};