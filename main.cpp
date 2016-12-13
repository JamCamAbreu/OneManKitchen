/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: The main function serves as the top layer to 
 *  this multi-file program. See the design document for full 
 *  documentation
 * *********************************************************/

#include <iostream>
#include <string>

#include "Game.hpp"
#include "menuSelect.hpp"

int main() {

  std::cout << std::endl;
  std::cout << "|-------------------------------------------|" << std::endl;
  std::cout << "|   Welcome to                              |" << std::endl;
  std::cout << "|              The Amazing One Man Kitchen! |" << std::endl;
  std::cout << "|                     by James Cam Abreu    |" << std::endl;
  std::cout << "|-------------------------------------------|" << std::endl;
  std::cout << std::endl;

  std::string mainMenu[5];
  mainMenu[1] = "New Game";
  mainMenu[2] = "Overview and Instructions";
  mainMenu[3] = "About Author";
  mainMenu[4] = "Exit Program";

  int choice;
  do {

    choice = menuSelect(mainMenu, 4);

    switch (choice) {

      case 1: {
        std::cout << "Starting new game...";
        std::cout << std::endl;
        std::cout << std::endl;

        Game* newGame = new Game;
        newGame->runGame();
        delete newGame;
        break;
      }
	  
      case 2:
        {
        std::cout << std::endl;
        std::cout << "Game Overview: " << std::endl;
        std::cout << "The Amazing One Man Kitchen is";
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "How to Play:" << std::endl;
        std::cout << "After choosing \"New Game\" from the main menu, ";
        std::cout << std::endl;
        break;
        }
		
      case 3:
        {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "About Author:" << std::endl;
        std::cout << "James 'Cam' Abreu is currently a computer science major at Oregon State University.";
        std::cout << "He enjoys his programming assignments, but also fancies game programming at a higher ";
        std::cout << "level using programs such as GameMaker or whatever else he can find. He also previously ";
        std::cout << "earned a bachelor's degree in music education and spent a few years in the Seattle area ";
        std::cout << "as a public band teacher" << std::endl;
        std::cout << std::endl;
        break;
        }

      case 4: 
        break;

      default:
        break;
    } // end switch

  } while (choice != 4);


  std::cout << std::endl;
  std::cout << "Thank you for using James Cam Abreu's 'One Man Kitchen'!" << std::endl;
  std::cout << std::endl;

  return 0;
}


