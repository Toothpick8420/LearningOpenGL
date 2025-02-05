#include "udp.h"

int main() {
    UDPSocket socket;
    
    while (true) {
        std::cout << "Enter message: ";
        std::string msg;
        std::getline(std::cin, msg);

        socket.send(msg, "127.0.0.1", 12345);
    }

}
