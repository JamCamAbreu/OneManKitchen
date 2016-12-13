/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: The Game class serves as a top layer logic 
 *  for controling other class objects and game logic. It 
 *  is responsible for beginning a new game, running the proper
 *  functions in the game, and determining winning conditions. 
 * *********************************************************/

#include "Game.hpp"

// get functions:
int Game::getMinutes() {return minutes;}
Player* Game::getUser() {return user;}
Space* Game::getRoom(int room){return rooms[room];} // returns single element
Space** Game::getRooms(){return rooms;} // returns array

// set functions:
void Game::setMinutes(int newMinutes) {minutes = newMinutes;}
void Game::addMinutes(int time) {minutes += time;}
void Game::setUser(Player* newPlayer){user = newPlayer;}
void Game::setRoom(Space* newRoom, int element){// sets element in array
  rooms[element] = newRoom; }
void Game::setRooms(Space** newArray) {rooms = newArray;} // assigns new array


// display info to user funcions:
std::string Game::calculateHour() {

  std::string hourString = "";
  std::stringstream ss;
  ss << (getMinutes()/60);
  hourString += ss.str();

  hourString += ":";
  std::stringstream ss2;
  ss2 << (getMinutes()%60);
  hourString += ss2.str();

  // add 0 if minutes are one digit:
  if (getMinutes()%60 < 10)
    hourString += "0";

  // what part of the day?
  if (getMinutes() < (60*10)) { // before 10:00am
    hourString += " - Morning";
  }
  else if (getMinutes() < (60*(12 + 1))) {
    hourString += " - Lunch Rush";
  }
  else if (getMinutes() < (60*(12 + 5))) {
    hourString += " - Dinner Prep Time";
  }
  else if (getMinutes() < (60*(12 + 8))) {
    hourString += " - Dinner Rush";
  }
  else if (getMinutes() < (60*(12 + 10))) {
    hourString += " - Evening Cleanup";
  }
  return hourString;
}

std::string Game::calculateLocation() {

  std::string locationString = "The ";
  switch (getUser()->getLocation()) {

    case T_MFREEZER: {
      locationString += "Meat Freezer";
      break; }

    case T_PFREEZER: {
      locationString += "Produce Freezer";
      break; }

    case T_KITCHEN: {
      locationString += "Kitchen";
      break; }

    case T_COUNTER: {
      locationString += "Plating Counter";
      break; }

    case T_MDINING: {
      locationString += "Main Dining Hall";
      break; }

    case T_SDINING: {
      locationString += "Side Dining Hall";
      break; }

    default: {
      std::cout << "ERROR - calculateLocation, default switch case.";
      std::cout << std::endl;
      break; }
  } // end switch
  return locationString;
}


int Game::calculateCustomers() {

  int customerCount = 0;
  customerCount += getRoom(T_MDINING)->getTablesAmount();
  customerCount += getRoom(T_SDINING)->getTablesAmount();
  return customerCount;
}

void Game::displayTurn() {
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "         .------------.       " << std::endl;
  std::cout << "       ~<| Turn Begin |>~     " << std::endl;
  std::cout << "         '------------'       " << std::endl;
  std::cout << std::endl;
  std::cout << "Time: " << calculateHour() << std::endl;
  std::cout << "Location: " << calculateLocation() << std::endl;
  std::cout << "Current Customers: " << calculateCustomers() << std::endl;
  std::cout << "Money: $" << getUser()->getMoney() << std::endl;
  std::cout << "------------------------------" << std::endl;
}




// gameplay functions:
int Game::promptAction() {
  int action;
  action = getRoom(getUser()->getLocation())->displayMenu();
  return action;
}



int Game::sendAction(int action) { // returns minutes used
  int timeSpent;
  timeSpent = getRoom(getUser()->getLocation())->performAction(action); 
  return timeSpent;

}

void Game::update(int minutes) {

  // each room updates differently:
  for (int i = 0; i < TOTALROOMS; i++) {
    getRoom(i)->updateSpace(minutes);
  }
  
  // update all items in player inventory!!
  getUser()->updateInventory(minutes);
}



