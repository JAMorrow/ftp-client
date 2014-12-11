/* 
 * File:   Get.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:47 PM
 */

#include "Get.h"

using namespace std;

int Get::execute(Session* session, string fn = "") {

  //string fn has the form get <filename,> get rid of get so we just
  // have filename

  string filename = fn.substr(fn.find_first_of(" "), fn.length() -1);
  //cout << filename << endl;


  Command* cmd = new Pasv; // get a PASV command
  
  if (cmd->execute(session) == 1) {
    return 1; // error, pasv not successful
  }

  // session->dataport now refers to where the server is listening to the
  // data connection.


  // tell server to enter binary mode for write
  session->sendCmdToServer("TYPE I");

  // create a child to manage the data transfer.
  pid_t pid = fork();
  // let server know about the username.
  if (pid == 0) { // child process
    session->getFileFromServer(filename);
    session->teardownDataSocket(); // destroy data socket now we're done
    exit(0);
  } else if (pid > 0 ) { // parent
    // send list cmd
    session->sendCmdToServer("RETR " + filename);
    // wait for child to finish getting list
    int returnStatus;    
    waitpid(pid, &returnStatus, 0);
  } else { // error in fork
    cerr << "Fork error in Session!" << endl;
  }
  session->teardownDataSocket(); // destroy data socket in parent now we're done

  // return to ASCII mode by default
  session->sendCmdToServer("TYPE A");
  return 0;
}


Get::~Get() {
    
}
