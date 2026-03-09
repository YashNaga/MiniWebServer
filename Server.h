#ifndef Server_h
#define Server_h

#include <netinet/in.h>
#include <sys/socket.h>

struct Server {
        int domain;
        int protocol;
        int service;
        u_long interface;
        int port;
        int backlog;

        struct sockaddr_in address;

        int socket;

        void (*launch)(struct Server* server);
};

struct Server server_constructor(int domain, int protocol, int service, u_long interface, int port, int backlog,
                                 void (*launch)(struct Server* server));

#endif  // Server_h
