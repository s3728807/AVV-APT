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
