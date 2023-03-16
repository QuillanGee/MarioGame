// Quillan Gee
// 2404244
// qgee@chapman.edu
// CPSC 350-02
// P2: Not So Super Mario Bros - main.cpp file

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "World.h"


using namespace std;

int main(int argc, char** argv){
  int l; // levels
  int n; // NxN
  int v; // lives
  int c; // % coins
  int x; // % nothing
  int g; // % goombas
  int k; // % koopas
  int m; // % mushrooms

  // read into file
  string line;
  int lineNumber = 0;
  ifstream infile;
  string textfile = argv[1];
  infile.open(textfile);

  ofstream outfile;
  string logfile = argv[3];
  outfile.open(logfile);

  //get and assign each line to variable
  while (getline(infile, line)){
    if (lineNumber == 0){
      l = stoi(line);
    } else if (lineNumber == 1){
      n = stoi(line);
    } else if (lineNumber == 2){
      v = stoi(line);
    } else if (lineNumber == 3){
      c = stoi(line);
    } else if (lineNumber == 4){
      x = stoi(line);
    } else if (lineNumber == 5){
      g = stoi(line);
    } else if (lineNumber == 6){
      k = stoi(line);
    } else if (lineNumber == 7){
      m = stoi(line);
    }
    ++lineNumber;
  }

  World* myWorld = new World(l, n, v, c, x, g, k, m); // creates 3D array

  myWorld -> populateGrid();
  myWorld -> printGrid();
  myWorld -> placeMario();
  myWorld -> printLevel();

  while(myWorld -> isGameOver() == false){
    // sleep(1);
    myWorld -> Move();
    myWorld -> printLevel();
  }

  infile.close();
  outfile.close();

  delete myWorld;

  return 0;
}
