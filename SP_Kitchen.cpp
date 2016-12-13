/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: Derived from the Space class, a kitchen allows
 *  the user to unthaw and cook food.
 * *********************************************************/

#include "SP_Kitchen.hpp"


// virtual inherited functions ----------------

// unused:
int Kitchen::getTablesAmount() {
}


int Kitchen::displayMenu() {

  int choice;

  std::string actions[10];
  actions[1] = "North: Meat Freezer";
  actions[2] = "East: Counter";
  actions[3] = "South: Main Dining Room";
  actions[4] = "West: Produce Freezer";
  actions[5] = "Use appliances";
  actions[6] = "Counter Space - Unthaw, Grab, Etc...";
  actions[7] = "Review cookbook";
  actions[8] = "Wait";
  actions[9] = "Inventory";

  choice = menuSelect(actions, 9);
  return choice;

}

int Kitchen::performAction(int type) {

  int timeSpent = 0;

  // leave Kitchen:
  switch (type) {
    case 1: {
    case 2: 
    case 3: 
    case 4: 
      enterDoor(type);
      timeSpent = TIME_DOOR;
      break; }

    // use appliances
    case 5: {
      useAppliance();
      break; }

    // unthaw food
    case 6: {
      useCounter();
      break; }

    // review cookbook
    case 7: {
      reviewCookbook();
      break; }

    // wait
    case 8: {
      timeSpent = Space::wait();
      break; }

    // inventory
    case 9: {
      Space::showInventory();
      break; }

    default: {
      std::cout << "ERROR: performAction DEFAULT switch case.";
      std::cout << std::endl;
      break; }
  }

  return timeSpent;

}

void Kitchen::updateSpace(int minutes) {

  // update all food items on counter!!

}


// class specific ----------------------------------

void Kitchen::enterDoor(int direction) {

  switch (direction) {
    case 1: {
      std::cout << "Leaving Kitchen, Entering ";
      std::cout << "the meat freezer." << std::endl;
      Space::getUser()->setLocation(T_MFREEZER);
      break; }

    case 2: {
      std::cout << "Leaving Kitchen, Entering ";
      std::cout << "the plating counter." << std::endl;
      Space::getUser()->setLocation(T_COUNTER);
      break; }

    case 3: {
      std::cout << "Leaving Kitchen, Entering ";
      std::cout << "the main dining room." << std::endl;
      Space::getUser()->setLocation(T_MDINING);
      break; }

    case 4: {
      std::cout << "Leaving Kitchen, Entering ";
      std::cout << "the produce freezer." << std::endl;
      Space::getUser()->setLocation(T_PFREEZER);
      break; }

    default: {
      std::cout << "ERROR: enterDoor DEFAULT switch case.";
      std::cout << std::endl;
      break; }
  } // end switch
}


int Kitchen::useAppliance() {

  // step 1: choose appliance
  // step 2: choose ingredients
  // step 3: choose minutes to cook
  // step 4: determine and create new item
  //          correct ingredients? 
  // step 5: add new cooked item to player inventory
  // step : return minutes used

  int minutesUsed = 2;

  // step 1:
  std::string actions[6];
  actions[1] = "Back (cancel)";
  actions[2] = "Use Oven";
  actions[3] = "Use Pan";
  actions[4] = "Use Pot";
  actions[5] = "Use Bowl";

  int choice = menuSelect(actions, 5);

  if (choice != 1) {

    // step 2:
    int* ingredients;
    ingredients = Space::getUser()->useIngredients();

    if (ingredients != NULL) {

      // step 3:
      std::cout << "How many minutes will you cook these items?";
      std::cout << std::endl;
      std::cout << "Enter amount of minutes from " << MIN_COOK;
      std::cout << " to " << MAX_COOK << ": ";
      int cookMinutes;
      std::cin >> cookMinutes;
      inputValidation(cookMinutes, MIN_COOK, MAX_COOK);

      // step 4:
      int itemToCreate = checkIngredients(ingredients);
      std::cout << "You've created...";
      Food* newItem = new Food(static_cast<foodType>(itemToCreate));
      std::cout << newItem->getName();
      std::cout << "!!" << std::endl;

      // step 4b delete pointer:
      delete ingredients;

      // step 5:
      Space::getUser()->addFood(newItem);
      std::cout << "Put cooked food into inventory.";
      std::cout << std::endl;

    } // end if ingredients != NULL


  } // end if choice != 1

  return minutesUsed;
}

int Kitchen::checkItem(int* ingredientList, int itemID) {
  
  int amount = 0;
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (ingredientList[i] == itemID)
      amount++;
  }
  return amount;
}

