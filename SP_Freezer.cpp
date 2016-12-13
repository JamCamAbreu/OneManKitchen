/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: Derived from the Space class, a Freezer Space 
 *  allows the user to pull ingredients out to be thawed and 
 *  later cooked.
 * *********************************************************/

#include "SP_Freezer.hpp"


// get functions
int Freezer::getFreezerType() {return freezerType;}

// set functions
void Freezer::setFreezerType(int newType) {freezerType = newType;}

// unused:
int Freezer::getTablesAmount() {
}

// inherited virtual functions

// unused:
void Freezer::updateSpace(int minutes) {
}

int Freezer::displayMenu() {

  int choice = 1;

  // meat freezer:
  if (getFreezerType() == F_MEAT) {
    std::string actions[5];
    actions[1] = "South: Kitchen";
    actions[2] = "Pull item to Unthaw";
    actions[3] = "Wait";
    actions[4] = "Inventory";
    choice = menuSelect(actions, 4);
  }
  // meat freezer:
  else if (getFreezerType() == F_PRODUCE) {
    std::string actions[5];
    actions[1] = "East: Kitchen";
    actions[2] = "Pull item to Unthaw";
    actions[3] = "Wait";
    actions[4] = "Inventory";
    choice = menuSelect(actions, 4);
  }
  else {
    std::cout << "ERROR - freezer display menu type error";
    std::cout << std::endl;
  }

  return choice;
}


int Freezer::performAction(int type) {

  int timeSpent = 0;

  // leave Freezer (either)
  switch (type) {
    case 1: {
      enterDoor(type);
      timeSpent = TIME_DOOR;
      break; }

    // pull item to unthaw:
    case 2: {
      timeSpent = pullItem();
      break; }

    // wait
    case 3: {
      timeSpent = Space::wait();
      break; }

    // inventory
    case 4: {
      Space::showInventory();
      break; }

    default: {
      std::cout << "ERROR: performAction DEFAULT switch case.";
      std::cout << std::endl;
      break; }
  }

  return timeSpent; 
}



// class specific functions----------------

void Freezer::enterDoor(int direction) {
  switch (direction) {
    case 1: {
      if (getFreezerType() == F_MEAT) {
        std::cout << "Leaving Meat Freezer, Entering ";
        std::cout << "the Kitchen." << std::endl;
        Space::getUser()->setLocation(T_KITCHEN);
      }
      else if(getFreezerType() == F_PRODUCE) {
        std::cout << "Leaving Produce Freezer, Entering ";
        std::cout << "the Kitchen." << std::endl;
        Space::getUser()->setLocation(T_KITCHEN);
      }
      else {
        std::cout << "ERROR - Freezer enterDoor getFreezerType error";
        std::cout << std::endl;
      }

      break; }

    default: {
      std::cout << "ERROR: enterDoor DEFAULT switch case.";
      std::cout << std::endl;
      break; }
  } // end switch

}

int Freezer::pullItem() {

  int choice = 1;

  if (getFreezerType() == F_MEAT) {
    std::string actions[7];
    actions[1] = "Back (cancel)";
    actions[2] = "Pull Frozen Chicken Breast";
    actions[3] = "Pull Frozen Ground Hamburger";
    actions[4] = "Pull Frozen Pork Loin";
    actions[5] = "Pull Frozen Beef Steak";
    actions[6] = "Pull Frozen Sausage";
    choice = menuSelect(actions, 6);

    Food* newFoodItem;

    switch (choice) {

      case 1: {
        // back (cancel) do nothing.
        break; }

      case 2: {
        newFoodItem = new Food(F_CHICKEN);
        break; }

      case 3: {
        newFoodItem = new Food(F_HAMBURGER);
        break; }

      case 4: {
        newFoodItem = new Food(F_PORK);
        break; }

      case 5: {
        newFoodItem = new Food(F_BEEFSTEAK);
        break; }

      case 6: {
        newFoodItem = new Food(F_SAUSAGE);
        break; }

      default: {
        std::cout << "ERROR - Freezer pullItem default switch case";
        std::cout << std::endl;
        break; }


    } // end switch
    
    if (choice != 1) {
      getUser()->addFood(newFoodItem);
    }


  } // end Meat Freezer
  else if (getFreezerType() == F_PRODUCE) {

    std::string actions[9];
    actions[1] = "Back (cancel)";
    actions[2] = "Pull Frozen Spinach Leaves";
    actions[3] = "Pull Frozen Cabbage";
    actions[4] = "Pull Frozen Eggs";
    actions[5] = "Pull Frozen Chicken Stalk";
    actions[6] = "Pull Frozen Bread Slice";
    actions[7] = "Pull Frozen Carrots";
    actions[8] = "Pull Frozen Onions";
    choice = menuSelect(actions, 8);

    Food* newFoodItem;

    switch (choice) {

      case 1: {
        // back (cancel) do nothing.
        break; }

      case 2: {
        newFoodItem = new Food(F_SPINACH);
        break; }

      case 3: {
        newFoodItem = new Food(F_CABBAGE);
        break; }

      case 4: {
        newFoodItem = new Food(F_EGGS);
        break; }

      case 5: {
        newFoodItem = new Food(F_STALK);
        break; }

      case 6: {
        newFoodItem = new Food(F_BREAD);
        break; }

      case 7: {
        newFoodItem = new Food(F_CARROTS);
        break; }

      case 8: {
        newFoodItem = new Food(F_ONIONS);
        break; }

      default: {
        std::cout << "ERROR - Freezer pullItem default switch case";
        std::cout << std::endl;
        break; }

    } // end switch
    
    if (choice != 1) {
      getUser()->addFood(newFoodItem);
    }

  } // end Produce Freezer
  else {
    std::cout << "ERROR - Freezer pullItem getFreezerType error";
    std::cout << std::endl;
  }


  // announce pull successful:
  if (choice != 1) {
    std::cout << "Successfully pulled ";
    std::cout << getUser()->peekTop()->getName();
    std::cout << std::endl;
  }

  // minutes used
  if (choice != 1)
    return TIME_FREEZER;
  else 
    return 1;
}



// one parameter constructor:
Freezer::Freezer(int type) {
  setFreezerType(type);
}


