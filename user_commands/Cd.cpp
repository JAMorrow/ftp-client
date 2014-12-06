/* 
 * File:   Cd.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:47 PM
 */

#include "Cd.h"

using namespace std;

int Cd::execute(Session* session, string cd = "") {

  //string cd has the form cd <directory>
  // get rid of cd so we just have directory

  string directory = cd.substr(cd.find_first_of(" "), cd.length() -1);
  cout << directory << endl;

  session->sendCmdToServer("CWD " + directory);
  // read server's reply to the message
  string reply = session->getServerReply();
  // check if reply is 530, an error
  if (!session->serverReplyEqualsCode(reply, "250")) {
    cerr << "Error in changing directory." << endl;
  }

  return 0;
}

Cd::~Cd() {
    
}
