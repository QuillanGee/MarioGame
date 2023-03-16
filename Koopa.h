// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

// Class for the game piece, Koopa Troopa
// Used for Mario vs. Koopa interaction

#ifndef KOOPA_H
#define KOOPA_H

class Koopa{
  public:
    Koopa();
    ~Koopa();
    bool koopaWon(); // checks if koopa or mario won

  protected:
    bool koopaWin; // true if koopa won against mario
};

#endif
