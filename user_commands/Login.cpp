/* 
 * File:   Login.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:47 PM
 */

#include "Login.h"

void Login::execute(Session* session) {
    std::cout << "Executing login!\n";
    session->setUsername("bob");
    std::cout << "Session username is now " 
            << session->getUsername() << std::endl;
}


Login::~Login() {
    
}

