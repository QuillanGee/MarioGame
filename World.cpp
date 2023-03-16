// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Creates world using game specs provided at runtime and assigned in main
// Contains all main game methods to facilitate gameplay

#include "World.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Boss.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h> // for sleep


using namespace std;

// default constructor
World::World(){

}

// destructor
World::~World(){

}

// overloaded constructor
// creates World with given game parameters from file, read in main
World::World(int numLevels,int numGrid,int lives, int coins, int nothingPer, int goombaPer, int koopasPer, int mushroomPer){
  // assign params to member vars
  my_numLevels = numLevels;
  my_numGrid = numGrid;
  my_lives = lives;
  my_coins = coins;
  my_nothingPer = nothingPer;
  my_goombaPer = goombaPer;
  my_koopasPer = koopasPer;
  my_mushroomPer = mushroomPer;

  marioLevel = 0;
  gameOver = false;
  levelOver = false;
  didBossWin = false;
  battleWon = true;

  my_grid = new char** [my_numLevels];
  myMario = new Mario(my_lives);

  // create NxN array with appropriate number of levels
  for (int i = 0;i<my_numLevels;i++){
    // create memory blocks for rows of each 2D array
    my_grid[i] = new char*[my_numGrid];
    for(int j = 0;j<my_numGrid;j++){
      // create memory blocks for columns of each 2D array
      my_grid[i][j] = new char[my_numGrid];
    }
  }
}


/*
a. populateGrid - populates NxN grid with game specs given in main
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void World::populateGrid(){
  // assign item to each element in array
  for (int l = 0; l<my_numLevels; ++l) { // levels
    for (int r = 0; r < my_numGrid; ++r) { // rows
      for (int c = 0; c <my_numGrid; ++c) { // columns
        my_grid[l][r][c] = getRandItem();
      }
    }
  }
  // place boss and warp pipe
  for (int l = 0; l<my_numLevels; ++l){
    sleep(1); // for random placements
    placeBoss(l);
    placeWarpPipe(l);
  }
}

/*
a. printGrid - prints NxN grid after populated with game pieces
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void World::printGrid(){
  // prints grid
  for (int l = 0; l<my_numLevels; ++l) { // levels
    for (int r = 0; r < my_numGrid; ++r) { // rows
      for (int c = 0; c <my_numGrid; ++c) { // columns
        cout << my_grid[l][r][c] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  cout << "===============" << endl;
}

/*
a. printLevel - prints NxN grid of 1 level
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void World::printLevel(){
  // prints grid of level
  cout << "===============" << endl;
  for (int r = 0; r < my_numGrid; ++r) {
    for (int c = 0; c < my_numGrid; ++c) {
      cout << my_grid[marioLevel][r][c] << " ";
    }
    cout << endl;
  }
  printStats();
}

/*
a. printStats - prints current stats after every NxN level grid is printed
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void World::printStats(){
  cout << "===============" << endl;
  cout << "Level: " << marioLevel+1 << ". " << "Mario is at position: " << newRow << ", " << newCol << ". " << "Num Lives: " << myMario -> getLives() << ". " << "Coins: " << myMario -> getCoin() << ". " << "Power Level: " << myMario -> getPL() << ". " << "Number of Wins: " << myMario -> getWs() << endl;
  cout << endl;
}

/*
a. getRandItem - gets a random item (coin, nothing, goomba, koopa, or mushroom)
    according to % in game specs file. warp pipe and boss are placed after.
b. returns a char c, representing the random game piece item that is randomly chosen
    used in populateGrid() to populate each level randomly
c. no parameters taken
d. no known exeptions thrown
*/

char World::getRandItem(){
  char c;
  sleep(1);
  srand(time(0));
  int x = rand() % 100; // 0-99
  if (x<my_coins){ // coin
    c = 'c';
  }else if (x<(my_nothingPer+my_coins)){ // nothing
    c = 'x';
  }else if (x<(my_nothingPer+my_coins+my_goombaPer)){ // goomba
    c = 'g';
  }else if (x<(my_nothingPer+my_coins+my_goombaPer+my_koopasPer)){ // koopa
    c = 'k';
  }else if (x<(my_nothingPer+my_coins+my_goombaPer+my_koopasPer+my_mushroomPer)){ // mushroom
    c = 'm';
  }
  return c;
}

/*
a. placeMario - places Mario randomly in NxN grid
    also used for when Mario advances a level
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void World::placeMario(){
  sleep(1);
  marioColStart = rand() % my_numGrid; // get random starting column position
  marioRowStart = rand() % my_numGrid; // get random starting row position
  // if a boss or warp pipe is there, choose a different spot
  while(((randomColWarpPipe == marioColStart) && (marioRowStart == randomRowWarpPipe)) || ((randomColBoss == marioColStart) && (marioRowStart == randomRowBoss))){
    marioColStart = rand() % my_numGrid;
    marioRowStart = rand() % my_numGrid;
  }
  // assign Mario to his new spot
  newRow = marioRowStart;
  newCol = marioColStart;
  my_grid[marioLevel][marioRowStart][marioColStart] = 'H';
  cout << "Placed Mario at col: " << marioColStart << " row: " << marioRowStart << endl;
}

/*
a. placeBoss - places Boss randomly in NxN grid
b. returns void
c. takes int level, representing the level the Boss should be placed in
d. no known exeptions thrown
*/

