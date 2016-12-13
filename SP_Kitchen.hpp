/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: Derived from the Space class, a kitchen allows
 *  the user to unthaw and cook food.
 * *********************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Space.hpp"

const int MAX_ITEMS = 8;
const int MIN_COOK = 5;
const int MAX_COOK = 40;

enum applianceType {
  A_OVEN = 0,
  A_PAN,
  A_POT,
  A_BOWL
};

class Kitchen : public Space {

  private:
    std::vector<Food*> counterItems;


  public: 
    // virtual inherited:
    int displayMenu();
    int performAction(int type);
    int getTablesAmount();
    void updateSpace(int minutes);

    // class specific: 
    void enterDoor(int direction);
    int useAppliance();

    int checkItem(int* ingredientList, int itemID);
    int checkIngredients(int* ingredientList);

    void useCounter();
    void viewCounter();
    void placeCounter();
    void grabCounter();

    void reviewCookbook();

    // counterSpace vector functions:
    void addFood(Food* newItem);
    void displayCounterItems();
    int searchCounterItems();
    Food* removeItem();

};


#endif
