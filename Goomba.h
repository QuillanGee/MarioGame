// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Class for the game piece, Goomba
// Used for Mario vs. Goomba interaction

#ifndef GOOMBA_H
#define GOOMBA_H

class Goomba{
  public:
    Goomba();
    ~Goomba();
    bool goombaWon(); // checks if goomba or mario won

  protected:
    bool goombaWin; // true if goomba won against mario

};

#endif
