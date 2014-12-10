/* 
 * File:   Dictionary.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:46 PM
 */

#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary() {
    dict.insert(make_pair("USER", new Login ));
    dict.insert(make_pair("cd", new Cd ));
    dict.insert(make_pair("ls", new Ls ));
    dict.insert(make_pair("get", new Get ));
}

Dictionary::~Dictionary() {
}

Command* Dictionary::lookup(string key) {
    map<string, Command*>::const_iterator iter;
    iter = dict.find(key);
    if (iter != dict.end()) {
        return iter->second;
    }
    else {
        return NULL;
    }
}
