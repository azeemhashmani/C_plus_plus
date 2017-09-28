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

using namespace std;

int main()
{
    int socketFd = 0;
    int n = 0;
    char sendBuff[1024];
    struct sockaddr_in6 serverAddress;

    if (socketFd = socket(AF_INET6, SOCK_DGRAM, 0) < 0)
    {
        perror("Cannot create socket :");
        return -1;
    }

    memset(sendBuff, 0, sizeof(recvBuff));
    memset(&serverAddress, 0, sizeof(serverAddress));

    // Initialized the address
    serverAddress.sin6_family = AF_INET6;
    serverAddress.sin6_port = htons(5000);

    inet_pton(AF_INET6, "fe80::2ea5:39ff:fe00:1981", &serverAddress.sin6_addr);

    /* This field is only used for local scope(i.e. link-local, sitelocal) unicast IPV6 addresses.
     * For global scope unicast IPv6 addresses, as well as for IPv5 addresses. this field is not used and should be set to 0. 
     *  When the IPv6 address is link-local scope unicast Pv6 address, then sin6_scope_id must be set to interface index of interface associated with the IP address. When the IPv6 address is a 
     * site-local scope unicast IPv6 address, then sin6_scope_id must be set to the site identifier of the site (i.e. set of interface) associated with that IP adress refer to tf6InterfaceSetSiteId().
     */
    serverAddress.sin6_scope_id = 4; 

    /* send a message to the server */
    if (sendto(fd, "Hi Server", strlen("Hi Server"), 0, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("sendto failed");
        return 0;
    
    return 0;
}
