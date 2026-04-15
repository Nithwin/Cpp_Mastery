#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

using namespace std;

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // ---------------------------------------------------------
    // TODO 1: Create the raw socket. 
    // We want IPv4 (AF_INET) and TCP (SOCK_STREAM).
    // server_fd = ?????(AF_INET, SOCK_STREAM, 0);
    // ---------------------------------------------------------
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) { cout << "Socket creation failed\n"; return -1; }

    // Configuration for the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on any IP address
    address.sin_port = htons(8080);       // Listen on Port 8080
    cout << "Ip add: " << address.sin_addr.s_addr <<"\n";

    // ---------------------------------------------------------
    // TODO 2: Attach the socket to Port 8080.
    // ?????(server_fd, (struct sockaddr *)&address, sizeof(address));
    // ---------------------------------------------------------
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    // ---------------------------------------------------------
    // TODO 3: Tell the socket to wait for incoming connections.
    // ?????(server_fd, 3); // 3 is the maximum queue size
    // ---------------------------------------------------------
    listen(server_fd, 3);
    cout << "Server is running. Waiting for connections on Port 8080...\n";

    // ---------------------------------------------------------
    // TODO 4: Wait and grab the first person who connects!
    // client_socket = ?????(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    // ---------------------------------------------------------
    client_socket = accept(server_fd,(struct sockaddr *)&address, (socklen_t*)&addrlen);
    cout << "A Client has connected!\n";

    // We send a welcome message using the TCP socket!
    const char* hello = "Welcome to the Alcatel-Lucent Trial Server!\n";
    send(client_socket, hello, strlen(hello), 0);
    cout << "Message sent to client.\n";

    // Close the sockets to prevent memory and file descriptor leaks
    close(client_socket);
    close(server_fd);

    return 0;
}