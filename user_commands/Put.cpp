/* 
 * File:   Put.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:47 PM
 */

#include "Put.h"

using namespace std;

int Put::execute(Session* session, string unused = "") {

  string localfile;
  string remotefile;
  // get name of local file we want to send to server
  cout << "(local-file) ";
  cin >> localfile;

  // get name of remote file we are creating at server
  cout << "(remote-file) ";
  cin >> remotefile;

  Command* cmd = new Pasv; // get a PASV command
  
  if (cmd->execute(session) == 1) {
    return 1; // error, pasv not successful
  }

  // session->dataport now refers to where the server is listening to the
  // data connection.

  session->sendCmdToServer("TYPE I");
  session->sendCmdToServer("STOR " + remotefile);

  session->sendFileToServer(localfile, remotefile);

  cout << "PUT about to teardown data socket" << endl;
  session->teardownDataSocket(); // destroy data socket in parent now we're done

  //session->sendCmdToServer("TYPE A"); // set mode back to ASCII
  return 0;
}


Put::~Put() {
    
}
