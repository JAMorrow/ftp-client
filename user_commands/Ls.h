/* 
 * File:   Ls.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:47 PM
 */

#ifndef LS_H
#define	LS_H

#include "../Command.h"
#include "Pasv.h"
#include <iostream>
#include <string>

class Ls : public Command {
public:
  int execute(Session *, std::string);
  virtual ~Ls();
private:

};

#endif	/* LS_H */
