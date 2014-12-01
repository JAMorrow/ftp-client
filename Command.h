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

class Command {
public:
    virtual void execute(Session*)=0;
    virtual ~Command() { }
private:

};

#endif	/* COMMAND_H */

