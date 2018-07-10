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
#include <net/if_arp.h>
#include <libexplain/setsockopt.h>
#include <netinet/in.h>
#include <linux/ip.h>

using namespace std;

int main()
{
    int socketFd = 0;
    char recvBuff[1024];
    struct sockaddr_in6 serverAddress;
    struct sockaddr_in6 from;
    unsigned int fromLen;
    socklen_t clientLen = sizeof(struct sockaddr_in6);
    struct ipv6_mreq mreq;
    struct sockaddr_in6 groupStruct;

    // Initialize multicast
    memset(&mreq, 0, sizeof(mreq));
    inet_pton(AF_INET6, "ff12:0:0:0:0:0:80FF:F1F2", &mreq.ipv6mr_multiaddr);
    mreq.ipv6mr_interface = 0;

    // Create socket
    socketFd = socket(AF_INET6, SOCK_DGRAM, 0);
    if (socketFd == -1)
    {
        perror("Failed to create socket : ");
        return -1;
    }

    // Initialized the address
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin6_family = AF_INET6;
    serverAddress.sin6_port = htons(6692);
    serverAddress.sin6_scope_id = 0;
   
    // Add membership  
    if(setsockopt(socketFd, IPPROTO_IPV6, IPV6_ADD_MEMBERSHIP, (char*)&mreq, sizeof(mreq)))
    {
        perror("Failed to Add IPV6 membership : ");
        return -1;
    }

    bind(socketFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
 
    memset(recvBuff, 0, sizeof(recvBuff));
    if (recvfrom(socketFd, recvBuff, sizeof(recvBuff), 0, (struct sockaddr*)&from, &fromLen) > 0)
    {
        cout << recvBuff << endl;
    }
    else
    {
        perror("Failed receiving data: ");
    }

    return 0;
}