void Game::runGame() {

  std::cout << "DEBUG - runGame...";
  std::cout << std::endl;

  std::cout << "Message to TA here...";
  std::cout << std::endl;
  std::cout << std::endl;

  // create game spaces:
  spaceSetup();

  // create player at the Kitchen
  int startingSpace = T_KITCHEN;
  setUser(new Player(startingSpace));

  // assign Player to all game Spaces:
  spaceAssignUser();

  // game winning conditions
  bool gameover = false;
  int selectedAction;
  int usedMinutes;

  while (!gameover) {
    displayTurn();
    selectedAction = promptAction();
    usedMinutes = sendAction(selectedAction);
    addMinutes(usedMinutes);
    update(usedMinutes);

    // game conditions:
    if (getMinutes() > (60*(12 + 8)))
      gameover = true;
  }

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "|-------------------------------------|" << std::endl;
  std::cout << "|           KITCHEN: CLOSED           |" << std::endl;
  std::cout << "|-------------------------------------|" << std::endl;
  std::cout << "~~Final results~~" << std::endl;
  std::cout << "    Time: " << calculateHour() << std::endl;
  std::cout << "    Money: $" << getUser()->getMoney() << std::endl;
  std::cout << "    Customers successfully Served: ";
  std::cout << getUser()->getCustomersServed() << std::endl;
  std::cout << std::endl;
  std::cout << "Tomorrow's another day...." << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
}



void Game::spaceSetup() {

  // dynamically allocate:
  Space** newSpaces = new Space*[TOTALROOMS];
  newSpaces[0] = new Freezer(F_MEAT); // meat
  newSpaces[1] = new Freezer(F_PRODUCE); // produce
  newSpaces[2] = new Kitchen;
  newSpaces[3] = new Counter;
  newSpaces[4] = new Dining(D_MAIN); // main dining
  newSpaces[5] = new Dining(D_SIDE); // side dining

  // assign pointer to array to member variable:
  setRooms(newSpaces);

  // assign pointers in each Space object---------
  // meatFreezer: 
  getRoom(T_MFREEZER)->setNorth(NULL);
  getRoom(T_MFREEZER)->setEast(NULL);
  getRoom(T_MFREEZER)->setSouth(getRoom(T_KITCHEN));
  getRoom(T_MFREEZER)->setWest(NULL);

  // produceFreezer: 
  getRoom(T_PFREEZER)->setNorth(NULL);
  getRoom(T_PFREEZER)->setEast(getRoom(T_KITCHEN));
  getRoom(T_PFREEZER)->setSouth(NULL);
  getRoom(T_PFREEZER)->setWest(NULL);

  // Kitchen: 
  getRoom(T_KITCHEN)->setNorth(getRoom(T_MFREEZER));
  getRoom(T_KITCHEN)->setEast(getRoom(T_COUNTER));
  getRoom(T_KITCHEN)->setSouth(getRoom(T_MDINING));
  getRoom(T_KITCHEN)->setWest(getRoom(T_PFREEZER));

  // Counter: 
  getRoom(T_COUNTER)->setNorth(NULL);
  getRoom(T_COUNTER)->setEast(getRoom(T_SDINING));
  getRoom(T_COUNTER)->setSouth(getRoom(T_MDINING));
  getRoom(T_COUNTER)->setWest(getRoom(T_KITCHEN));

  // Dining (main): 
  getRoom(T_MDINING)->setNorth(getRoom(T_COUNTER));
  getRoom(T_MDINING)->setEast(NULL);
  getRoom(T_MDINING)->setSouth(NULL);
  getRoom(T_MDINING)->setWest(getRoom(T_KITCHEN));

  // Dining (side): 
  getRoom(T_SDINING)->setNorth(NULL);
  getRoom(T_SDINING)->setEast(NULL);
  getRoom(T_SDINING)->setSouth(NULL);
  getRoom(T_SDINING)->setWest(getRoom(T_COUNTER));
}


void Game::spaceAssignUser() {
  for (int i = 0; i < TOTALROOMS; i++) {
    getRoom(i)->setUser(getUser());
  }
}




// constructor/destructor:
Game::Game() {
  setMinutes(400);
  setUser(NULL);
  setRooms(NULL);
}


Game::~Game() {
  // delete element of array:
  for (int i = 0; i < TOTALROOMS; i++) {
    delete getRoom(i);
  }
  // delete array:
  delete [] getRooms();
}

// debug:


