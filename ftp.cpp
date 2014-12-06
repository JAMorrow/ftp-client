/* 
* File:   ftp.cpp
* Author: kowalsky
*
* Created on November 30, 2014, 2:44 PM
  */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Command.h"
#include "Dictionary.h"
#include "Session.h"


#define PORT 21 // default port

using namespace std;


int loginToServer(Session*);

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
  if (loginToServer(&session) == 1) { // there was an error logging in
    return 1;
  } // else login was successful

  /* COMMAND PHASE */
  
  string input;    // user input
    cout << "";
    getline(cin, input);
  while (true) {
    input.clear(); // make sure input is empty before reading in

    cout << "ftp> ";
    getline(cin, input);
    cout << input;

    // get the cmd part of input
    string command = input;
    Command* cmd = dict.lookup(input.substr(0, command.find_first_of(" ")));

    cout << input << endl;
    if (cmd != NULL) {
      cmd->execute(&session, input);
    } else {
      cout << "Invalid command.\n";
    }
  }

  return 0;
}


/**
 * loginToServer
 * login to the server with the user account and password
 */
int loginToServer(Session* session) {

  Command* cmd = new Login; // get a login command
  
  if (cmd->execute(session) == 1) {
    return 1; // error
  }

  return 0;
}
