/* 
 * File:   Socket.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 4:49 PM
 */

#include "Socket.h"

Socket::Socket(int port)
: port(port), clientFd(NULL_FD), serverFd(NULL_FD) {
}

Socket::~Socket() {
    if (clientFd != NULL_FD)
        close(clientFd);
    if (serverFd != NULL_FD)
        close(serverFd);
}

int Socket::getClientSocket(char ipName[]) {
    return getClientSocket(ipName, 0, false);
}

int Socket::getClientSocket(char ipName[], int sndbufsize, bool nodelay) {

    // Get the host entry corresponding to ipName
    struct hostent* host = gethostbyname(ipName);
    if (host == NULL) {
        perror("Cannot find hostname.");
        return NULL_FD;
    }

    // Fill in the structure "sendSockAddr" with the address of the server.
    sockaddr_in sendSockAddr;
    bzero((char*) &sendSockAddr, sizeof ( sendSockAddr));
    sendSockAddr.sin_family = AF_INET; // Address Family Internet
    sendSockAddr.sin_addr.s_addr =
            inet_addr(inet_ntoa(*(struct in_addr*) *host->h_addr_list));
    sendSockAddr.sin_port = htons(port);

    // Open a TCP socket (an Internet strem socket).
    if ((clientFd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Cannot open a client TCP socket.");
        return NULL_FD;
    }

    // Set the rcvbuf option
    if (sndbufsize > 0) {
        cout << sndbufsize << endl;
        if (setsockopt(clientFd, SOL_SOCKET, SO_SNDBUF,
                (char *) &sndbufsize, sizeof ( sndbufsize)) < 0) {
            perror("setsockopt SO_SNDBUF failed");
            return NULL_FD;
        }
    }

    // Set the nodelay option
    if (nodelay == true) {
        int on = 1;
        if (setsockopt(clientFd, IPPROTO_TCP, TCP_NODELAY,
                (char *) &on, sizeof ( int)) < 0) {
            perror("setsockopt TCP_NODELAY failed");
            return NULL_FD;
        }
    }

    // Connect to the server.
    while (connect(clientFd, (sockaddr*) & sendSockAddr,
            sizeof ( sendSockAddr)) < 0);

    // Connected
    return clientFd;
}

int Socket::pollRecvFrom() {

  struct pollfd pfd[1];
  pfd[0].fd = clientFd;       // declare I'll check the data availability of sd
  pfd[0].events = POLLRDNORM; // declare I'm interested in only reading from sd

  // check it for 2 seconds and return a positive number if sd is readable,
  // otherwise return 0 or a negative number
  return poll( pfd, 1, 1000 );

}
