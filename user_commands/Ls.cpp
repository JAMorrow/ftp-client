/* 
 * File:   Ls.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:47 PM
 */

#include "Ls.h"

using namespace std;

int Ls::execute(Session* session, string unused = "") {
  Command* cmd = new Pasv; // get a PASV command
  
  if (cmd->execute(session) == 1) {
    return 1; // error, pasv not successful
  }

  // session->dataport now refers to where the server is listening to the
  // data connection.

  // create a child to listen for the list 
   pid_t pid = fork();
  // let server know about the username.
  if (pid == 0) { // child process to check for list contents
    string reply = session->getDataFromServer();
    exit(0);
  } else if (pid > 0 ) { // parent
    // send list cmd
    session->sendCmdToServer("LIST");
    // wait for child to finish getting list
    int returnStatus;    
    waitpid(pid, &returnStatus, 0);
  } else { // error in fork
    cerr << "Fork error in Session!" << endl;
  }
session->teardownDataSocket(); // destroy data socket now we're done
  return 0;
}


Ls::~Ls() {
    
}
