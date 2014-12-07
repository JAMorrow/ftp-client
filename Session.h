/* 
 * File:   Session.h
 * Author: kowalsky
 *
 * Created on November 30, 2014, 2:46 PM
 */

#ifndef SESSION_H
#define	SESSION_H

#include <cstring>
#include <string>

#include "utilities/Socket.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // for fork
#include <sys/types.h>
#include <sys/wait.h>
#include <poll.h>  // to poll socket
 
#define BUFFERSIZE 1500

class Session {

public:
  Session( int, char[] );
  virtual ~Session();
    
  // set methods
  bool setUsername(std::string);
  bool authenticate(std::string);
  void setPort(int);

  // get methods
  std::string getUsername();
  bool isAuthenticated();

  // Socket access methods
  void sendCmdToServer(std::string); // send a given string to the server
                                       // with CRLF

  std::string getServerReply(); // get the current server reply, display it,
                                // and return it as a string

  bool serverReplyEqualsCode(std::string, std::string); // checks if the
                                // server's reply code matches the given code.


  void setupDataSocket();

  void teardownDataSocket();

  std::string getDataFromServer();

  char * getServerIP();

  int getDataPort();

  std::string doRead(int);

private:
  Socket * ctrl;            // control socket used to interact with the server
  int ctrlsd;               // our control socket descriptor
  char message[BUFFERSIZE]; // array to hold messages to and from server
  Socket * data;            // data socket used to interact with the server
  int datasd;               // our data socket descriptor
  char * serverIp;          // IP of the server we're connected to
  int dataport;             // port number from PASV, -1 if not intialized.


  std::string username; // a user to be associated with the session
  bool authenticated;   // whether or not the user is authenticated by the
                        // server
};

#endif	/* SESSION_H */

