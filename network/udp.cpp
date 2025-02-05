#include "udp.h"

UDPSocket::UDPSocket() {
    #ifdef _WIN32
    // Winsock for windows
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed with error: " << WSAGetLastError() << std::endl;
        exit(1);
    }
    #endif

    // Create the socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Socket creation failed." << std::endl;
        exit(1);
    }
}


UDPSocket::~UDPSocket() {
    // Close the socket 
    #ifdef _WIN32 
        closesocket(sockfd);
        WSACleanup();
    #else 
        close(sockfd);
    #endif
}


void UDPSocket::bindSocket(const std::string & address, uint16_t port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);    
    addr.sin_addr.s_addr = inet_addr(address.c_str());

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "Bind failed!" << std::endl;
        exit(1);
    }
}


void UDPSocket::send(const std::string & data, const std::string & address, uint16_t port) {
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    dest.sin_addr.s_addr = inet_addr(address.c_str());

    int sent = sendto(sockfd, data.c_str(), data.size(), 0, (struct sockaddr*)&dest, sizeof(dest));
    if (sent < 0) {
        std::cerr << "Send failed!" << std::endl;
    }
}


std::string UDPSocket::recv() {
    struct sockaddr_in sender;
    char buffer[1024];

    int received = -1;    
    
    #ifdef __linux__ 
        socklen_t senderSize = sizeof(sender);
        received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&sender, &senderSize);
    #else
        int senderSize = sizeof(sender);
        received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&sender, &senderSize);
    #endif

    if (received < 0) {
        std::cerr << "Recv failed!" << std::endl;
        return "";
    }

    return std::string(buffer, received);
}