int Kitchen::checkIngredients(int* ingredientList) {

  int howMany = 0;
  for (int i = 0; i < MAX_INVENTORY; i++) {
    if (ingredientList[i] != -1)
      howMany++;
  }

  if (howMany == 1) {
    // chicken breast:
    if (checkItem(ingredientList, F_CHICKEN) == 1)
      return F_COOK_CHICKEN;
    else
      return F_MISTAKE;
  }

  // 2 items:
  if (howMany == 2) {
    // pork loin
    if ( (checkItem(ingredientList, F_PORK) == 1) &&
         (checkItem(ingredientList, F_SPINACH) == 1) )
      return F_COOK_PORK;

    // steak
    else if ( (checkItem(ingredientList, F_BEEFSTEAK) == 1) &&
         (checkItem(ingredientList, F_SPINACH) == 1) )
      return F_COOK_STEAK;
    else 
      return F_MISTAKE;
  }
  // 3 items:
  else if (howMany == 3) {
    return F_MISTAKE;
  }
  // 4 items:
  else if (howMany == 4) {
    return F_MISTAKE;
  }
  // 5 items:
  else if (howMany == 5) {

    // hamburger:
    if ( (checkItem(ingredientList, F_HAMBURGER) == 1) &&
         (checkItem(ingredientList, F_SPINACH) == 1) &&
         (checkItem(ingredientList, F_BREAD) == 2) &&
         (checkItem(ingredientList, F_ONIONS) == 1) )
      return F_COOK_HAMBURGER;

    // omellete
    else if ( (checkItem(ingredientList, F_EGGS) == 2) &&
         (checkItem(ingredientList, F_SPINACH) == 1) &&
         (checkItem(ingredientList, F_SAUSAGE) == 1) &&
         (checkItem(ingredientList, F_ONIONS) == 1) )
      return F_COOK_OMELLETE;

    // irish stew
    else if ( (checkItem(ingredientList, F_SAUSAGE) == 1) &&
         (checkItem(ingredientList, F_STALK) == 1) &&
         (checkItem(ingredientList, F_CABBAGE) == 1) &&
         (checkItem(ingredientList, F_CARROTS) == 1) &&
         (checkItem(ingredientList, F_ONIONS) == 1) )
      return F_COOK_STEW;

    // salad
    else if ( (checkItem(ingredientList, F_SPINACH) == 3) &&
         (checkItem(ingredientList, F_CARROTS) == 1) &&
         (checkItem(ingredientList, F_ONIONS) == 1) )
      return F_COOK_SALAD;

    else
      return F_MISTAKE;
  }
}

// display counter menu options
void Kitchen::useCounter() {

  std::string actions[5];
  actions[1] = "Back";
  actions[2] = "View Items on Counter";
  actions[3] = "Place Item on Counter";
  actions[4] = "Grab Item from Counter";

  int choice = menuSelect(actions, 4);
  
  switch (choice) {

    case 1: {
      // do nothing, go back
      break; }

    case 2: {
      viewCounter();
      break; }

    case 3: {
      placeCounter();
      break; }

    case 4: {
      grabCounter();
      break; }

    default: {
      std::cout << "ERROR: useCounter DEFAULT switch case.";
      std::cout << std::endl;
      break; }

  } // end switch

}

