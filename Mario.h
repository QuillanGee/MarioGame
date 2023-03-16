// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Holds methods and variables pertaining to Mario such as
// lifves, coins, power level, and wins

#ifndef MARIO_H
#define MARIO_H

class Mario{
  public:
    Mario();
    Mario(int lives);
    ~Mario();

    // life methods
    int getLives();
    void addLife();
    void subLife();

    // coin methods
    int getCoin();
    void addCoin();
    void subCoin();

    // power level methods
    int getPL();
    void setPL(int pl);
    void addPL();
    void subPL();

    // win methods
    void setWs(int w);
    int getWs();
    void addW();
    void checkW();

    int getLevel();

  protected:
    // member vars for Mario
    int livesLeft; // lives Mario has left
    int coin; // # of coins
    int power; // power level (PL0-PL2)
    int currLevel; // current level Mario's on
    int marioWs; // wins Mario has
};

#endif
