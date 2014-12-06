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
#include <string>
#include <termios.h> // for hiding password as it's typed
#include <unistd.h>  // for showing system username
#include <stdio.h>   // for showing system username


class Login : public Command {
public:
  int execute(Session *, std::string);
  virtual ~Login();
private:
  std::string getPassword();

};

#endif	/* LOGIN_H */

