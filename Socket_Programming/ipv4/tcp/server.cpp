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
struct sockaddr_in
{
    short            sin_family; //Size = 2bytes.This defined the family of internet. AF_INET is Address Family Internet and PF_NET is Protocol Family Internet 
    unsigned short   sin_port; // Size = 2 bytes. Defines the port we can use 
    struct in_addr   sin_addr; // Size = 2 bytes . Defines the 32 bit ipv4 address
    char             sin_zero[8]; // Size = 8 bytes. Used for future implementation and padding to make the struct 16 byte
};

struct in_addr 
{
    unsigned long s_addr; // load with inet_aton
};

*/

int main()
{

    int listenFd = 0;
    int newFd = 0;
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
    char sendBuf[1024] = {'\0'};
    char *clientAddr = NULL;
    int addrLen;
    time_t ticks; 
    int ret;
    int port;

    /* int socket(int domain, int type, int protocol);
     * domain - AF_INET is used for IPv4 protocols 
     * type   - SOCK_STREAM for streams socket and SOCK_DGRAM for datagram sockets
     * protocol - int sock_udp = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP), int sock_tcp = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     * Stream socket - Dedicated and point to point commn, Used TCP protocol for data transmission, reliable and lossless, order maintained, recover is easy
     * Datagram socket - No dedicated point to point commn, Uses UDP protocol for data transmission, not reliable, order not maintained, not rapid in recovery
     */
    listenFd = socket(AF_INET, SOCK_STREAM, 0); 

    /* Initialize everything to zero */
    memset(&serverAddress, '0', sizeof(serverAddress));
    memset(&clientAddress, '0', sizeof(clientAddress));
    memset(&sendBuf, '0', sizeof(sendBuf));
    
    strcpy(sendBuf, " Hello Client \n");

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(5000);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);


    /* int bind(int socket, const struct sockaddr *address, socklen_t address_len);
     * socket - Specifies the file descriptor of the socket to be bound
     * address - Points to sockaddr struct containing the address to be binded with the socket.
     * address_len - Length of sockaddr strcuture pointed by address argument
     */
    bind(listenFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));


    /* int listen(int socket, int backlog);
     * socket argument is a fd that refers to socket type SOCK_STREAM, SOCK_DGRAM
     * backlog - Maximum lenght of queue of pending connections for socket may grow. If connection queue is full client may receive an error
     */
    listen(listenFd, 1);

    /* int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
     * accept function shall extract the first connection on the queue of pending connections, create a new socket with same socket type protocol and address family as specified and
     * allocate a new file descriptor for that socket
     * This system call is used with connection-based socket types (SOCK_STREAM, SOCK_SEQPACKETS).
     * The original socket is unaffected by this state and newly created socket is not in listening state
     */
     addrLen = sizeof(clientAddress);


     while(1)
     {
        newFd = accept(listenFd, (struct sockaddr*)&clientAddress, (socklen_t*)&addrLen); 

        //ret = getpeername(newFd, (struct sockaddr*)&clientAddress, (socklen_t*)&addrLen);
        if (ret < 0)
        {
            perror("Peer name error: ");
        }
        clientAddr = inet_ntoa(clientAddress.sin_addr);
        cout << "Peer address " << clientAddr  << endl;

        port = ntohs(clientAddress.sin_port);
        cout << "Port " << port;

        write(newFd, sendBuf, strlen(sendBuf)); 

        close(newFd);
     }

    return 0;
}
   


