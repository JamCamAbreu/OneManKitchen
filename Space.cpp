/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: A "Space" is an abstract class. No objects of 
 *  just type "Space" are created. Space has many derived classes. 
 *  A derived Space is essentially a room that the user will 
 *  be placed in, and can traverse to other rooms using pointer
 *  logic. 
 * *********************************************************/

#include "Space.hpp"


// get functions:
Player* Space::getUser() {return user;}
Space* Space::getNorth() {return north;}
Space* Space::getEast() {return east;}
Space* Space::getSouth() {return south;}
Space* Space::getWest() {return west;}

// set functions:
void Space::setUser(Player* newUser) {user = newUser;}
void Space::setNorth(Space* newNorth) {north = newNorth;}
void Space::setEast(Space* newEast) {east = newEast;}
void Space::setSouth(Space* newSouth) {south = newSouth;}
void Space::setWest(Space* newWest) {west = newWest;}


int Space::wait() {

  std::cout << "How many minutes would you like to wait? " << std::endl;
  std::cout << "(Enter an integer from " << WAIT_MIN;
  std::cout << " to " << WAIT_MAX << "): ";

  int waitMinutes;
  std::cin >> waitMinutes;
  inputValidation(waitMinutes, WAIT_MIN, WAIT_MAX);

  std::cout << "Waiting " << waitMinutes << " minutes...";
  std::cout << std::endl;

  return waitMinutes;
}

void Space::showInventory() {
  getUser()->displayInventory();
}


void Space::pressContinue() {
  std::string dummy;
  std::cin.ignore(); // flush input buffer
  std::cout << "Press enter to continue...";
  std::getline(std::cin, dummy);
}



