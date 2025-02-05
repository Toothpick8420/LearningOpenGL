#ifndef UDP_H
#define UDP_H

#include <iostream>
#include <cstring> // ?

// Platform dependent includes

// Linux
#ifdef __linux__
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#ifdef _WIN32
#include <winsock2.h>
#endif

class UDPSocket {
public:
    UDPSocket();
    ~UDPSocket();

    void bindSocket(const std::string & addr, uint16_t port);
    void send(const std::string & data, const std::string & addr, uint16_t port);
    std::string recv();

private:
    int sockfd;

};

#endif
