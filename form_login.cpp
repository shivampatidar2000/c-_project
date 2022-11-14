#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;
void login();
void registration();
void forget();

int main()
{
    int c;
    cout << "\t\t\t_______________________________________________________\n\n\n";
    cout << "\t\t\t                Welcome to the login page               \n\n\n";
    cout << "\t\t\t________________         Menu         __________________\n\n\n";
    cout << "                                                                    \n";

    cout << "\t Press 1 to LOGIN                        |" << endl;
    cout << "\t Press 2 to RGISTRATION                  |" << endl;
    cout << "\t Press 3 to if you forget you PASSWORD   |" << endl;
    cout << "\t Press 4 to EXIT                         |" << endl;

    cout << "\n\t\t\t Please Enter your choise : ";
    cin >> c;

    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forget();
        break;
    case 4:
        cout << "\t\t\t Thankyou!  \n\n";
        break;

    default:
        system("cls"); // we can execute any command that can run on terminal if operating system allows
        cout << "\t\t\t Please select from the options given obove \n\n";
        main();
    };
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please Enter the the username and password : " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userId;
    cout << "\t\t\t PASSWORD ";
    cin >> password;
    // ifstream is used to read and write in the file the
    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << userId << "\n Your LOGIN is successfull \n Thanks for logging in ! \n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR \n please check your username and password \n";
        main();
    }
}

void registration()
{
    string ruserId, rPassword, rId, rPass;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password : ";
    cin >> rPassword;

    // we want to write inside the file so ofstream help us with that
    // ios is input, output stream and App will open the file and append the output of the end
    ofstream f1("records.txt", ios::app);
    f1 << ruserId << " " << rPassword << endl;
    system("cls");

    cout << "\n\t\t\t Registration is Successfull \n";
    main(); // we used main() because control back to the main function
}

void forget()
{
    int option;
    system("cls");
    cout << "\t\t\t You Forget the password? No worries \n";
    cout << "\t\t\t Press 1 to search your id by username " << endl;
    cout << "\t\t\t Press 2  to go to main menu " << endl;
    cout << "\t\t\t Enter your choice : ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string sUserid, sId, sPass;
        cout << "\t\t\t Enter the user which you remembered : ";
        cin >> sUserid;

        ifstream f2("records.txt");
        while (f2 >> sId >> sPass)
        {
            if (sId == sUserid)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your Accout is found! \n";
            cout << "\n\n your Password is : " << sPass;
            main();
        }
        else
        {
            cout << "\n\t Sorry! your account is not found! \n";
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }

    default:
        cout << "\t\t\t Worng choice ! Please try again " << endl;
        forget();
    }
}