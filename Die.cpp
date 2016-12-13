/********************************************************************************
 * Author: James Cameron Abreu
 * Date: 11/03/2016
 * Description: The Die class is used to represent random dice rolling.
 * *****************************************************************************/

#include "Die.hpp"
#include <iostream>

// get functions:
int Die::getSides() {return sides;}

// set functions:
void Die::setSides(int newSides) {sides = newSides;}

// other functions:
int Die::rollDie(int forRandom) {

  int max = getSides();
  int min = 1;

  // use time function to get seed value for srand:
  unsigned seed;
  seed = std::time(0) + forRandom;
  srand(seed);

  // find a random number using that seed:
  int roll = (std::rand() % (max - min + 1)) + min;
  return roll;
}

// constructor:
Die::Die(int howManySides) {
  setSides(howManySides);
}


