/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: Derived from the Space class, a Counter allows 
 *  the user to plate cooked food.
 * *********************************************************/

#include "SP_Counter.hpp"

// unused:
int Counter::getTablesAmount() {
}
void Counter::updateSpace(int minutes) {
}


// virtual inherited
int Counter::displayMenu() {
  int choice;

  std::string actions[7];
  actions[1] = "East: Side Dining Room";
  actions[2] = "South: Main Dining Room";
  actions[3] = "West: Kitchen";
  actions[4] = "Plate Food";
  actions[5] = "Wait";
  actions[6] = "Inventory";
  choice = menuSelect(actions, 6);
  return choice;
}

int Counter::performAction(int type) {
  int timeSpent = 0;

  // leave Counter:
  switch (type) {
    case 1: {
    case 2: 
    case 3: 
      enterDoor(type);
      timeSpent = TIME_DOOR;
      break; }

    // plate food
    case 4: {
      timeSpent = plateFood();
      break; }

    // wait
    case 5: {
      timeSpent = Space::wait();
      break; }

    // inventory
    case 6: {
      Space::showInventory();
      break; }

    default: {
      std::cout << "ERROR: performAction DEFAULT switch case.";
      std::cout << std::endl;
      break; }
  }

  return timeSpent;


}



// class specific functions------------------

void Counter::enterDoor(int direction) {

  switch (direction) {
    case 1: {
      std::cout << "Leaving Counter, Entering ";
      std::cout << "the Side Dining Room." << std::endl;
      Space::getUser()->setLocation(T_SDINING);
      break; }

    case 2: {
      std::cout << "Leaving Counter, Entering ";
      std::cout << "the Main Dining Room." << std::endl;
      Space::getUser()->setLocation(T_MDINING);
      break; }

    case 3: {
      std::cout << "Leaving Counter, Entering ";
      std::cout << "the Kitchen." << std::endl;
      Space::getUser()->setLocation(T_KITCHEN);
      break; }

    default: {
      std::cout << "ERROR: enterDoor DEFAULT switch case.";
      std::cout << std::endl;
      break; }
  } // end switch
}



int Counter::plateFood() {

  return 1;
}

