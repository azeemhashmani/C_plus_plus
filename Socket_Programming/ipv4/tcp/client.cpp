#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string.h>

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

    int socketFd = 0;
    int n = 0;
    char recvBuff[1024] = {'\0'};
    struct sockaddr_in clientAddr;

    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    memset(recvBuff, 0, sizeof(recvBuff));
    memset(&clientAddr, 0, sizeof(clientAddr));

    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(5000);

    // Server address in our case its loop back
    inet_pton(AF_INET, "127.0.0.1", &clientAddr.sin_addr);

    if (connect(socketFd, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) < 0)
    {
        perror("Connection failed : ");
    }



    read(socketFd, recvBuff, sizeof(recvBuff)-1);


     cout << "Reading Data from server : " << recvBuff;

    return 0;
}
