/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: The Food class is a very flexible class that 
 *  can by specified into many types of food using an enum. 
 *  Food is an item that is carried by the Player class in 
 *  their inventory. Food can be raw at first, and can be 
 *  unthawed, but can also spoil. Food can be cooked and 
 *  plated, and then served to Tables (customers).
 * *********************************************************/

#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include <string>

const int UNTHAW_FACTOR = 2;
const int SOONSPOIL_FACTOR = 3;

enum foodType {
  // Meat Freezer
  F_CHICKEN = 0,
  F_HAMBURGER,
  F_PORK,
  F_BEEFSTEAK,
  F_SAUSAGE,

  // Produce Freezer
  F_SPINACH, // 5 - 11
  F_CABBAGE,
  F_EGGS,
  F_STALK,
  F_BREAD,
  F_CARROTS,
  F_ONIONS,

  // cooked items:
  F_COOK_CHICKEN, //12 - 18
  F_COOK_HAMBURGER,
  F_COOK_PORK,
  F_COOK_STEAK,
  F_COOK_OMELLETE,
  F_COOK_STEW,
  F_COOK_SALAD,

  // mistake:
  F_MISTAKE //19
};

enum foodStatus {
  S_FROZEN = 0,
  S_UNTHAW,
  S_SOONSPOIL,
  S_SPOIL
};


class Food {
  private:
    std::string name;
    int type;
    int maxLife;
    int life;
    bool plated;
    bool burnt;

  public:
    // get functions
    std::string getName();
    int getType();
    int getMaxLife();
    int getLife();
    bool getPlated();
    bool getBurnt();

    // set functions
    void setName(std::string newName);
    void setType(int newType);
    void setMaxLife(int newLife);
    void setLife(int newLife);
    void setPlated(bool flag);
    void setBurnt(bool flag);

    // other functions
    void ageLife(int minutes);
    int status();
    std::string printStatus();

    // one parameter constructor
    Food(foodType itemType);
};

#endif
