// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Creates world using game specs provided at runtime and assigned in main
// Contains all main game methods to facilitate gameplay

#ifndef WORLD_H
#define WORLD_H

#include "Mario.h"
#include "Koopa.h"
#include "Goomba.h"
#include "Boss.h"

class World{
public:
  World(); //default constructor
  ~World(); //default destructor
  World(int numLevels,int numGrid,int lives, int coins, int nothingPer, int goombaPer, int koopasPer, int mushroomPer); //overloaded constructor

  // print and populate methods
  void populateGrid();
  void printGrid();
  void printLevel();
  void printStats();
  char getRandItem();
  void placeMario();
  void placeBoss(int level);
  void placeWarpPipe(int level);

  // movement methods
  void Move();
  void MoveUp(int level,int prevRow);
  void MoveDown(int level,int prevRow);
  void MoveLeft(int level, int prevCol);
  void MoveRight(int level, int prevCol);

  // object interaction
  void objectAt(char gamePiece);

  bool isGameOver();
  bool isLevelOver();

private:
  // member vars for game specs
  int my_numLevels;
  int my_numGrid;
  int my_lives;
  int my_coins;
  int my_nothingPer;
  int my_goombaPer;
  int my_koopasPer;
  int my_mushroomPer;
  Mario* myMario;
  char*** my_grid;

  // member vars for mario, warp pipe, and boss placements
  int marioColStart;
  int marioRowStart;
  int randomColWarpPipe;
  int randomRowWarpPipe;
  int randomRowBoss;
  int randomColBoss;

  // member vars to keep track of mario
  int prevRow;
  int prevCol;
  int newRow;
  int newCol;
  int marioLevel;

  // member vars to keep track of gameplay
  bool gameOver;
  bool levelOver;
  bool didBossWin;
  bool battleWon;
  int x;
};

#endif
