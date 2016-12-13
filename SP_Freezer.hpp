/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: Derived from the Space class, a Freezer Space 
 *  allows the user to pull ingredients out to be thawed and 
 *  later cooked.
 * *********************************************************/

#ifndef FREEZER_HPP
#define FREEZER_HPP

#include "Space.hpp"

const int TIME_FREEZER = 3;

enum freezerType {
  F_MEAT = 0,
  F_PRODUCE
};

class Freezer : public Space {

  private:
    int freezerType; // freezer type

  public:

    // get functions
    int getFreezerType();

    // set functions
    void setFreezerType(int newType);

    // inherited virtual functions:
    int displayMenu();
    int performAction(int type);
    int getTablesAmount();
    void updateSpace(int minutes);

    // class specific functions:
    void enterDoor(int direction);
    int pullItem();

    // one parameter constructor:
    Freezer(int type);
};

#endif
