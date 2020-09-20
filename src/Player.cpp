#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
  private:
    string name;



public :
    string getName() {
      return name;
    }
    void setName(string playername) {
      name=playername;
    }
};

int main() {

string p1name;
string p2name;
Player player1;
Player player2;
cout << "Enter player 1's name ";
cin >> p1name;
player1.setName(p1name);

cout << "Enter player 2's name ";
cin >> p2name;
player2.setName(p2name);


cout << "Player 1's name is " << p1name;
cout << " and ";
cout << "Player 2's name is " << p2name;

};