void World::placeBoss(int level){
  srand(time(0));
  randomColBoss = rand() % my_numGrid;
  randomRowBoss = rand() % my_numGrid;
  my_grid[level][randomRowBoss][randomColBoss] = 'b';
}

/*
a. placeBoss - places Warp Pipe randomly in NxN grid
b. returns void
c. takes int level, representing the level the Warp Pipe should be placed in
d. no known exeptions thrown
*/

void World::placeWarpPipe(int level){
  srand(time(0));
  if(level!=my_numLevels-1){ // put warp pipe in all but last level
    randomColWarpPipe = rand() % my_numGrid;
    randomRowWarpPipe = rand() % my_numGrid;
    // make sure a warp pipe doesnt replace a boss
    while((randomColBoss == randomColWarpPipe) && (randomRowWarpPipe == randomRowBoss)){
      randomColWarpPipe = rand() % my_numGrid;
      randomRowWarpPipe = rand() % my_numGrid;
    }
    my_grid[level][randomRowWarpPipe][randomColWarpPipe] = 'w';
  }
}

/*
a. Move - randomly selects a direction for Mario to move
    Calls function of that direction if chosen
b. returns void
c. no parameters taken
d. no known exeptions thrown
*/

void World::Move(){
  x = rand()%4;
  prevRow = newRow;
  prevCol = newCol;

  if (x == 0){ // UP
    cout << "Mario will move UP" << endl;
    MoveUp(marioLevel,prevRow);
  } else if (x == 1){ // DOWN
    cout << "Mario will move DOWN" << endl;
    MoveDown(marioLevel,prevRow);
  } else if (x == 2){ // LEFT
    cout << "Mario will move LEFT" << endl;
    MoveLeft(marioLevel,prevCol);
  } else if (x == 3){ // RIGHT
    cout << "Mario will move RIGHT" << endl;
    MoveRight(marioLevel,prevCol);
  }
}


/*
a. MoveUp - moves Mario up 1 block in NxN grid
b. returns void
c. takes in int level (level that Mario is on)
   & int my_prevRow (previous row that Mario is moving FROM)
d. no known exeptions thrown
*/

void World::MoveUp(int level,int my_prevRow){
  // if mario is at top most row already, wrap to bottom most row
  if(my_prevRow==0){
    newRow = my_numGrid-1;
  }
  // else, move mario up 1 row
  else{
    newRow -=1;
  }
  objectAt(my_grid[level][newRow][prevCol]); // check object at new Mario position

  //checks if battle has been won
  if(battleWon == true){
    my_grid[level][prevRow][prevCol] = 'x';
    prevRow = newRow;
    my_grid[level][newRow][prevCol] = 'H';

  //if it hasn't been won we stay at our current spot,
  //and revert the newCol back to the original
  }else{
    newRow = my_prevRow;
  }
  battleWon = true;
}

/*
a. MoveDown - moves Mario down 1 block in NxN grid
b. returns void
c. takes in int level (level that Mario is on)
   & int my_prevRow (previous row that Mario is moving FROM)
d. no known exeptions thrown
*/

void World::MoveDown(int level, int my_prevRow){
  // if mario is at bottom most row already, wrap to top most row
  if(my_prevRow==(my_numGrid-1)){
    newRow = 0;
  }
  // else, move mario down 1 row
  else{
    newRow +=1;
  }
  objectAt(my_grid[level][newRow][prevCol]);

  if(battleWon == true){
    my_grid[level][prevRow][prevCol] = 'x';
    prevRow = newRow;
    my_grid[level][newRow][prevCol] = 'H';

  }else{
    newRow = my_prevRow;
  }
  battleWon = true;
}

/*
a. MoveRight - moves Mario right 1 block in NxN grid
b. returns void
c. takes in int level (level that Mario is on)
   & int my_prevCol (previous column that Mario is moving FROM)
d. no known exeptions thrown
*/

void World::MoveRight(int level, int my_prevCol){
  // if mario is at right most column already, wrap to left most column
  if(my_prevCol==(my_numGrid-1)){
    newCol = 0;
  }
  // else, move mario right 1 column
  else{
    newCol +=1;
  }
  objectAt(my_grid[level][prevRow][newCol]);

  if(battleWon == true){
    my_grid[level][prevRow][prevCol] = 'x';
    prevCol = newCol;
    my_grid[level][prevRow][newCol] = 'H';

  }else{
    newCol = my_prevCol;
  }
  battleWon = true;
}

/*
a. MoveLeft - moves Mario left 1 block in NxN grid
b. returns void
c. takes in int level (level that Mario is on)
   & int my_prevCol (previous column that Mario is moving FROM)
d. no known exeptions thrown
*/

