/********************************************************
 * Author: James Cameron Abreu
 * Date: 10/04/2016
 * Description: This menu function is designed as a stand-
 *  alone function to create and display a menu to the 
 *  user for selecting options. 
 * *****************************************************/

#include "menuSelect.hpp"

int menuSelect(std::string menuOptions[], int howManyOptions) {
  int choice;

  std::cout << std::endl;
  std::cout << "Please select one of the choices from the menu:";
  std::cout << std::endl;

  for (int i = 1; i <= howManyOptions; i++) {
    std::cout << " " << i << ". " << menuOptions[i];
    std::cout << std::endl;
  }
  std::cout << "Your choice: ";
  std::cin >> choice;

  // input validation:
  while (!((choice >= 1) && (choice <= howManyOptions))) {
    std::cout << std::endl;
    std::cout << "Please enter one of the options, either ";
    for (int j = 1; j < (howManyOptions); j++) {
      std::cout << j << ", ";
    }
    std::cout << "or " << howManyOptions;
    std::cout << ". " << std::endl;

    std::cout << "Your choice: ";
    std::cin >> choice;
  } 

  return choice;
}

