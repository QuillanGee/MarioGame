// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Class for the game piece, Boss
// Used for Mario vs. Boss interaction

#include "Boss.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Boss::Boss(){ // constructor
}

Boss::~Boss(){ // destructor
}

bool Boss::bossWon(){
  int x = rand()%100;
  // cout << "This is the number for boss: "<< x << endl;
  // 50% chance mario wins
  if ((x >= 0) && (x < 50)){
    bossWin = false;
    // 50% chance mario loses
  } else if ((x >= 50) && (x < 100)){
    bossWin = true;
  }
  return bossWin;
}