void World::MoveLeft(int level, int my_prevCol){
  // if mario is at left most column already, wrap to right most column
  if(my_prevCol==0){
    newCol = my_numGrid-1;
  }
  // else, move mario left 1 column
  else{
    newCol -=1;
  }
  objectAt(my_grid[level][prevRow][newCol]);

  if(battleWon == true){
    my_grid[level][prevRow][prevCol] = 'x';
    prevCol = newCol;
    my_grid[level][prevRow][newCol] = 'H';

  }else{
    newCol = my_prevCol;
  }
  battleWon = true;
}

/*
a. objectAt - checks the game piece/object at the NEW location Mario is moving to
    and deals with that game piece accordingly by calling appropriate method
b. returns void
c. takes in char gamePiece (the game piece in the spot Mario is moving to)
d. no known exeptions thrown
*/

void World::objectAt(char gamePiece){
  if (gamePiece == 'c'){ // coin
    // add coin to mario
    cout << "Mario collected a coin. " << endl;
    myMario -> addCoin();

  } else if (gamePiece == 'm'){ // mushroom
    // add power level to mario
    cout << "Mario ate a mushroom. " << endl;
    if (myMario -> getPL() < 2){
      myMario -> addPL();
    }

  } else if (gamePiece == 'g'){ // goomba
    // create new goomba, battle
    Goomba* newGoomba = new Goomba();
    // mario won, game continues
    if (newGoomba -> goombaWon() == false){
      myMario -> addW();
      myMario -> checkW(); // checks if wins = 7
      cout << "Mario encountered a Goomba and WON. " << endl;
    // goomba won
    } else {
      //if power level is 0 we subtract a life
      if ((myMario -> getPL()) == 0){
        myMario -> subLife();
        //if we have no more lives left then the game is over
        if(myMario -> getLives() == 0){
          cout << "Mario lost all his lives. GAME OVER." << endl;
          gameOver = true;
        }
      } else {
        //power level is greater than 0
        myMario -> subPL();
      }
      battleWon = false;
      cout << "Mario encountered a Goomba and LOST. " << endl;
    }

  } else if (gamePiece == 'k'){ // koopa
    // create new koopa, battle
    Koopa* newKoopa = new Koopa();
    // mario won
    if (newKoopa -> koopaWon() == false){
      // game just continues
      myMario -> addW();
      myMario -> checkW();
      cout << "Mario encountered a Koopa and WON. " << endl;
    // koopa won
    } else {
      if ((myMario -> getPL()) == 0){
        myMario -> subLife();
        if(myMario -> getLives() == 0){
          cout << "Mario lost all his lives. GAME OVER." << endl;
          gameOver = true;
        }
      } else {
        myMario -> subPL();
      }
      battleWon = false;
      cout << "Mario encountered a Koopa and LOST. " << endl;
    }

  } else if (gamePiece == 'w'){ // warp pipe
    cout << "Mario encountered a warp pipe. WARPING TO NEXT LEVEL... " << endl;
    // mario jumps to rand. pos in next level w/o needing to beat level boss
    marioLevel += 1;
    placeMario();

  } else if (gamePiece == 'b'){ // boss
    // create new boss, battle
    Boss* newBoss = new Boss();
    // mario won
    didBossWin = newBoss -> bossWon();

    // losing to the boss - mario tries again
    while(didBossWin){
      if((myMario -> getPL()) > 1){
        myMario -> subPL();
        myMario -> subPL();
        cout << "Mario encountered the Boss and LOST. " << endl;
        printStats();
        cout << "Trying again..." << endl;
        didBossWin = newBoss -> bossWon();
      }
      //lose to boss and power level is < 1
      else{
        myMario -> setPL(0);
        //loss to boss and still have lives left
        if(myMario -> getLives() > 0){
          myMario -> subLife();
          cout << "Mario encountered the Boss and LOST. " << endl;
          printStats();
          cout << "Trying again..." << endl;
          didBossWin = newBoss -> bossWon();
        }
        //loss to boss and doesn't have lives left
        else{
          cout << "Mario encountered the Boss and LOST. " << endl;
          gameOver = true;
          didBossWin = false;
        }
      }
    }
    //boss beat on final level, finish game
    if(!didBossWin && (marioLevel+1 == my_numLevels)){
      cout << "You Win! Boss Defeated! GAME OVER" << endl;
      cout << "Printing grid and game stats one last time... " << endl;
      gameOver = true;
    }
    //boss beat move to next level
    else{
      myMario -> addW();
      myMario -> checkW();
      myMario -> setWs(0);
      marioLevel +=1;
      cout << "Mario encountered the Boss and WON. " << endl;
      placeMario();
    }
  }
  else{ // x
    cout << "Mario visited an empty space. " << endl;
  }
}


/*
a. isLevelOver - checks if the level that Mario is on is passed
b. returns levelOver, a boolean (true/false)
c. no parameters taken
d. no known exeptions thrown
*/

bool World::isLevelOver(){
  return levelOver;
}

/*
a. isGameOver - checks if the game is over
b. returns gameOver, a boolean (true/false)
c. no parameters taken
d. no known exeptions thrown
*/

bool World::isGameOver(){
  return gameOver;
}
