/* 
 * File:   Pasv.cpp
 * Author: kowalsky
 * 
 * Created on November 30, 2014, 2:47 PM
 */

#include "Pasv.h"

using namespace std;

int Pasv::execute(Session* session, string unused = "") {


  session->sendCmdToServer("PASV");
  // read server's reply to the message
  string reply = session->getServerReply();
  // check if reply is 530, an error
  if (!session->serverReplyEqualsCode(reply, "227")) {
    cerr << "Error in PASV." << endl;
    return 1;
  }
  // setup session with a port for data connection
  setupPort(session, reply); 
  // setup session's data connection
  session->setupDataSocket();

  //  it's the reponsibility of the next command to clean up
  // this data connection.
  return 0;
}


Pasv::~Pasv() {
    
}


void Pasv::setupPort(Session * session,string reply) {

  // from reply, calculate port number.
  // last part of reply is in the form (xxx,xxx,xxx,xx,yyy,zzz)
  // port = yyy*256+zzz

  // first step, get address and port by itself
  string ipAndPort = reply.substr(reply.find_first_of("(") + 1, 
				  reply.find_first_of(")"));
  // now we have a comma delimited string of numbers
  // put those numbers into a vector.
  stringstream ss(ipAndPort);
  vector<int> number;
  int i;

  // while there are comma delimited numbers
  while (ss >> i) {
    number.push_back(i);
    if (ss.peek() == ',' || ss.peek() == ')' ) {
      ss.ignore();
    }
  }
  // use last two numbers to find the port.
  //cout << number[4] * 256 + number[5] << endl;
  session->setPort(number[4] * 256 + number[5]);


}
