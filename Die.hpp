/********************************************************************************
 * Author: James Cameron Abreu
 * Date: 11/03/2016
 * Description:
 * *****************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <cstdlib>
#include <ctime>

class Die {

  private:
    int sides;

  public:

    // get functions:
    int getSides();

    // set functions:
    void setSides(int newSides);

    // other functions:
    int rollDie(int forRandom);

    // constructor:
    Die(int sides);

};


#endif