void Kitchen::viewCounter() {

  if (counterItems.size() == 0) {
    std::cout << "There is nothing on the Counter.";
    std::cout << std::endl;
  }
  else {
    std::cout << "Currently sitting on Counter: ";
    std::cout << std::endl;
    std::cout << "    ";

    unsigned int i;
    for (i = 0; i < counterItems.size(); i++) {

      // number
      std::cout << i << ". ";

      // name
      std::cout << std::setw(MAX_NAME_PRINT) << std::left 
        << counterItems.at(i)->getName();

      // life
      std::cout << " - Life: ";
      std::cout << std::setw(MAX_LIFE_PRINT) << std::left 
        << counterItems.at(i)->getLife();

      std::cout << " of ";
      std::cout << std::setw(MAX_LIFE_PRINT) << std::left 
        << counterItems.at(i)->getMaxLife();

      // life status
      std::cout << " (";
      std::cout << counterItems.at(i)->printStatus();
      std::cout << ")";

      // comma, if nessisary, newline, indent
      if (counterItems.at(i) != counterItems.back()) {
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

void Kitchen::placeCounter() {
  // step 1: check counterspace
  // step 1a. check to see if inventory is empty
  // step 2: Space::getUser()->removeItem
  // step 3: store item in counterItems vector

  // step 1:
  if (counterItems.size() >= MAX_ITEMS) {
    std::cout << "The counter is full!";
    std::cout << std::endl;
    std::cout << "You must remove an item from it ";
    std::cout << "before you can place another one.";
    std::cout << std::endl;
  }
  else if (Space::getUser()->inventory.size() == 0) {
    std::cout << "You have nothing to place. ";
    std::cout << "(Your inventory is empty.)";
    std::cout << std::endl;
    std::cout << "You can grab frozen ingredients from either ";
    std::cout << std::endl;
    std::cout << "  -The Meat Freezer (north) or ";
    std::cout << std::endl;
    std::cout << "  -The Produce Freezer (West)";
    std::cout << std::endl;
  }
  else {
    // step 2:
    Food* temp = Space::getUser()->removeItem();

    // step 3:
    addFood(temp);

  } // end else
}

void Kitchen::grabCounter() {
  // step 1: check user inventory space 
  // step 1a: check to see if counter is empty
  // step 2: show items on counter
  // step 3: remove item from counter
  // step 4: place item in user inventory

  // step 1:
  if (Space::getUser()->inventory.size() >= MAX_INVENTORY) {
    std::cout << "Your inventory is already full!";
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
  else if (counterItems.size() == 0) {
    std::cout << "There is nothing to grab";
    std::cout << std::endl;
    std::cout << "The Counter is empty.";
    std::cout << std::endl;
  }
  else {

    // step 2:
    displayCounterItems();

    // step 3:
    Food* temp = removeItem();

    // step 4:
    Space::getUser()->addFood(temp);

  } // end else
}


void Kitchen::reviewCookbook() {
  std::cout << "|-------------------------------------------------|" << std::endl;
  std::cout << "|            |One Man Kitchen Cookbook|           |" << std::endl;
  std::cout << "|            '------------------------'           |" << std::endl;
  std::cout << "|                    ~RECIPES~                    |" << std::endl;
  std::cout << "|                                                 |" << std::endl;
  std::cout << "|  1. Chicken Breast         5. Fried Omelette    |" << std::endl;
  std::cout << "|    -X1 Chicken Breast        -X2 Eggs           |" << std::endl;
  std::cout << "|    -X1 Spinach Leaves        -X1 Spinach Leaves |" << std::endl;
  std::cout << "|    -use oven                 -X1 Sausage        |" << std::endl;
  std::cout << "|                              -X1 Onion          |" << std::endl;
  std::cout << "|  2. Hamburger                -use fry pan       |" << std::endl;
  std::cout << "|    -X1 Ground Hamburger                         |" << std::endl;
  std::cout << "|    -X2 Bread Slices        6. Irish Stew        |" << std::endl;
  std::cout << "|    -X1 Onion                 -X1 Sausage        |" << std::endl;
  std::cout << "|    -use fry pan              -X1 Chicken Stalk  |" << std::endl;
  std::cout << "|                              -X1 Cabbage        |" << std::endl;
  std::cout << "|  3. Pork Loin                -X1 Carrots        |" << std::endl;
  std::cout << "|    -X1 Pork Loin             -X1 Onion          |" << std::endl;
  std::cout << "|    -X1 Onion                 -use pot           |" << std::endl;
  std::cout << "|    -use oven                                    |" << std::endl;
  std::cout << "|                            7. Salad             |" << std::endl;
  std::cout << "|  4. Juicy Steak              -X3 Spinach Leaves |" << std::endl;
  std::cout << "|    -X1 Beef Steak            -X1 Carrots        |" << std::endl;
  std::cout << "|    -X1 Spinach Leaves        -X1 Onion          |" << std::endl;
  std::cout << "|    -use oven                 -use bowl          |" << std::endl;
  std::cout << "|-------------------------------------------------|" << std::endl;
}




// counterSpace vector functions: -------------------
void Kitchen::addFood(Food* newItem) {

  // condition for max capacity:
  if (counterItems.size() < MAX_ITEMS)
    counterItems.push_back(newItem);
  else {
    std::cout << "You only have space for " << MAX_ITEMS;
    std::cout << " items to be placed on the kitchen counter.";
    std::cout << std::endl;
    std::cout << "You must remove something before placing ";
    std::cout << "another item.";
  }
}

void Kitchen::displayCounterItems() {

}


int Kitchen::searchCounterItems() {
  return 0;
}


Food* Kitchen::removeItem() { // REMEMBER TO CHECK FOR NULL WHEN CALLING!

  // step 1: show user what items they are carrying
  // step 2: user selects item to be removed
  // step 3: Temporarily store item to be removed to be returned later
  // step 4: Item is removed
  // step 5: temp Food* is returned

  // step 1:
  displayCounterItems();

  // step 2:
  std::cout << std::endl;
  std::cout << "Which item would you like to pick up?";
  std::cout << std::endl;
  std::cout << "(enter -1 to cancel): ";
  int itemChoice = -1;
  std::cin >> itemChoice;
  inputValidation(itemChoice, -1, counterItems.size());

  if (itemChoice != -1) {
    // step 3:
    Food* temp = counterItems.at(itemChoice);

    // step 4:
    counterItems.erase(counterItems.begin()+itemChoice);

    // step 5:
    return temp;
  }
  else
    return NULL;
}




