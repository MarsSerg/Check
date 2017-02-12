

#include <string>
#include <iostream>
#include <vector>

#include "matches.h"

using namespace std;



int main()
{
    bool ext = false;
    string s = "";
    do
    {
        cout << ">"; cin >> s;
        if     (s == "!add") { add_match(); }
        else if(s == "!del") { del_match(); }
        else if(s == "!chg") { change_matches(); }
        else if(s == "!prt") { print_all(); }
        else if(s == "!frd") { readfile();}
        else if(s == "!fwr") { savefile();}
        else if(s == "!ext") { ext = true;}
        else {cout << "Wrong argement" << endl;}
    }
    while(!ext);
    
    free_memory();
    
    return 0;
}
