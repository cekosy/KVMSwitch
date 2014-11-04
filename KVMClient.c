#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <string.h>

#include <sys/socket.h>

#include <sys/stat.h>

#include <arpa/inet.h>

#define MAXBUF 256

int main()

{

    int ssock;

    int clen;

    struct sockaddr_in server_addr;

    char buf[MAXBUF];

    //Make socket

    if((ssock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)

    { perror("Failed to make socket descriptor");

        exit(1);

    }

    clen = sizeof(server_addr);

    //set connected address for socket

    memset(&server_addr, 0, sizeof(clen));

    server_addr.sin_family = AF_INET;

    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    server_addr.sin_port = htons(3317);

    //connect to setted address

    if(connect(ssock, (struct sockaddr *)&server_addr, clen) < 0 )

    { perror("Failed to connect socket");

        exit(1);

    }

    memset(buf, 0, MAXBUF);

    int readbytes;

    //read socket

    if(readbytes = read(ssock, buf, MAXBUF) <= 0)

    { perror("Failed to read socket");

        exit(1);

    }

    char writebuf[MAXBUF] = "Im client! Hi~ server~";

    if(write(ssock, writebuf, sizeof(writebuf)) < 0)

        perror("Failed to writing");

    close(ssock);

    //print to screen

    printf("\n[read] : %s\n\n", buf);

    return 0;

}

