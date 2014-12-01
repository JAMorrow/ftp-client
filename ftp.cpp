/* 
 * File:   ftp.cpp
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:44 PM
 */

#include <cstdlib>
#include <iostream>
#include "Command.h"
#include "Dictionary.h"
#include "Session.h"
//#include "util/Socket.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Dictionary dict;
    Command * cmd;
    Session session;
    //Socket sock;
    
    string input;
    
    cout << "Welcome to ftp.  Please enter a command.\n";

    cin >> input; // first input
    while (input != "exit") {
        Command* cmd = dict.lookup(input);

        if (cmd != NULL) {
            cmd->execute(&session);
        } else {
            cout << "Invalid command.\n";
        }
        cin >> input;
    }

    return 0;
}

