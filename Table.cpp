/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: The Table class is used for functions related 
 *  to customers. The reason it is called a table, is because 
 *  it can contain a customer or not (empty)
 * *********************************************************/

#include "Table.hpp"


// get functions
Player* Table::getHost() {return host;}
std::string Table::getName() {return name;}
int Table::getHappinessMax() {return happinessMax;}
int Table::getHappiness() {return happiness;}
Food* Table::getDesiredFood() {return desiredFood;}
Die* Table::getDie() {return die;}
bool Table::getServed() {return served;}

// set functions
void Table::setHost(Player* newHost) {host = newHost;}
void Table::setName(std::string newName) {name = newName;}
void Table::setHappinessMax(int newLevel) {happinessMax = newLevel;}
void Table::setHappiness(int newLevel) {happiness = newLevel;}
void Table::decrementHappiness(int amount) {happiness -= amount;}
void Table::incrementHappiness(int amount) {happiness += amount;}
void Table::setDesiredFood(Food* newType) {desiredFood = newType;}
void Table::setDie(Die* newDie) {die = newDie;}
void Table::setServed(bool flag) {served = flag;}

// other functions
void Table::greet() {

  std::cout << "[You approach and greet the customer]";
  std::cout << std::endl;

  displayCustomerInfo();

  // serving customer increases their patience a little:
  if (!getServed())
    incrementHappiness(5);

  pressContinue();
}

void Table::displayCustomerInfo() {

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Customer info:" << std::endl;
  std::cout << "  Name:      " << getName() << std::endl;
  std::cout << "  Mood: " << getMood() << std::endl;
  std::cout << "  Desired Food: " << getDesiredFood()->getName();
  std::cout << std::endl;
  std::cout << std::endl;

  if (getServed()) {
    std::cout << "You notice the customer is still eating and will ";
    std::cout << "likely leave in about " << getHappiness();
    std::cout << " minutes." << std::endl;
  }
}


std::string Table::getMood() {
  if (getServed())
    return "Very Satisfied. -\"The Food is delicious, thank you!\"";
  else if (getHappiness() > MAX_HAPPINESS*(4/5))
    return "Very Happy, but still need served.";
  else if (getHappiness() > MAX_HAPPINESS*(3/5))
    return "Happy, but still need served.";
  else if (getHappiness() > MAX_HAPPINESS*(2/5))
    return "Been waiting awhile..., still need served.";
  else if (getHappiness() > MAX_HAPPINESS*(1/5))
    return "Unhappy, leaving soon.";
  else 
    return "Very Unhappy! \"I've never had to wait this long for my food!\"";
}


void Table::updateHappiness(int minutes) {
  decrementHappiness(minutes);
  if (getHappiness() <= 0)
    leave();
}


void Table::leave() {

  // if served is true, leave cash
  if (getServed()) {
    // for now just a static amount:
    getHost()->incrementMoney(TIP);
    getHost()->incrementCustomersServed();

    // notify player:
    std::cout << "Customer " << getName();
    std::cout << " just left " << TIP;
    std::cout << "dollars!";
    std::cout << std::endl;
  }
  else {
    std::cout << "Customer " << getName();
    std::cout << " just left and was NOT ";
    std::cout << " happy at all! No tip!";
    std::cout << std::endl;
  }

  pressContinue();
  
  // suicide...
  delete this;
}

void Table::pressContinue() {
  std::string dummy;
  std::cin.ignore(); // flush input buffer
  std::cout << "Press enter to continue...";
  std::getline(std::cin, dummy);
}


// constructor
Table::Table(Player* user) {

  setHost(user);
  setServed(false);

  setHappinessMax(MAX_HAPPINESS);
  setHappiness(MAX_HAPPINESS);

  // used for random:
  setDie(new Die(7)); // + use roll + DIE_OFFSET

  // roll for desired food:
  int roll = getDie()->rollDie(1);
  setDesiredFood(new Food(static_cast<foodType>(roll + DIE_OFFSET)));

  // roll for random name:
  roll = getDie()->rollDie(2);

  switch (roll) {

    case 1: {
      setName("Bob");
      break; }

    case 2: {
      setName("Cindy");
      break; }

    case 3: {
      setName("Mike");
      break; }

    case 4: {
      setName("Mary");
      break; }

    case 5: {
      setName("Joe");
      break; }

    case 6: {
      setName("Niki");
      break; }

    case 7: {
      setName("James");
      break; }

    default: {
      setName("Default case error");
      break; }
  } // end switch

}

// destructor
Table::~Table() {
  delete getDie();
}

