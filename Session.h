/* 
 * File:   Session.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:46 PM
 */

#ifndef SESSION_H
#define	SESSION_H

#include <string>
#include "utilities/Socket.h"
#include <stdlib.h>

#define BUFFERSIZE 1500

class Session {

public:
  Session( int, char[] );
  virtual ~Session();
    
  // set methods
  void setUsername(std::string);
  bool authenicate(std::string);

  // get methods
  std::string getUsername();
  bool isAuthenticated();

  // Socket access methods
  std::string getServerReply(); // get the current server reply, display it,
                                // and return it as a string

  bool serverReplyEqualsCode(std::string, std::string); // checks if the
                                // server's reply code matches the given code.

private:
  Socket * sock;            // socket used to communicate with the server
  int sd;                   // our client socket descriptor
  char message[BUFFERSIZE]; // array to hold messages to and from server


  std::string username; // a user to be associated with the session
  bool authenticated;   // whether or not the user is authenticated by the
                        // server
};

#endif	/* SESSION_H */

