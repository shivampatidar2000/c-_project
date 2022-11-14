#include<iostream>
using namespace std;
class Library{
    private:
    int id;
    char name[100];
    char author[100];
    char student[100];
    int price;
    int pages;
    public:
    void setdata()
    {
          cout << "Enter Book id ";
            cin >> id;
            cout << "Enter the name ";
            cin >> name;
            cout << "Enter book Author ";
            cin >> author;
            cout << "Enter Student ";
            cin >> student;
            cout << "Enter book price ";
            cin >> price;
            cout << "Enter book pages ";
            cin >> pages;
    }
    void display()
    {
        cout << "Book id : " << id << endl;
                cout << "Book name : " << name << endl;
                cout << "Book author : " << author << endl;
                cout << "Book get student : " << student << endl;
                cout << "Book price : " << price << endl;
                cout << "Book pages: " << pages << endl;
    }
};
int main()
{
    Library lab[20];
    int input = 0;
    int count = 0;

    while(input !=3)
    {
        cout<<"Enter 1 to input like id, name, author, student, price, pages "<<endl;
        cout<<"Enter 2 to display book details "<<endl;
        cout<<"Enter 3 to quit "<<endl;
        cin>> input;
        switch(input)
        {
            case 1:
            start:
            lab[count].setdata();
            count++;
            break;
            case 2:
            for(int i = 0; i<count; i++)
            {
                lab[count].display();
            }
            break;
            case 3:
             exit(0);
             break;
             default :
            cout << "You have Entered wrong value, please type again" << endl;
             goto start;
        }
    }


  return 0;
}