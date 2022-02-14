#include<iostream>
#include <fstream>
using namespace std;

class A
{
  public:

    int X=0,Y=0,Z=0;

  public:

   void Edit(int x, int y, int z)
   {
      X=x;Y=y;Z=z;

      ofstream MyFile("XYZ.txt");
      MyFile << X << "\n" << Y << "\n" << Z << "\n" ;
      MyFile.close();
      cout << "Marks saved successfully" << endl;
      cout << "-------------------------------------------" << endl;
   }

   void View()
   {
      string myText,check;
      ifstream MyReadFile("XYZ.txt");

      cout << "(X,Y,Z) = ";

      while (getline (MyReadFile, myText)) 
      {
         cout << myText << " " ;
         check += myText;
      }

      if(check=="\0")
        {
            
            cout << "X Y Z" << endl;
            cout << "Values not assignned yet";
        }

      cout << endl;

      MyReadFile.close();
      cout << "----------------------------------------------" << endl;
   }

   void Start()
   {
      while (true)
      {
         cout << "\n Welocme Admin" << endl;
         cout << "Select one of the operations" << endl;
         cout << "Enter 1 - To VIEW \n"; 
         cout << "Enter 2 - To EDIT \n";
         cout << "Enter 3 - To LOG OUT \n\n";

         int n;
         cin >> n;

         if(n==1)
         {
            View();
         }

         if(n==2)
         {  
            cout << "Enter the values of x, y, z respectively :" << endl;
            int x,y,z;
            cin >> x >> y >> z;
            Edit(x,y,z);
         }

         if(n==3)
         {
             cout << "Logged Out Successfully" << endl;
             cout << "----------------------------------" << endl;
             break;
         }   
      }
      
   }
 
};

