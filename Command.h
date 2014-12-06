/* 
 * File:   Command.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:46 PM
 */

#ifndef COMMAND_H
#define	COMMAND_H

#include <string>
#include "Session.h"

#define ERROR 1

class Command {
public:
  virtual int execute(Session*, std::string = "")=0;
    virtual ~Command() { }
private:

};

#endif	/* COMMAND_H */

