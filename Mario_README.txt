CPSC 350-02 PROJECT 1 README - Not So Super Mario Bros

Personal Info
  a. Full name: Quillan Gee
  b. Student ID: 2404244
  c. Chapman email: qgee@chapman.edu
  d. Course number and section: CPSC 350-02
  e. Assignment: Project 2 - Not So Super Mario Bros

List of all source files:
   - main.cpp
   - World.cpp
   - World.h
   - Mario.cpp
   - Mario.h
   - Goomba.cpp
   - Goomba.h
   - Koopa.cpp
   - Koopa.h
   - Boss.cpp
   - Boss.h
   - input.txt (input file, game specs)
   - log.txt (output file, game log)

A description of any known compile or runtime errors, code limitations, or deviations
from the assignment specification (if applicable):
  - Code compiles and takes a while to run due to sleep()
  - Takes about a minute to run. Please be patient :)

A list of all references used to complete the assignment, including peers (if applicable):
  - https://cplusplus.com/forum/beginner/121597/
  - https://www.geeksforgeeks.org/how-to-dynamically-allocate-a-3d-array-in-c/
  - https://cboard.cprogramming.com/cplusplus-programming/149429-rand-srand-not-working-i-want-them-o-o.html
  - Classmate Arisa for running assignment (./e.exe gameSpecs.txt > log.txt)
  - Classmate Marissa for sleep method with random

Instructions for running the assignment:
  docker start compsci
  docker attach compsci
  g++ *.cpp -o e.exe
  ./e.exe input.txt > log.txt

  *where input.txt is input, log.txt is output*
