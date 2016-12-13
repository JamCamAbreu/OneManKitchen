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

#include "Food.hpp"

// get functions
std::string Food::getName() {return name;}
int Food::getType() {return type;}
int Food::getMaxLife() {return maxLife;}
int Food::getLife() {return life;}
bool Food::getPlated() {return plated;}
bool Food::getBurnt() {return burnt;}

// set functions
void Food::setName(std::string newName) {name = newName;}
void Food::setType(int newType) {type = newType;}
void Food::setMaxLife(int newLife) {maxLife = newLife;}
void Food::setLife(int newLife) {life = newLife;}
void Food::setPlated(bool flag) {plated = flag;}
void Food::setBurnt(bool flag) {burnt = flag;}

// other functions
void Food::ageLife(int minutes) {life -= minutes;}

int Food::status() {
  if (getLife() >= (getMaxLife()/UNTHAW_FACTOR) )
    return S_FROZEN;
  else if (getLife() >= (getMaxLife()/SOONSPOIL_FACTOR) )
    return S_UNTHAW;
  else if (getLife() >= 0)
    return S_SOONSPOIL;
  else
    return S_SPOIL;
}

std::string Food::printStatus() {

  int currentStatus = status();
  switch(currentStatus) {

    case S_FROZEN: {
      return "Still Frozen";
      break; }

    case S_UNTHAW: {
      return "Unthawed and Ready";
      break; }

    case S_SOONSPOIL: {
      return "Soon to Spoil";
      break; }

    case S_SPOIL: {
      return "Spoiled";
      break; }

    default: {
      std::cout << "ERROR - printStatus default switch" << std::endl;
      break; }

  } // end switch
  return "ERROR - printStatus no return value";
}


// one parameter constructor
Food::Food(foodType itemType) {
  switch(itemType) {

    // Meat Freezer:
    case F_CHICKEN: {
      setName("Chicken Breast");
      setMaxLife(60);
      break; }
  
    case F_HAMBURGER: {
      setName("Ground Hamburger");
      setMaxLife(50);
      break; }
  
    case F_PORK: {
      setName("Pork Loin");
      setMaxLife(70);
      break; }
  
    case F_BEEFSTEAK: {
      setName("Beef Steak");
      setMaxLife(50);
      break; }
  
    case F_SAUSAGE: {
      setName("Sausage");
      setMaxLife(40);
      break; }

    // Produce Freezer
    case F_SPINACH: {
      setName("Spinach Leaves");
      setMaxLife(16);
      break; }
  
    case F_CABBAGE: {
      setName("Cabbage");
      setMaxLife(24);
      break; }
  
    case F_EGGS: {
      setName("Eggs");
      setMaxLife(16);
      break; }
  
    case F_STALK: {
      setName("Chicken Stalk");
      setMaxLife(32);
      break; }
  
    case F_BREAD: {
      setName("Slice of Bread");
      setMaxLife(24);
      break; }
  
    case F_CARROTS: {
      setName("Carrots");
      setMaxLife(24);
      break; }
  
    case F_ONIONS: {
      setName("Onions");
      setMaxLife(20);
      break; }

    // cooked items:

    case F_COOK_CHICKEN: {
      setName("Cooked Chicken Breast");
      setMaxLife(40);
      setLife(19);
      break; }

    case F_COOK_HAMBURGER: {
      setName("Cooked Hamburger");
      setMaxLife(40);
      setLife(19);
      break; }

    case F_COOK_PORK: {
      setName("Cooked Pork Loin");
      setMaxLife(40);
      setLife(19);
      break; }

    case F_COOK_STEAK: {
      setName("Cooked Juicy Steak");
      setMaxLife(40);
      setLife(19);
      break; }

    case F_COOK_OMELLETE: {
      setName("Cooked Omellete");
      setMaxLife(40);
      setLife(19);
      break; }

    case F_COOK_STEW: {
      setName("Cooked Irish Stew");
      setMaxLife(40);
      setLife(19);
      break; }

    case F_COOK_SALAD: {
      setName("Prepared Salad");
      setMaxLife(40);
      setLife(19);
      break; }

    // mistake
    case F_MISTAKE: {
      setName("Mistake");
      setMaxLife(20);
      break; }
  
    default: {
      std::cout << "ERROR - Food constructor - default switch" << std::endl;
      break; }

  } // end switch

  setType(itemType);
  setPlated(false);
  setBurnt(false);

  if (getType() < F_COOK_CHICKEN)
    setLife(getMaxLife());
}

