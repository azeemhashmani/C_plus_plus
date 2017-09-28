#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

using namespace std;

/*
sin --> May refer to Socket INternet
#include <netinet/in.h>
struct sockaddr_in6
{
    sa_family_t     sin6_family;
    in_port_t       sin6_port;
    uint32_t        sin6_flowinfo;
    uint32_t        sin6_addr;
    struct in6_addr sin6_addr;
    uint32          sin6_scope_id;
};

struct in6_addr
{
    unsigned char s6_addr[16];
};
*/

int main()
{
    int listenFd = 0;
    struct sockaddr_in6 serverAddress;
    struct sockaddr_in6 clientAddress;
    int clientLen;
    char recvBuff[1024] = {'\0'};
    int addrLen = 0;
    int port = 0; 
    char client_addr_ipv6[100];

    /* Create a socket */
    listenFd = socket(AF_INET6, SOCK_DGRAM, 0);

   /* Initialize everything to zero */
   memset(&serverAddress, '0', sizeof(serverAddress));
   memset(&recvBuff, '0', sizeof(sendBuff));


   serverAddress.sin6_family = AF_INET6;
   serverAddress.sin6_port = htons(5000);
//   serverAddress.sin6_addr = in6addr_any;
   inet_pton(AF_INET6, "fe80::2ea5:39ff:fe00:1981", &serverAddress.sin6_addr);
   serverAddress.sin6_scope_id = 4;
   bind(listenFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

   while(1)
   {
       cout << "Here \n";
       if (recvfrom(listedFd, recvBuff, sizeof(recvBuff), 0, (struct sockaddr*)&clientAddress, &clientLen) > 0)
       {
            cout << recvBuff;
       }

   }

   return 0;
}


