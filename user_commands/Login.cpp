/* 
 * File:   Login.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:47 PM
 */

#include "Login.h"

using namespace std;

int Login::execute(Session* session) {

  /* SEND USERNAME */
  string username;
  // print name prompt that includes user's computer info
  // TODO get computer info
  cout << "Name (here be comp info): " << endl;
  cin >> username;
 
  // prompt for new username if this one fails
  while (!session->setUsername(username)) {
    cout << "Name (here be comp info): " << endl;
    cin >> username;
  }

  /* SEND PASSWORD */

  string password;
  cout << "Password: ";
  cin >> password;
  // // this code prevents the typed password from appearing 
  // // in the console window as it is typed for security.
  // termios oldt;
  // tcgetattr(STDIN_FILENO, &oldt);
  // termios newt = oldt;
  // newt.c_lflag &= ~ECHO;
  // tcsetattr(STDIN_FILENO, TCSANOW, &newt);


  // getline(cin, password);


  // give password to session to authenticate.
  if (!session->authenticate(password)) {
    return ERROR; // password not authenticated.
  } // else it was authenticated successfully.


    cout << password << endl;
 
    string mess;
    cin >> mess;
    cout << mess;


  return 0;
}


Login::~Login() {
    
}

