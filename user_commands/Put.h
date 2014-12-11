/* 
 * File:   Put.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:47 PM
 */

#ifndef PUT_H
#define	PUT_H

#include "../Command.h"
#include "Pasv.h"
#include <iostream>
#include <string>

class Put : public Command {
public:
  int execute(Session *, std::string);
  virtual ~Put();
private:

};

#endif	/* PUT_H */
