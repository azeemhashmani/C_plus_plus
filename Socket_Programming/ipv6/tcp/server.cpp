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
    int newFd = 0;
    struct sockaddr_in6 serverAddress;
    struct sockaddr_in6 clientAddress;
    char sendBuff[1024] = {'\0'};
    int addrLen = 0;
    int port = 0; 
    char client_addr_ipv6[100];
    struct tm *timeStamp;
    time_t rawTime;

    rawTime = time(NULL);
    timeStamp = localtime(&rawTime);
    
    cout << timeStamp->tm_min << endl;
    /* Create a socket */
    listenFd = socket(AF_INET6, SOCK_STREAM, 0);

   /* Initialize everything to zero */
   memset(&serverAddress, '0', sizeof(serverAddress));
   memset(&clientAddress, '0', sizeof(clientAddress));
   memset(&sendBuff, '0', sizeof(sendBuff));

   strcpy (sendBuff, "Hello Client");

   serverAddress.sin6_family = AF_INET6;
   serverAddress.sin6_port = htons(5000);
   serverAddress.sin6_addr = in6addr_any;


   bind(listenFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

   listen(listenFd, 1);

   addrLen = sizeof(clientAddress);

   while(1)
   {
       newFd = accept(listenFd, (struct sockaddr*)&clientAddress, (socklen_t*)&addrLen);

       inet_ntop(AF_INET6, &(clientAddress.sin6_addr), client_addr_ipv6, 100);
       cout << "Peer address " << client_addr_ipv6  << endl;

       port = ntohs(clientAddress.sin6_port);
       cout << "Port " << port;

//       write(newFd, sendBuff, strlen(sendBuff));
       write(newFd, timeStamp, sizeof(struct tm));

       close(newFd);
   }

   return 0;
}


