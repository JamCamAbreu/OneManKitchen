/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: The Table class is used for functions related 
 *  to customers. The reason it is called a table, is because 
 *  it can contain a customer or not (empty)
 * *********************************************************/

#ifndef TABLE_HPP
#define TABLE_HPP

#include "Food.hpp"
#include "Die.hpp"
#include "Player.hpp"
// iostream and string from Food.hpp

const int MAX_HAPPINESS = 90;
const int DIE_OFFSET = 11;
const int TIP = 10;

class Table {

  private:
    Player* host;
    std::string name;
    int happinessMax;
    int happiness;
    Food* desiredFood;
    Die* die;
    bool served;


  public:

    // get functions
    Player* getHost();
    std::string getName();
    int getHappinessMax();
    int getHappiness();
    Food* getDesiredFood();
    Die* getDie();
    bool getServed();

    // set functions
    void setHost(Player* newHost);
    void setName(std::string newName);
    void setHappinessMax(int newLevel);
    void setHappiness(int newLevel);
    void decrementHappiness(int amount);
    void incrementHappiness(int amount);
    void setDesiredFood(Food* newType);
    void setDie(Die* die);
    void setServed(bool flag);

    // other functions
    void greet();
    void displayCustomerInfo();
    std::string getMood();
    void updateHappiness(int minutes);
    void leave();

    void pressContinue();

    // constructor
    Table(Player* user);

    // destructor
    ~Table();
};

#endif

