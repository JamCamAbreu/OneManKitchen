/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: Derived from the Space class, a Dining room 
 *  contains Table objects (customers) and allows the user 
 *  to interact with those objects.
 * *********************************************************/

#ifndef DINING_HPP
#define DINING_HPP

#include "Space.hpp"

#include "Table.hpp"
// Die.hpp included from Table.hpp

// chance of customers spawning:
const int NEW_CUSTOMER_ROLL = 120;
const int MAX_CUSTOMERS = 5;

enum diningType {
  D_MAIN = 0,
  D_SIDE
};

class Dining : public Space {

  private:
    int diningType;
    std::vector<Table*> tables;
    Die* die;
    int chanceIncreaser;

  public:

    // get functions
    int getDiningType();
    Die* getDie();
    int getChanceIncreaser();

    // set functions
    void setDiningType(int newType);
    void setDie(Die* newDie);
    void setChanceIncreaser(int amount);
    void incrementChance();

    // inherited virtual functions:
    int displayMenu();
    int performAction(int type);
    int getTablesAmount();
    void updateSpace(int minutes);

    // class specific functions:
    void enterDoor(int direction);
    int greetCustomers();
    int serveCustomers();

    // one parameter constructor:
    Dining(int type);


};


#endif
