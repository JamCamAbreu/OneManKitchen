/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: Derived from the Space class, a Dining room 
 *  contains Table objects (customers) and allows the user 
 *  to interact with those objects.
 * *********************************************************/

#include "SP_Dining.hpp"

// get functions
int Dining::getDiningType() {return diningType;}
Die* Dining::getDie() {return die;}
int Dining::getChanceIncreaser() {return chanceIncreaser;}

// set functions
void Dining::setDiningType(int newType) {diningType = newType;}
void Dining::setDie(Die* newDie) {die = newDie;}
void Dining::setChanceIncreaser(int amount) {chanceIncreaser = amount;}
void Dining::incrementChance() {chanceIncreaser++;}


// inherited virtual functions -----------------
int Dining::getTablesAmount() {return tables.size();}

int Dining::displayMenu() {

  int choice = 1;

  // display "There are x customers in this dining room"

  std::cout << "There are currently " << tables.size();
  std::cout << " customers in this room.";
  std::cout << std::endl;

  // main Dining room:
  if (getDiningType() == D_MAIN) {
    std::string actions[7];
    actions[1] = "North: Plating Counter";
    actions[2] = "West: Kitchen";
    actions[3] = "Greet Customers";
    actions[4] = "Serve Customers";
    actions[5] = "Wait";
    actions[6] = "Inventory";
    choice = menuSelect(actions, 6);
  }
  // side Dining Room:
  else if (getDiningType() == D_SIDE) {
    std::string actions[6];
    actions[1] = "West: Plating Counter";
    actions[2] = "Greet Customers";
    actions[3] = "Serve Customers";
    actions[4] = "Wait";
    actions[5] = "Inventory";
    choice = menuSelect(actions, 5);
  }
  else {
    std::cout << "ERROR - dining room display menu type error";
    std::cout << std::endl;
  }

  return choice;


}

