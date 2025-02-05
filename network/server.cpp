#include "udp.h"

int main() {
    UDPSocket socket;
    socket.bindSocket("127.0.0.1", 12345);

    while (true) {
        std::string msg = socket.recv();
        std::cout << "Server receieved: " << msg << std::endl;
    }
}

