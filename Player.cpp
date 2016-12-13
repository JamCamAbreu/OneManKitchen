/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: The Player class essentially holds data for 
 *  the user, such as an inventory and the user's current 
 *  location (which Space are they in?)
 * *********************************************************/

#include "Player.hpp"

// get functions
int Player::getLocation() {return location;}
int Player::getMoney() {return money;}
int Player::getCustomersServed() {return customersServed;}

// set functions
void Player::setLocation(int newLocation) {location = newLocation;}
void Player::setMoney(int amount) {money = amount;}
void Player::incrementMoney(int amount) {money += amount;}
void Player::setCustomersServed(int newAmount) {customersServed = newAmount;}
void Player::incrementCustomersServed() {customersServed++;}


// inventory functions -------------------------
// push
void Player::addFood(Food* newItem) {

  // condition for max capacity:
  if (inventory.size() < MAX_INVENTORY)
    inventory.push_back(newItem);
  else {
    std::cout << "You only have space for " << MAX_INVENTORY;
    std::cout << " items to carry in your hands at a time.";
    std::cout << std::endl;
    std::cout << "You can: ";
    std::cout << std::endl;
    std::cout << "  -Place an item on the Kitchen counter";
    std::cout << "(if there's space on the counter)";
    std::cout << std::endl;
    std::cout << "  -Combine different ingredients into appliances";
    std::cout << " in the Kitchen to cook them.";
    std::cout << std::endl;
    std::cout << "  -Deliver cooked, plated items to customers tables.";
    std::cout << std::endl;
    std::cout << "  -Throw items in the trash";
    std::cout << std::endl;
  }
}

// display:
void Player::displayInventory() {

  if (inventory.size() == 0) {
    std::cout << "Your inventory is empty.";
    std::cout << std::endl;
  }
  else {
    std::cout << "Currently holding: ";
    std::cout << std::endl;
    std::cout << "    ";

    unsigned int i;
    for (i = 0; i < inventory.size(); i++) {

      // number
      std::cout << i << ". ";

      // name
      std::cout << std::setw(MAX_NAME_PRINT) << std::left 
        << inventory.at(i)->getName();

      // life
      std::cout << " - Life: ";
      std::cout << std::setw(MAX_LIFE_PRINT) << std::left 
        << inventory.at(i)->getLife();

      std::cout << " of ";
      std::cout << std::setw(MAX_LIFE_PRINT) << std::left 
        << inventory.at(i)->getMaxLife();

      // life status
      std::cout << " (";
      std::cout << inventory.at(i)->printStatus();
      std::cout << ")";

      // comma, if nessisary, newline, indent
      if (inventory.at(i) != inventory.back()) {
        std::cout << ", ";

      // newline, indent
        std::cout << std::endl;
        std::cout << "    ";
      }
      else
        std::cout << std::endl;
    } // end for loop
  } // end else

}

// peek
Food* Player::peekTop() {
  if (inventory.size() > 0)
    return inventory.back(); 
  else 
    return NULL;
}

// search
int Player::searchInventory(int type) {

  // I DONT NEED THIS FUNCTION FOR PLAYER
  // BUT I DO NEED IT FOR KITCHEN

  // This function is used by the cooking to 
  // check and see if all the correct items 
  // are present to cook the food.
  /*
  if (inventory.size() > 0) {
    for (int i = 0; i < 
  }
  else {
    std::cout << "Your inventory is empty.";
    std::cout << std::endl;
    return -1; // null value
  }
  */

}


// remove
Food* Player::removeItem() { // REMEMBER TO CHECK FOR NULL WHEN CALLING!

  // step 1: show user what items they are carrying
  // step 2: user selects item to be removed
  // step 3: Temporarily store item to be removed to be returned later
  // step 4: Item is removed
  // step 5: temp Food* is returned

  // step 1:
  displayInventory();

  // step 2:
  std::cout << std::endl;
  std::cout << "Which item would you like to use?";
  std::cout << std::endl;
  std::cout << "(enter -1 to cancel): ";
  int itemChoice = -1;
  std::cin >> itemChoice;
  inputValidation(itemChoice, -1, inventory.size());

  if (itemChoice != -1) {
    // step 3:
    Food* temp = inventory.at(itemChoice);

    // step 4:
    inventory.erase(inventory.begin()+itemChoice);

    // step 5:
    return temp;
  }
  else
    return NULL;
}

void Player::updateInventory(int minutes) {

  if (inventory.size() > 0) {
    for (int i = 0; i < inventory.size(); i++) {
      inventory.at(i)->ageLife(minutes);
    } // end for
  } // end if
}




int* Player::useIngredients() {
  
  std::vector<int> ingredientTypes;
  if (inventory.size() > 0) {

    int chooseItem = -1;

    do {

      // inventory empty yet?
      if (inventory.size() > 0) {

        displayInventory();
        std::cout << "Which Items would you like to use?";
        std::cout << std::endl;
        std::cout << "Choose an item from your inventory, ";
        std::cout << "enter -1 to stop: ";
        std::cin >> chooseItem;
        inputValidation(chooseItem, -1, inventory.size() - 1);

        if (chooseItem != -1) {
          // temporarily store the pointer:
          Food* temp = inventory.at(chooseItem);

          // update inventory vector:
          inventory.erase(inventory.begin()+chooseItem);

          // add type to our int vector:
          ingredientTypes.push_back(temp->getType());
          delete temp;
        }

      } // end if inventory empty
      else {
        std::cout << "You've used all ingredients you were carrying.";
        std::cout << std::endl;
        chooseItem = -1;
      }

    } while (chooseItem != -1);

    // store ingredients into array:
    if (ingredientTypes.size() > 0) {
      int* list = new int[MAX_INVENTORY];
      for (int j = 0; j < MAX_INVENTORY; j++) {
        if (j < ingredientTypes.size())
          list[j] = ingredientTypes.at(j);
        else
          list[j] = -1; // no ingredient
      } // end for loop
      return list;
    }
    else // decided to cancel:
      return NULL;

  } // end if inventory size > 0
  else {
    std::cout << "Your inventory is empty. You cannot cook without ingredients.";
    std::cout << std::endl;
    return NULL;
  }
}


// constructor: -------------------------
Player::Player(int startingLocation) {
  setLocation(startingLocation);
  setMoney(0);
  setCustomersServed(0); 
}

// destructor:
Player::~Player() {

}
