/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: The Player class essentially holds data for 
 *  the user, such as an inventory and the user's current 
 *  location (which Space are they in?)
 * *********************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // print spacing

#include "Food.hpp"
#include "inputValidation.hpp"

const int MAX_INVENTORY = 5;
const int MAX_NAME_PRINT = 16;
const int MAX_LIFE_PRINT = 2;

// enum for Space types:
enum SpaceTypes {
  T_MFREEZER = 0, // 0
  T_PFREEZER, // 1
  T_KITCHEN, // 2
  T_COUNTER,  // 3
  T_MDINING,  // 4
  T_SDINING   // 5
};


class Player {

  private:
    int location;
    int money;
    int customersServed;

  public:

    std::vector<Food*> inventory;

    // get functions:
    int getLocation();
    int getMoney();
    int getCustomersServed();

    // set functions:
    void setLocation(int newLocation);
    void setMoney(int amount);
    void incrementMoney(int amount);
    void setCustomersServed(int newAmount);
    void incrementCustomersServed();

    // inventory functions:
    void addFood(Food* newItem);
    void displayInventory();
    Food* peekTop();
    int searchInventory(int type);
    Food* removeItem();
    void updateInventory(int minutes);

    int* useIngredients();


    // constructor / destructor:
    Player(int startingLocation);
    ~Player();
};

#endif

