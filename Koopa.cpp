// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Class for the game piece, Koopa Troopa
// Used for Mario vs. Koopa interaction

#include "Koopa.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Koopa::Koopa(){ // constructor
}

Koopa::~Koopa(){// destructor
}

/*
a. koopaWon - facilitates Mario vs Koopa interaction
b. returns a boolean, koopaWin, if Koopa won or not
c. no parameters taken
d. no known exeptions thrown
*/

bool Koopa::koopaWon(){
  int x = rand()%100;
  // cout << "This is the number for koopa: "<< x << endl;
  // 65% chance mario wins
  if ((x >= 0) && (x < 65)){
    koopaWin = false;
    // 35% chance mario loses
  } else if ((x >= 65) && (x < 100)){
    koopaWin = true;
  }
  return koopaWin;
}
