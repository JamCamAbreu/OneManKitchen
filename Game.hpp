/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: The Game class serves as a top layer logic 
 *  for controling other class objects and game logic. It 
 *  is responsible for beginning a new game, running the proper
 *  functions in the game, and determining winning conditions. 
 * *********************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <sstream>

#include "Food.hpp"
#include "Player.hpp"
#include "Table.hpp"

// Space classes:
#include "SP_Freezer.hpp"
#include "SP_Kitchen.hpp"
#include "SP_Counter.hpp"
#include "SP_Dining.hpp"

// constants:
const int TOTALROOMS = 6;

class Game {

  private:
    int minutes;
    Player* user;
    Space** rooms; // array, uses enum SpaceTypes

  public:
    // get functions:
    int getMinutes();
    Player* getUser();
    Space* getRoom(int room); // returns single element
    Space** getRooms(); // returns array

    // set functions:
    void setMinutes(int newMinutes);
    void addMinutes(int time);
    void setUser(Player* newPlayer);
    void setRoom(Space* newRoom, int element); // sets element in array
    void setRooms(Space** newArray); // assigns new array

    // display info to user funcions:
    std::string calculateHour();
    std::string calculateLocation();
    int calculateCustomers();
    void displayTurn();
    
    // setup functions:
    void spaceSetup();
    void spaceAssignUser();

    // gameplay functions:
    int promptAction(); // returns correct action
    int sendAction(int action); // returns minutes used
    void update(int minutes);
    void runGame();

    // constructor/destructor:
    Game();
    ~Game();

    // debug:

};

#endif
