#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Server.h"

void launch(struct Server *server) {
    char buffer[30000];
    int address_length = sizeof(server->address);
    printf("......WAITING.......");

    while(1) {
        int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);
        read(new_socket, buffer, 30000);
        
        char* response = "HTTP/1.1 200 OK\r\n"
                        "Header: value\r\n"
                        "Header: value\r\n"
                        "\r\n"
                        "Hello World!";
        printf("%s\n", buffer);
        
        write(new_socket, response, strlen(response));
        close(new_socket);
    }
}

int main() {
    struct Server server = server_constructor(AF_INET, 0, SOCK_STREAM,  INADDR_ANY, 9090, 10, launch);
    server.launch(&server);
}
