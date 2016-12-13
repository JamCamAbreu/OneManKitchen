/********************************************************
 * Author: James Cameron Abreu
 * Date: 10/05/2016
 * Description: The input validation function will serve 
 *  as a multi-purpose utility to check the user's input
 *  any time a cin function is called. Using this function, 
 *  I do not need to redundently keep adding this code 
 *  each time I need to test for input validation. 
 * *****************************************************/

#include "inputValidation.hpp"

bool inputValidation(int& userInput, int min, int max) {
  while ( (userInput < min) || (userInput > max) ) {

    std::cout << std::endl;
    std::cout << "Please enter an integer greater than " << min;
    std::cout << ", and less than " << max << ": ";
    std::cin >> userInput;
  }
  
  std::cout << std::endl;
  return true;
}


