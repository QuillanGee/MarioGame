// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Class for the game piece, Boss
// Used for Mario vs. Boss interaction

#ifndef BOSS_H
#define BOSS_H

class Boss{
  public:
    Boss();
    ~Boss();
    bool bossWon();  // checks if boss or mario won

  protected:
    bool bossWin; // true if boss won against mario

};

#endif
