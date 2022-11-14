#include <iostream>
#include <string>
using namespace std;
float pi = 3.14;
class Car
{
    string color;
    float weight;
    string brand;

public:
    bool is_on = false;
    void turn_on()
    {
        if (is_on == true)
        {
            cout << "Car is already on " << endl;
        }
        else
        {
            is_on = true;
            cout << "car Turn on " << endl;
        }
    }

    void turn_Right()
    {
        if (is_on == false)
        {
            cout << "Car is not turned on " << endl;
        }
        else
        {
            cout << "Turning Rigth" << endl;
        }
    }
    void turn_Left()
    {
        if (is_on == false)
        {
            cout << "Car is not turned on " << endl;
        }
        else
        {
            cout << "Turning Left" << endl;
        }
    }

    void Accelerate()
    {
        if (is_on == false)
        {
            cout << "Car is not turned on " << endl;
        }
        else
        {
            cout << "Accelerating" << endl;
        }
    }
    void Reverse()
    {
        if (is_on == false)
        {
            cout << "Car is not turned on " << endl;
        }
        else
        {
            cout << "Reversing" << endl;
        }
    }
    void turn_Off()
    {
        if (is_on == false)
        {
            cout << "Car is already turnei off " << endl;
        }
        else
        {
            is_on == false;
        }
    }
   
};
int main()
{
    Car car1;
    int user_input = 0;
    while (user_input != 7)
    {
        cout << "Press 1 ro start the Car\nPress 2 ro Turn Right\nPress 3 to Turn Left\n"
             << "Press 4 to Accelerate\nPress 5 to Reverse\nPress 6 to Turn off the Car\nPress 7 exit\n";
        cin>>user_input;
        switch(user_input)
        {
            case 1:car1.turn_on();
            break;
              case 2:car1.turn_Right();
            break;
              case 3:car1.turn_Left();
            break;
              case 4:car1.Accelerate();
            break;
              case 5:car1.Reverse();
            break;
              case 6:car1.turn_Off();
            break;
            case 7:if(car1.is_on==false)
            {
                break;
            }
            else
            {
                cout<<"The Car is still on! "<<endl;
                break;
            }
            default: 
            {
                cout<<"Invalid Input";
            }
        }
    }
    // cout<<car2.color<<endl;
    return 0;
}