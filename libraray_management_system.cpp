#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Library
{
public:
    int id;
    char name[100];
    char author[100];
    char student[100];
    int price;
    int pages;
};
int main()
{
    Library lib[20];
    int input = 0;
    int count = 0;
    while (input != 3)
    {
        cout << "Enter 1 to input details like id, name, author, student, price, pages " << endl;
        cout << "Enter 2 to display details " << endl;
        cout << "Enter 3 to quit " << endl;
        cin>>input;
        switch (input)
        {
        case 1:
        start:
            // lib[count].setdata();
            cout << "Enter Book id";
            cin >> lib[count].id;
            cout << "Enter the book name ";
            cin >> lib[count].name;
            cout << "Enter book Author";
            cin >> lib[count].author;
            cout << "Enter Student ";
            cin >> lib[count].student;
            cout << "Enter book price ";
            cin >> lib[count].price;
            cout << "Enter book pages ";
            cin >> lib[count].pages;
            count++;
            break;
        case 2:
            for (int i = 0; i < count; i++)
            {
                cout << "Book id : " << lib[i].id << endl;
                cout << "Book name : " << lib[i].name << endl;
                cout << "Book author : " << lib[i].author << endl;
                cout << "Book get student : " << lib[i].student << endl;
                cout << "Book price : " << lib[i].price << endl;
                cout << "Book pages: " << lib[i].pages << endl;
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "You have Entered wrong value, please type again" << endl;
            goto start;
        }
    }
    return 0;
}