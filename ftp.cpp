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

#define PORT 21 // default port

  using namespace std;

/**
 * Main method of ftp.
 * Takes two command line arguments, the port to listen to and the hostname.
 */
int main(int argc, char** argv) {

  // check for correct number of arguments.
  if ( argc != 2 ) {
    cout << "Missing hostname." << endl;
    return 0;
  }
      
  char * ipName = argv[1]; // hostname to connect to

  Dictionary dict; // contains available commands.
  Command * cmd;   // a pointer to a command object that can execute commands.

  /* CONNECT TO SERVER  */

  Session session(PORT, ipName); // the current session of ftp.
    
  // check for server error
  
  
  //TODO: Poll for server reply
  string reply = session.getServerReply();
  // if reply does not start with 220, we got an error.
  if (!session.serverReplyEqualsCode(reply, "220")) {
    cerr << "Error with server." << endl;
    return 1;
  }

  /* LOGIN PHASE */
  


  /* COMMAND PHASE */

  string input;    // user input
    
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

