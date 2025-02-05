#include "udp.h"

int main() {
    UDPSocket socket;

    socket.bindSocket("127.0.0.1", 12345);
    socket.send("Hello, World", "127.0.0.1", 12345);
    std::string msg = socket.recv();

    std::cout << "Got: " << msg << std::endl;

    return 0; 
}
