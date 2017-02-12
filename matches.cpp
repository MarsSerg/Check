#include <vector>
#include <iostream>
#include <fstream>

#include "struct.h"
#include "io.h"
std::vector<Futbal> Matches;
int next_id = 0;

void free_memory()
{
    Matches.clear();
}

void savefile()
{
    string path = "./bd.txt";
    
    ofstream file;
    file.open(path);
    
    if (file.is_open())
    {
        for (Futbal one : Matches) 
        {
            file << one.id << endl;
            file << one.team1 << endl;
            file << one.team2 << endl;
            file << one.mesto << endl;
            file << one.score1 << endl;
            file << one.score2 << endl;
            if (!file) 
            {
                cout << "Error writing to file '" << path << "'" << endl;
                return;
            }
        }
        
        file.close();
        if (!file) 
        {
            cout << "Error writing to file '" << path << "'" << endl;
            return;
        }
        else
        {
            cout << "Writing to file - ready" << endl;
            
        }
    }
    else
    {
        cout << "Error writing to file '" << path << "'" << endl;
    }
    return;
}

void nullmatch(Futbal * one)
{
    one->id = 0;
    one->team1 = "";
    one->team2 = "";
    one->mesto = "";
    one->score1 = 1;
    one->score2 = 0; 
    
}

void readfile()
{
    Matches.clear();
    Futbal buf;
    string path = "./bd.txt";
    ifstream file;
    file.open(path);
    if (file.is_open())
    {
        do
        {
            file >> buf.id;
            file >> buf.team1;
            file >> buf.team2;
            file >> buf.mesto;
            file >> buf.score1;
            file >> buf.score2;
            if (buf.id != 0) 
                Matches.push_back(buf);
            
            nullmatch(&buf);
            
            
        }while (!file.eof() || buf.id!=0);
        file.close();
        cout << "Reading from file - ready" << endl;
    }
    else
    {
        cout << "Error reading from file '" << path << "'" << endl;
    }
    
}


bool read_match(Futbal* new_match)
{
    new_match->team1      = give_meaning("first team");
    new_match->team2    = give_meaning("second team");
    new_match->mesto  = give_meaning("Place");
    new_match->score1 = read_int("Score first",0,10);
    new_match->score2   = read_int("Score second",0,10);
    
    string in = give_meaning("Is data correct? (y/n)");
    return (in == "y" || in == "yes");
}

void add_match()
{
    Futbal new_match;
    
    bool confirmed = read_match(&new_match);
    
    if (confirmed) {
        new_match.id = ++next_id;
        Matches.push_back(new_match);
        cout << "Match with id " << new_match.id << " added." << endl;
    } else {
        cout << "Canceled." << endl;
    }
}

bool check_id(int id)
{
    if(id>0 && id <= next_id)
    {
        for (Futbal one : Matches) 
        {
            
            if (one.id == id)
            {
                return true;
            }
        }
    }
    return false;
}

void del_match()
{
    int id = read_match_id();
    if (check_id(id)) {
        int number = 0;
        
        for (Futbal one : Matches) 
        {
            
            cout << "   DEL CHECK ID: " << one.id << " =? " << id << endl;
            if (one.id == id)
            {
                Matches.erase(Matches.begin() + number);
                break;
            }
            number++;
        }
        
        cout << "Deleted." << endl;
    } else {
        cout << "Error. ID: " << id << endl;
    }
}

void print_matches(Futbal* one) 
{
    cout << one->team1 << " " 
         << one->team2 << " "
         << one->mesto << endl;
    
    cout << "Score " ;
    cout << one->score1<<":"<< one->score2 << endl;
 
}




void print_all()
{
    int i = 1;
    for (Futbal one : Matches)
    {
        cout << i++ << ". ";
        print_matches(&one);
        cout << endl;
    }
}

void change_matches()
{
    int id = read_match_id();
    if (check_id(id)) {
        
        Futbal new_match;
        if(read_match(&new_match) == true)
        {
            int number = 0;
            for (Futbal one : Matches) 
            {
                if (one.id == id)
                {
                    new_match.id = one.id;
                    Matches.at(number) = new_match;
                }
                number++;
            }
        }
        cout << "Saved." << endl;
    } else {
        cout << "Error." << endl;
    }
}