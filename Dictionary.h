/* 
 * File:   Dictionary.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:46 PM
 */

#ifndef DICTIONARY_H
#define	DICTIONARY_H

#include <map>
#include <string>
#include "Command.h"
#include "user_commands/Login.h"
#include "user_commands/Cd.h"

class Dictionary
{
 private:
  std::map <std::string, Command*> dict;
 public:
  Dictionary();
  Command* lookup(std::string key);
  ~Dictionary();
};

#endif	/* DICTIONARY_H */

