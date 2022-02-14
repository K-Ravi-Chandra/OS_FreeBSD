#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class V
{

public:
    string data[3] = {"-", "-", "-"};

    void Start(char user)
    {

        string myText;
        ifstream MyReadFile("XYZ.txt");

        int i = 0;
        while (getline(MyReadFile, myText))
        {
            data[i++] = myText;
        }

        MyReadFile.close();

        while (true)
        {
            cout << "\nWelcome ";
            if (user == 'S')
                cout << "Student " << endl;
            else if (user == 'F')
                cout << "Faculty" << endl;
            else
                cout << "HOD" << endl;
            cout << "Select one of the operation" << endl;
            cout << "\nEnter 1 - To VIEW \n";
            cout << "Enter 2 - To LOG OUT \n\n";

            int n;
            cin >> n;

            if (n == 1)
            {
                Show(user);
            }

            else if (n == 2)
            {
                cout << "***Logged out successfully" << endl;
                cout << "----------------------------------" << endl;
                break;
            }
            else
            {
                cout << "***Invaild Option !\n\n";
            }
        }
    }

    void Show(char user)
    {

        // cout << user << endl;
        if (user == 'S')
        {
            cout << "Marks :" << endl;
            cout << data[0] << "  --  --\n";
        }
        else if (user == 'F')
        {
            cout << "Marks :" << endl;
            cout << "--  " << data[1] << "  --\n";
        }
        else if (user == 'H')
        {
            cout << "Marks :" << endl;
            cout << data[0] << "  " << data[1] << "  " << data[2] << endl;
        }
        cout << "-----------------------------------" << endl;
    }
};
