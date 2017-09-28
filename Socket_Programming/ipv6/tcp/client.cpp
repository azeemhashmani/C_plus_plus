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

#define SUCCESS 0

using namespace std;

int main()
{
    int socketFd = 0;
    int n = 0;
    char recvBuff[1024];
    struct sockaddr_in6 clientAddress;
    struct tm timeStamp;

    socketFd = socket(AF_INET6, SOCK_STREAM, 0);
    memset(recvBuff, 0, sizeof(recvBuff));
    memset(&clientAddress, 0, sizeof(clientAddress));

    // Initialized the address
    clientAddress.sin6_family = AF_INET6;
    clientAddress.sin6_port = htons(5000);

    inet_pton(AF_INET6, "::1", &clientAddress.sin6_addr);

    /* This field is only used for local scope(i.e. link-local, sitelocal) unicast IPV6 addresses.
     * For global scope unicast IPv6 addresses, as well as for IPv5 addresses. this field is not used and should be set to 0. 
     *  When the IPv6 address is link-local scope unicast Pv6 address, then sin6_scope_id must be set to interface index of interface associated with the IP address. When the IPv6 address is a 
     * site-local scope unicast IPv6 address, then sin6_scope_id must be set to the site identifier of the site (i.e. set of interface) associated with that IP adress refer to tf6InterfaceSetSiteId().
     */
    //clientAddress.sin6_scope_id = 4;

    if (SUCCESS == connect(socketFd, (struct sockaddr*)&clientAddress, sizeof(clientAddress)))
    {
        //read(socketFd, recvBuff, sizeof(recvBuff));
        read(socketFd, &timeStamp, sizeof(struct tm));
        //cout << "Reading data from server : " << recvBuff;
        cout << "Reading data from server : " << timeStamp.tm_hour << ":" << timeStamp.tm_min << ":" << timeStamp.tm_sec << endl;
    }
    return 0;
}
