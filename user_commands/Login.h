/* 
 * File:   Login.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:47 PM
 */

#ifndef LOGIN_H
#define	LOGIN_H

#include "../Command.h"
#include <iostream>

class Login : public Command {
public:
    void execute(Session *);
    virtual ~Login();
private:

};

#endif	/* LOGIN_H */

