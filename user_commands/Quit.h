/* 
 * File:   Quit.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:47 PM
 */

#ifndef QUIT_H
#define	QUIT_H

#include "../Command.h"
#include <iostream>
#include <string>

class Quit : public Command {
public:
  int execute(Session *, std::string);
  virtual ~Quit();
private:

};

#endif	/* QUIT_H */
