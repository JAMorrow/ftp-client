/* 
 * File:   Quit.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:47 PM
 */

#include "Quit.h"

using namespace std;

int Quit::execute(Session* session, string unused = "") {

  session->sendCmdToServer("QUIT");
  session->getServerClosingReply();

  return 0;
}


Quit::~Quit() {
    
}
