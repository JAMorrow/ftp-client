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
Session::Session( int port, char ipName[] ) {
  this->username = "";
  this->authenticated = false;
  this->sock = new Socket(port); // create a socket listening to that port

  //std::cout << "setup socket with port " << port << std::endl;

  // tell it the ip address to listen to.
  this->sd = this->sock->getClientSocket(ipName);

  if (this->sd == -1) {  // connection was unsuccessful
    std::cerr << "Error: Not connected to server." << std::endl;
  }
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


/**
 * getServerReply
 * Prints the current server reply to console and returns a string
 * of the server message.
 * @return a string version of the reply
 */
std::string Session::getServerReply() {

  read(sd, message, BUFFERSIZE);      // Get server's reply

  // We need to find the end of the message, since it is probably shorter
  // than BUFFERSIZE.
  // A simple solution is to convert the message to a string, and then
  // get the substring that starts from the beginning of the string to the 
  // terminating character.
  std::string temp(message);   // convert message to string
  std::size_t position = temp.find("\n"); // find the end of the string
  std::string reply = temp.substr(0, position); // create answer string.
  // note: substr starts at 0, and ends at the position of the '\n'

  std::cout << reply << std::endl;  // Display reply

  return reply;
}


/**
 * serverReplyEqualsCode
 * Compares code given by server to code entered by user.
 * @return true if a match, false if not.
 */
bool Session::serverReplyEqualsCode(std::string reply, std::string code) {
  
  // compare the 1st three characters of reply to the given code.
  if (reply.compare(0,3,code) == 0) {
    return true;
  } else {
    return false;
  }
}
