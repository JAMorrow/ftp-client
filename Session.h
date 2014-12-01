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

class Session {
public:
    Session();
    virtual ~Session();
    
    // set methods
    void setUsername(std::string);
    bool authenicate(std::string);
    void setSocket(Socket sock);

    // get methods
    std::string getUsername();
    bool isAuthenticated();

private:
    Socket* sock; // a socket used to communicate with the server
    std::string username; // a user to be associated with the session
    bool authenticated; // whether or not the user is authenticated by the
    // server
};

#endif	/* SESSION_H */

