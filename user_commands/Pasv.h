/* 
 * File:   Pasv.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:47 PM
 */

#ifndef PASV_H
#define	PASV_H

#include "../Command.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Pasv : public Command {
public:
  int execute(Session *, std::string);
  virtual ~Pasv();
private:
  void setupPort(Session *, std::string);
};

#endif	/* PASV_H */
