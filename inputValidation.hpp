/********************************************************
 * Author: James Cameron Abreu
 * Date: 10/05/2016
 * Description: The input validation function will serve 
 *  as a multi-purpose utility to check the user's input
 *  any time a cin function is called. Using this function, 
 *  I do not need to redundently keep adding this code 
 *  each time I need to test for input validation. 
 * *****************************************************/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

// used for prompts:
#include <iostream>

bool inputValidation(int& userInput, int min, int max);

#endif
