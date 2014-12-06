/* 
 * File:   Cd.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:47 PM
 */

#ifndef CD_H
#define	CD_H

#include "../Command.h"
#include <iostream>
#include <string>

class Cd : public Command {
public:
  int execute(Session *, std::string);
  virtual ~Cd();
private:

};

#endif	/* CD_H */

