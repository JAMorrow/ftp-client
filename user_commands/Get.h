/* 
 * File:   Get.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:47 PM
 */

#ifndef GET_H
#define	GET_H

#include "../Command.h"
#include "Pasv.h"
#include <fstream>
#include <iostream>
#include <string>

class Get : public Command {
public:
  int execute(Session *, std::string);
  virtual ~Get();
private:

};

#endif	/* GET_H */
