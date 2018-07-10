#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <net/if.h>

using namespace std;

int main()
{
    struct sockaddr_in6 clientAddress;
    int socketFd = 0;
    char sendBuff[1024] = "Hi from client";
    struct iovec iovec;
    struct msghdr msg;
    struct ipv6_mreq mreq;

    socketFd = socket(PF_INET6, SOCK_DGRAM, 0);
    if (socketFd == -1)
    {
        perror("Cannot create socket :");
        return -1;
    }
    memset(&clientAddress, 0, sizeof(clientAddress));

    // Initialized the address
    clientAddress.sin6_family = AF_INET6;
    clientAddress.sin6_port = htons(6692);
    clientAddress.sin6_scope_id = 0; 

    // No need to join membership when you are sending data.
    // sin6_addr is the group address the server will join to receive data.
    inet_pton(AF_INET6, "ff12:0:0:0:0:0:80FF:F1F2", &clientAddress.sin6_addr);

    bind(socketFd, (struct sockaddr*)&clientAddress, sizeof(clientAddress));
    iovec.iov_base = (void*)sendBuff;
    iovec.iov_len = sizeof(sendBuff);
    memset(&msg, 0, sizeof(msg));
    msg.msg_name = (struct sockaddr*)&clientAddress;
    msg.msg_namelen = sizeof(struct sockaddr_in6);
    msg.msg_iov = &iovec;
    msg.msg_iovlen = 1;

    if(sendmsg(socketFd, &msg, 0) > 0)
    {
        printf("Success sending data \n");
        return 0;
    }
    else
    {
        perror("Failed sending data: \n");
        return -1;
    }
}
