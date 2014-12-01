/** 
 * Session.cpp
 * @Author kowalsky
 * A session that a user accesses to issue commands to an FtP server.
 * The Receiver in the Command Pattern.
 * Created on November 30, 2014, 2:46 PM
 */

#include "Session.h"

/**
 * constructor
 * initialize the session.
 */
Session::Session() {
  this->username = "";
  this->authenticated = false;
  this->sock = NULL;
}

/**
 * destructor
 */
Session::~Session() {
  this->sock = NULL;
}

/**
 * setUsername
 * Set the username for the session to a given string.
 * Whenever username is changed, isAuthenticated becomes false.
 * @param username new username for the session.
 */
void Session::setUsername(std::string username) {
  this->username = username;
  this->authenticated = false;
}

/**
 * authenticate
 * using a password, authenticate the username associated with it
 * @param password password entered
 * @return whether or not the authentication was successful.
 */
bool Session::authenicate(std::string password) {
  // do authentication

  if (this->sock != NULL) { // if there is a socket connected


  }

  return authenticated; // so caller knows if password was accepted
}

/**
 * getUsername
 * Get the username for the session.
 * @return username associated with the session.
 */
std::string Session::getUsername() {
  return username;
}

/**
 * isAuthenticated
 * Returns whether or not a user is authenticated.
 * @return isAuthenticated or not
 */
bool Session::isAuthenticated() {
  return authenticated;
}
