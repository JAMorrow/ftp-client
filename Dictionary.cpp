/* 
 * File:   Dictionary.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:46 PM
 */

#include "Dictionary.h"

Dictionary::Dictionary() {
    dict.insert(std::make_pair("login", new Login ));
}

Dictionary::~Dictionary() {
}

Command* Dictionary::lookup(std::string key) {
    std::map<std::string, Command*>::const_iterator iter;
    iter = dict.find(key);
    if (iter != dict.end()) {
        return iter->second;
    }
    else {
        return NULL;
    }
}
