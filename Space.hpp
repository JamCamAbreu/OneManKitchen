/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: A "Space" is an abstract class. No objects of 
 *  just type "Space" are created. Space has many derived classes. 
 *  A derived Space is essentially a room that the user will 
 *  be placed in, and can traverse to other rooms using pointer
 *  logic. 
 * *********************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include "menuSelect.hpp"
#include "inputValidation.hpp"
#include "Player.hpp"

const int WAIT_MIN = 1;
const int WAIT_MAX = 60;
const int TIME_DOOR = 1;

class Space {

  private:

    Player* user;

    Space* north;
    Space* east;
    Space* south;
    Space* west;

  public:

    // get functions:
    Player* getUser();
    Space* getNorth();
    Space* getEast();
    Space* getSouth();
    Space* getWest();

    // set functions:
    void setUser(Player* newUser);
    void setNorth(Space* newNorth);
    void setEast(Space* newEast);
    void setSouth(Space* newSouth);
    void setWest(Space* newWest);

    // Every Space contains these functions,
    // but a different implementation:
    virtual int displayMenu() = 0;
    virtual int performAction(int type) = 0;
    virtual int getTablesAmount() = 0;
    virtual void updateSpace(int minutes) = 0;

    int wait();
    void showInventory();
    void pressContinue();

    // debug:
};

#endif
