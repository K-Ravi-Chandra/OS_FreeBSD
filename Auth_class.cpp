#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include "Admin_class.cpp"
#include "H_S_F_class.cpp"
using namespace std;

class Authentication
{
public:
   vector<vector<string>> authfile;
   char roles[4];
   void import_data()
   {
      authfile.clear();
      string myText;
      ifstream MyReadFile("Authentication.team_10");
      int i_role = 0;
      while (getline(MyReadFile, myText))
      {

         // cout << myText << endl;
         vector<string> temp;
         int pk = myText.length();
         // cout << pk << endl;
         int start = 0, end;
         string token = "";
         for (int pkp = 0; pkp < 8; pkp++)
         {
            token.push_back(myText[pkp]);
         }
         temp.push_back(token);
         string temp_1 = "";
         for (int hl = 9; hl < 15; hl++)
            temp_1.push_back(myText[hl]);
         // cout << temp_1 << endl;
         temp.push_back(temp_1);
         char tp = myText[16];
         roles[i_role] = tp;
         i_role++;
         authfile.push_back(temp);
         // cout << tp << endl;
         // cout << temp[1].length() << endl;
      }
      MyReadFile.close();
      //cout << authfile[1][0] << endl;
   }

   void validate(string iid, string passs)
   {
      A a;
      V v;
      int flag = 0;
      for (int p = 0; p < 4; p++)
      {
         if (authfile[p][0] == iid)
         {
            flag = 1;
            if (authfile[p][1] == passs)
            {
               if (roles[p] == 'A')
                  a.Start();
               else
                  v.Start(roles[p]);
            }
            else
            {
               cout << "Credentials Invalid" << endl;
               break;
            }
            //cout << "Yup" << endl;
            
            break;
         }
      }
      if (flag == 0)
      {
         cout << "Credentials Invalid" << endl;
      }
   }
};

int main()
{

   Authentication auth;
   auth.import_data();
   while (true)
   {
      cout << "Select one of the operation" << endl;
      cout << "Enter 1 to login" << endl;
      cout << "Enter 2 to close the application" << endl;
      int option;
      cin >> option;
      if (option == 1)
      {
         string id, pass;
         cout << "Enter the collegeID :" << endl;
         cin >> id;
         cout << "Enter the password :" << endl;
         cin >> pass;
         auth.validate(id, pass);
      }
      else if(option == 2)
      {
         cout << "***Application Closed successfully***" << endl;
         break;
      }
      else
        cout << "No such option exist" << endl;
      cout << "-------------------------------------------------------" << endl;
   }
}
