// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Class for the game piece, Goomba
// Used for Mario vs. Goomba interaction

#include "Goomba.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Goomba::Goomba(){ // constructor
}

Goomba::~Goomba(){ // destructor
}


/*
a. goombaWon - facilitates Mario vs Goomba interaction
b. returns a boolean, goombaWin, if Goomba won or not
c. no parameters taken
d. no known exeptions thrown
*/
bool Goomba::goombaWon(){
  int x = rand()%100;
  // cout << "This is the number for goomba: "<< x << endl;
  // 80% chance mario wins
  if ((x >= 0) && (x < 80)){
    goombaWin = false;
    // 20% chance mario loses
  } else if ((x >= 80) && (x < 100)){
    goombaWin = true;
  }
  return goombaWin;
}
