/* 
 * File:   Login.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:47 PM
 */

#include "Login.h"

using namespace std;

int Login::execute(Session* session, string unused = "") {

  /* SEND USERNAME */
  string username;
  // print name prompt that includes user's computer info
  // TODO get computer info

  string userString( getlogin() ); // gets the name of the user on this pc
  cout << "Name (" << session->getServerIP() << ":" << userString << "): ";
  cin >> username;
 
  if (!session->setUsername("USER " + username)) {
    return ERROR;
  }


  /* SEND PASSWORD */

  string password = getPassword();

  // give password to session to authenticate.
  if (!session->authenticate("PASS " + password)) {
    return ERROR; // password not authenticated.
  } // else it was authenticated successfully.


  /* SEND SYST to server */

  session->sendCmdToServer("SYST");
  session->getServerReply();

  return 0;
}


Login::~Login() {
    
}

string Login::getPassword() {
  string password;
  cout << "Password: ";

  // // this code hides the password on the console window as it is typed.
  // termios oldt;
  // tcgetattr(STDIN_FILENO, &oldt);
  // termios newt = oldt;
  // newt.c_lflag &= ~ECHO;
  // tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  cin >> password; // get password while cloaked
  // // set terminal back to normal mode.
  // tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  // output a CRLF to keep console looking aligned
  //cout << endl;
  return password;
}
