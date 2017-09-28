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

#define PORT 1153
#define BUFSIZE 2048

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

   
int main(int argc, char **argv)
{
	struct sockaddr_in myaddr;      /* our address */
        struct sockaddr_in remaddr;     /* remote address */
        socklen_t addrlen = sizeof(remaddr);            /* length of addresses */
        int recvlen;                    /* # bytes received */
        int fd;                         /* our socket */
        unsigned char buf[BUFSIZE];     /* receive buffer */

        /* create a UDP socket */

        if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
                perror("cannot create socket\n");
                return 0;
        }

        /* bind the socket to any valid IP address and a specific port */

        memset((char *)&myaddr, 0, sizeof(myaddr));
        myaddr.sin_family = AF_INET;
        myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        myaddr.sin_port = htons(PORT);

        if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
                perror("bind failed");
                return 0;
        }

        /* now loop, receiving data and printing what we received */
        for (;;) {
                printf("waiting on port %d\n", PORT);
                recvlen = recvfrom(fd, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
                printf("received %d bytes\n", recvlen);
                if (recvlen > 0) {
                        buf[recvlen] = 0;
                        printf("received message: \"%s\"\n", buf);
                }
        }
        /* never exits */
}

