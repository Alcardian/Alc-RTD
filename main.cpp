#include <cstdlib>
#include <iostream>
#include <ctime>   //for rand
#include <string>

#include "alctools.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));     //to be able to get random numbers
    int r[3];           // r0 = lowest number, r1 = highest number, r2 = r1-r0
    int o=0;
    string temp = "";
    alctools alc;
    bool check = false;
    
    while(true)
    {
              o=0;
              cout << "Alcardian's RTD" << endl;
              
              while(check == false)
              {
                          cout << "Choose the lowest value: ";
                          cin >> temp;
                          check = alc.isnumber(temp);
              }
              r[0] = alc.stringtonumber(temp);
              check = false;
              
              while(check == false)
              {
                          cout << "Choose the highest value: ";
                          cin >> temp;
                          check = alc.isnumber(temp);
              }
              r[1] = alc.stringtonumber(temp);
              r[2] = r[1] - r[0];
              
              cout << endl << "You Choose " << r[0] << " as lowest and " << r[1] << " as highest." << endl;
              cout << "You rolled the dice and you got: " << rand()%r[2]+r[0] << "." <<endl << endl;
              
              cout << "Do you want to Roll The Dice agian?(yes=1,no=0): ";
              temp = "";
              cin >> temp;
              if(alc.isnumber(temp))
              {
                                   o = alc.stringtonumber(temp);
                                   if(o == 0)
                                   {
                                        return EXIT_SUCCESS;
                                   }
              }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
