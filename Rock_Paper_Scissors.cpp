#include <iostream>
#include <random>
#include <cmath>
#include <fstream>
#include <deque>


using namespace std;

bool is_file_exist(string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}
void save(int w,int l,int d){
    deque<int> statsf = {w,l,d};
    ofstream file("stats.txt");
    for(int statf: statsf){
        file << statf << endl;
    }
    file.close();
}

int rng(int rmin, int rmax){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(rmin, rmax);
    int ran = dist(gen);
    return ran;
}
string choicename(int choicenum)
{
    string name;
    switch (choicenum)
    {
    case 1:
        name = "Rock";
        break;
    case 2:
        name = "Paper";
        break;
    case 3:
        name = "Scissors";
        break;
    default:
        break;
    }
    return name;
}

void game()
{
    int p;
    int min;
    int max;
    int c = rng(1,3);
    int result;
    int i;
    int wins;
    int loses;
    int draws;
    if(is_file_exist("stats.txt")){
        deque<int> stats;
        ifstream file("stats.txt");
        int stat;
        while(file >> stat){
            stats.push_back(stat);
        }
        file.close();
        wins = stats[0];
        loses = stats[1];
        draws = stats[2];
    } else {
        wins = 0;
        loses =0;
        draws = 0;
    }
    while(true){
        cout << "Chose either\n 1) Rock\n 2) Paper\n 3) Sissors\n";
        cin >> p;
        if(p >= 1 && p <= 3) {
            break;
        } else {
            cout << "Invalid choice try again" <<endl;
        }
    }
    min = fmin(p,c);
    max = fmax(p,c);
    if(p == 1){
        result = max - min;
    } else {
        result = min - max ;
    }
    switch (result)
    {
    case 0:
        cout << "The Computer chose: " << choicename(c) << endl;
        cout << "You Chose: " << choicename(p) << endl;
        cout << "You Draw" << endl;
        draws++;
        break;
    case 1:
        cout << "The Computer chose: " << choicename(c) << endl;
        cout << "You Chose: " << choicename(p) << endl;
        cout << "You Lose" << endl;
        loses++;
        break;
    case 2:
        cout << "The Computer chose: " << choicename(c) << endl;
        cout << "You Chose: " << choicename(p) << endl;
        cout << "You Win" << endl;
        wins++;
        break;
    case -1:
        cout << "The Computer chose: " << choicename(c) << endl;
        cout << "You Chose: " << choicename(p) << endl;
        cout << "You Win" << endl;
        wins++;
        break;
    case -2:
        cout << "The Computer chose: " << choicename(c) << endl;
        cout << "You Chose: " << choicename(p) << endl;
        cout << "You Lose" << endl;
        loses++;
        break;
    default:
        break;
    }
    save(wins,loses,draws);
}
void statscreen(){
    cout << "Here are your statistics\n";
    deque<int> stats;
    ifstream file("stats.txt");
    int stat;
    while(file >> stat){
        stats.push_back(stat);
    }
    file.close();
    cout << "You have Won:" << stats[0] << " times." << endl;
    cout << "You have Lost:" << stats[1] << " times." << endl;
    cout << "You have Drew:" << stats[2] << " times." << endl;
}
int main(){
    cout << "Would you like to play a game (y/n): " ;
    string choice;
    cin >> choice ;
    string choice2;
    int choice3;
    do{
        if(choice == "y"){
        cout << "Play game (1)" << endl;
        cout << "Get Statisitics (2)" << endl;
        cin >> choice3;
            if(choice3 == 1){
                game();
            } else {
                statscreen();
            }
        } else {
        break;
        }   
        cout << "Play again (y/n): ";
        cin >> choice2;
    } while(choice2 != "n");
    cout << "GoodBye" << endl ;
    system("pause");
    return 0;
}