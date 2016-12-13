/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: Derived from the Space class, a Counter allows 
 *  the user to plate cooked food.
 * *********************************************************/

#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "Space.hpp"

class Counter : public Space {

  private: 

  public: 
    // virtual inherited:
    int displayMenu();
    int performAction(int type);
    int getTablesAmount();
    void updateSpace(int minutes);

    // class specific:
    void enterDoor(int direction);
    int plateFood();
};


#endif
