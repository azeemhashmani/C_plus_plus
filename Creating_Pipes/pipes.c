/* pipe() creates a pipe, a unidirectional data channel that can be used for interprocess communication.
The argument of pipe() is used to return two file descriptors referring tho ends of the pipe. */

/* If the child wants to send data to parent, it should close fd[0] and parent should close fd[1].
   If the parent wants to send data to child, it should close fd[0] and child should close fd[1].
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd[2], nBytes;
    pid_t childPid;
    char string[] = "Hello, world using pipes";
    char readStr[100];

    pipe(fd);

    if((childPid = fork()) == -1)
    {
        perror("Fork");
        exit(1);
    }

    if(childPid == 0)
    {
        close(fd[0]);

        write(fd[1], string, (strlen(string) + 1));
        exit(0);
    }
    else
    {
        close(fd[1]);
        
        nBytes = read(fd[0], readStr, sizeof(readStr));

        printf("Received String: %s \n", readStr);
    }

     return 0;
}
