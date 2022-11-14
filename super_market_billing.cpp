

// super market billing
#include <iostream>
// #include <operator.h>
#include <fstream>
#include <string.h>
using namespace std;

class Billing
{
private:
    int pcode;
    float price;
    float dis;
    float pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void Billing ::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t__________________________________________\n";
    cout << "\t\t\t                                          \n";
    cout << "\t\t\t           SuperMarket main menu          \n";
    cout << "\t\t\t                                          \n";
    cout << "\t\t\t__________________________________________\n";
    cout << "\t\t\t                                          \n";

    cout << "\t\t\t| 1) Administrator   |\n ";
    cout << "\t\t\t                     |\n ";
    cout << "\t\t\t| 2)     Buyer       |\n ";
    cout << "\t\t\t                     |\n ";
    cout << "\t\t\t| 3)     Exit        |\n ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please login \n";
        cout << "\t\t\t Enter email   \n";
        cin >> email;
        cout << "\t\t\t password      \n ";
        cin >> password;
        if (email == "shivam@email.com" && password == "shivam@123")
        {
            cout<<"\t\tlogin Successfully\n";
            administrator();
        }
        else
        {
            cout << "Invalid email / password";
        }
        break;
    case 2:
    {
        buyer();
        break;
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please select the given options ";
    }
    }
    goto m;
}
void Billing ::administrator()
{
m:
    int choice;

    cout << "\n\n\n\t\t\t Administartor menu ";
    cout << "\n\t\t\t_____1) Add the product____|";
    cout << "\n\t\t\t_____2) Modify the product_|";
    cout << "\n\t\t\t_____3) Delete the product_|";
    cout << "\n\t\t\t_____4) Back to main menu__|";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid choice!";
    }
    goto m;
}
void Billing ::buyer()
{
m:
    int choice;
    cout << "\t\t\t Buyer \n";
    cout << "\t\t\t_______________ \n";
    cout << "                      \n";
    cout << "\t\t\t 1) buy product \n";
    cout << "                      \n";
    cout << "\t\t\t 2) Go Back     \n";
    cout << "\t\t\t Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        cout << "Invalid choice";
    }
    goto m;
}

void Billing ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Add new product ";
    cout << "\n\n\t Product code of the product ";
    cin >> pcode;
    cout << "\n\n\t Name of the product ";
    cin >> pname;
    cout << "\n\n\t Price of the product ";
    cin >> price;
    cout << "\n\n\t Discount of the product ";
    cin >> dis;
    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
        }
    }
    cout << "\n\n\t\t Record inserted ! ";
}

void Billing ::edit()
{
m:
    fstream data, data1;
    int c;
    string n;
    float p;
    float d;
    int token = 0;
    int pkey;
    cout << "\n\t\t Modify the record";
    cout << "\n\t\t product code ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n file dosen't exist! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data1 >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product New code ";
                cin >> c;
                cout << "\n\t\t Product new name ";
                cin >> n;
                cout << "\n\t\t Product new price ";
                cin >> p;
                cout << "\n\t\t Porduct new discound ";
                cin >> d;
                data1 << " " << c << " " << n << " "
                      << " " << p << " " << d << endl;
                cout << "\n\n\t\tRecord edited ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Sorry! Record not found \n";
        }
    }
}

void Billing ::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File dosen't exist ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }

            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n\t Recode not found";
        }
    }
}

void Billing::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_______________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n_________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void Billing::receipt()
{
m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout << "\n_____________________________\n";
        cout << "\n|                            \n";
        cout << "    please place the order     \n";
        cout << "\n|                            \n";
        do
        {
            cout << "\n\n Enter the product code ";
            cin >> arrc[c];
            cout << "\n\n Enter tne product name ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to another project? if yes then press Y else no ";
            cin >> choice;
        }while (choice == 'y');
        
            cout << "\n\n\t\t\t______________RECEIPT_______________\n";
            cout << "\n\n Product No.\t Product Name\tProduct quantity\tPrice\tAmount with discount\n";
            for (int i = 0; i < c; i++)
            {
                data.open("database.txt", ios::in);
                data >> pcode >> pname >> price >> dis;
                while (data.eof())
                {
                    if (pcode == arrc[i])
                    {
                        amount = price * arrq[i];
                        dis = amount - (amount * dis / 100);
                        total = total + dis;
                        cout << "\n"
                             << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                    }
                    data >> pcode >> pname >> price >> dis;
                }
            }
            data.close();
        
    }
    cout << "\n\n______________________________";
    cout << "\n Total Amount : " << total;
}

int main()
{
 
  Billing b;
  b.menu();
//   b.administrator();

  
    return 0;
}