int Dining::performAction(int type) {

  int timeSpent = 0;

  // main Dining Room:
  if (getDiningType() == D_MAIN) {

    // leave Dining Room:
    switch (type) {
      case 1: {
      case 2: 
        enterDoor(type);
        timeSpent = TIME_DOOR;
        break; }

      // greet customers
      case 3: {
        timeSpent = greetCustomers();
        break; }

      // serve customers
      case 4: {
        timeSpent = serveCustomers();
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
  } // end main dining room


  // side dining room:
  else if (getDiningType() == D_SIDE) {

    // leave Dining Room:
    switch (type) {
      case 1: {
        enterDoor(type);
        timeSpent = TIME_DOOR;
        break; }

      // greet customers
      case 2: {
        timeSpent = greetCustomers();
        break; }

      // serve customers
      case 3: {
        timeSpent = serveCustomers();
        break; }

      // wait
      case 4: {
        timeSpent = Space::wait();
        break; }

      // inventory
      case 5: {
        Space::showInventory();
        break; }

      default: {
        std::cout << "ERROR: performAction DEFAULT switch case.";
        std::cout << std::endl;
        break; }
    }
  } // end side dining room
  else {
    std::cout << "ERROR - dining performAction type error";
    std::cout << std::endl;
  }
  return timeSpent; 
}

void Dining::updateSpace(int minutes) {

  // update each customer!!
  if (tables.size() > 0) {
    for (int i = 0; i < tables.size(); i++) {
      tables.at(i)->updateHappiness(minutes);
    }
  }

  int random;
  if (getDiningType() == D_MAIN)
    random = 1;
  else if (getDiningType() == D_SIDE)
    random = 2;

  // roll for new customers:
  int newRoll = getDie()->rollDie(minutes*random);
  newRoll += getChanceIncreaser();
  newRoll += minutes/2;

  if ( (newRoll >= NEW_CUSTOMER_ROLL) && (tables.size() < MAX_CUSTOMERS)) {

    // new customer:
    tables.push_back(new Table(Space::getUser()));

    // warn user:
    std::cout << std::endl;
    std::cout << "New customer arrived in ";

    if (getDiningType() == D_MAIN)
      std::cout << "the Main Dining Room!";
    else if (getDiningType() == D_SIDE)
      std::cout << "the Side Dining Room!";

    std::cout << std::endl;
    Space::pressContinue();
    std::cout << std::endl;

    // reset chanceIncreaser:
    setChanceIncreaser(0);
  }
  else { // did NOT create a new customer, increase chances next time?
    if (newRoll > NEW_CUSTOMER_ROLL/2) { // 50% chance of increasing chances
      incrementChance();
      // 25% chance to increment main dining increaser AGAIN
      if ( (getDiningType() == D_MAIN) && newRoll > NEW_CUSTOMER_ROLL*(3/4))
        incrementChance();
    }
  } // end else
}


// class specific functions -----------------

void Dining::enterDoor(int direction) {
  switch (direction) {
    case 1: {
      if (getDiningType() == D_MAIN) {
        std::cout << "Leaving Main Dining Hall, Entering ";
        std::cout << "the Plating Counter." << std::endl;
        Space::getUser()->setLocation(T_COUNTER);
      }
      else if(getDiningType() == D_SIDE) {
        std::cout << "Leaving Side Dining Hall, Entering ";
        std::cout << "the Plating Counter." << std::endl;
        Space::getUser()->setLocation(T_COUNTER);
      }
      else {
        std::cout << "ERROR - Dining enterDoor getDiningType error";
        std::cout << std::endl;
      }

      break; }

    case 2: {
      std::cout << "Leaving Main Dining Hall, Entering ";
      std::cout << "the Kitchen." << std::endl;
      Space::getUser()->setLocation(T_KITCHEN);
      break; }

    default: {
      std::cout << "ERROR: enterDoor DEFAULT switch case.";
      std::cout << std::endl;
      break; }
  } // end switch

}

int Dining::greetCustomers() {

  if (tables.size() == 0) {
    std::cout << "There are currently no customers to greet.";
    std::cout << std::endl;
    return 1;
  }
  else {
    std::cout << "Which customer would you like to greet?";
    std::cout << std::endl;
    for (int i = 0; i < tables.size(); i++) {
      std::cout << i << ". ";
      std::cout << tables.at(i)->getName();
      std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Select a customer: ";
    int chooseCustomer;
    std::cin >> chooseCustomer;
    inputValidation(chooseCustomer, 0, tables.size() - 1);

    tables.at(chooseCustomer)->greet();
    return 2;
  }
}



int Dining::serveCustomers() {

  // step 1: display a list of customers, if any exist
  // step 2: choose a customer from the list
  // step 3: choose a food from your inventory
  // step 4: check if food was desired
  // step 5: display results
 
  // step 1
  if (tables.size() == 0) {
    std::cout << "There are currently no customers to serve.";
    std::cout << std::endl;
  }
  else {

    if (Space::getUser()->inventory.size() < 0) {
      std::cout << "You are carrying nothing to serve.";
      std::cout << std::endl;
      std::cout << "You can pull items from the freezer and ";
      std::cout << "cook them in the kitchen.";
      std::cout << std::endl;
      pressContinue();
    }

    else {
      std::cout << "Which customer would you like to serve?";
      std::cout << std::endl;
      for (int i = 0; i < tables.size(); i++) {
        std::cout << i << ". ";
        std::cout << tables.at(i)->getName();
        std::cout << std::endl;
      }

      // step 2
      std::cout << std::endl;
      std::cout << "Select a customer: ";
      int chooseCustomer;
      std::cin >> chooseCustomer;
      inputValidation(chooseCustomer, 0, tables.size() - 1);
      std::cout << std::endl;

      //Space::getUser()->displayInventory();

      // step 3
      Food* chooseItem;
      chooseItem = Space::getUser()->removeItem();
      int servedType = chooseItem->getType(); // your chosen
      int desiredType = tables.at(chooseCustomer)->getDesiredFood()->getType(); // customer

      // step 4
      if (servedType == desiredType) {
        // step 5
        tables.at(chooseCustomer)->setServed(true);
        std::cout << "The customer is VERY pleased with the dish!!";
        std::cout << std::endl;
      }
      else {
        // step 5
        std::cout << "You served the wrong dish!!";
        std::cout << std::endl;
      }

      Space::pressContinue();
    } // end there IS item in inventory
  } // end there IS at least one customer

  return 2;
}


// one parameter constructor:
Dining::Dining(int type) {
  setDiningType(type);

  if (getDiningType() == D_MAIN)
    setChanceIncreaser(NEW_CUSTOMER_ROLL/2); // main dining start with good chance
  else if (getDiningType() == D_SIDE)
    setChanceIncreaser(0);

  setDie(new Die(NEW_CUSTOMER_ROLL));
}


