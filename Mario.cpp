// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Holds methods and variables pertaining to Mario such as
// lifves, coins, power level, and wins

#include "Mario.h"

Mario::Mario(){ // constructor
  coin = 0;
  power = 0;
  marioWs = 0;
  currLevel = 0;
}

Mario::~Mario(){ // destructor
}

Mario::Mario(int lives){ // overloaded constructor
  livesLeft = lives;
  coin = 0;
  power = 0;
  marioWs = 0;
  currLevel = 1;
}

// life methods
/*
a. getLives - gets number of lives Mario has
b. returns int, livesLeft
c. no parameters taken
d. no known exeptions thrown
*/

int Mario::getLives(){
  return livesLeft;
}

/*
a. addLife, subLife - adds or subtracts a life from Mario
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void Mario::addLife(){
  livesLeft += 1;
}

void Mario::subLife(){
  livesLeft -= 1;
}

// coin methods
/*
a. getCoin - gets number of coins Mario has
b. returns int, coin
c. no parameters taken
d. no known exeptions thrown
*/
int Mario::getCoin(){
  return coin;
}

/*
a. addCoin, subCoin - adds or subtracts Mario's coins
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void Mario::addCoin(){
  coin += 1;
}

void Mario::subCoin(){
  coin -= 1;
}

// power level methods
/*
a. setPL - sets Mario's power level
b. returns void
c. takes in int i to set power level
d. no known exeptions thrown
*/
void Mario::setPL(int i){
  power = i;
}

/*
a. getPL - gets Mario's power level
b. returns int, power
c. no parameters taken
d. no known exeptions thrown
*/
int Mario::getPL(){
  return power;
}

/*
a. addPL, subPL - adds or subtracts a power level from Mario
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void Mario::addPL(){
  power += 1;
}

void Mario::subPL(){
  power -= 1;
}

// mario win methods
/*
a. setWs - sets Mario's wins against an enemy
b. returns void
c. takes in int i to set wins
d. no known exeptions thrown
*/
void Mario::setWs(int i){
  marioWs = i;
}

/*
a. getWs - gets Mario's wins against an enemy
b. returns int, marioWs
c. no parameters taken
d. no known exeptions thrown
*/
int Mario::getWs(){
  return marioWs;
}

/*
a. addW - adds win when Mario wins against an enemy
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void Mario::addW(){
  marioWs += 1;
}

/*
a. checkW - checks how many wins Mario has to decide whether
    a life should be added
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/
void Mario::checkW(){
  if(marioWs == 7){
    livesLeft +=1;
    marioWs = 0;
  }
}

/*
a. getLevel - gets the current level Mario is on
b. returns an int, currLevel
c. no parameters taken
d. no known exeptions thrown
*/
int Mario::getLevel(){
  return currLevel;
}
