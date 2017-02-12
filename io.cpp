#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

string give_meaning(string& info)
{
    string s;
    cout << info << " > ";
    cin >> s;
    return s;
}

int read_int(string& caption, int min, int max)
{
    int chislo = min;
    do
    {
        if (chislo>max || chislo <min) cout << "Number must be between " << min << " and " << max << endl;
        
        string s;
        cout << caption;
        cin >> s;
        chislo = atoi(s.c_str());
    }
    while(chislo>max || chislo <min);
    
    return chislo;
}



int read_match_id()
{
    int chislo = 0;
    string s;
    cout << "Enter id > ";
    cin >> s;
    chislo = atoi(s.c_str());
    return chislo;
}