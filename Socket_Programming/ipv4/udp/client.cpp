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

#define PORT 1153
#define BUFSIZE 2048

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
    int fd;
    struct sockaddr_in servaddr;    /* server address */
    char my_messsage[100] = "this is a test message";


    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
	perror("cannot create socket");
	return 0;
    } 


    /* fill in the server's address and data */
    memset((char*)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(1153);


    /* put the host's address into the server address structure */
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    /* send a message to the server */
    if (sendto(fd, "Hi Server", strlen("Hi Server"), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
	perror("sendto failed");
	return 0;
    }

    return 0;
}
