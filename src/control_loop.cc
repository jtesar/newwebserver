#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include <iostream>
#include <fstream>
using namespace std;
 
void ctrl_loop(int server, sockaddr_in *peer_addr) {
     
    socklen_t addr_size;
    addr_size = sizeof(struct sockaddr_in);
    char buffer1[256], buffer2[1024];
     
    // Ip character array will store the ip address of client
    char *ip;
     
    // while loop is iterated infinitely to
    // accept infinite connection one by one
    while (1)
    {
        int acc = accept(server, (struct sockaddr*) peer_addr, &addr_size);
        printf("Connection Established\n");
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(peer_addr->sin_addr), ip, INET_ADDRSTRLEN);
     
        // "ntohs(peer_addr.sin_port)" function is
        // for finding port number of client
        printf("connection established with IP : %s and PORT : %d\n",
                                            ip, ntohs(peer_addr->sin_port));
 
        recv(acc, buffer2, 256, 0);
        printf("Client : %s\n", buffer2);
        strcpy(buffer1, "HTTP/1.1 200 OK\nCache-Control: no-cache\nServer: Myserver\nContent-Type: text/html\n\n");
        send(acc, buffer1, strlen(buffer1), 0);

        string line;
        ifstream myfile ("/var/www/html/index.html");
        if (myfile.is_open())
        {
          while ( getline (myfile,line) )
          {
            line += "\n";
            send(acc,line.c_str(),line.length(),0);
          }
          myfile.close();
        }
	else
	{
	    line = "Cannot open index.html in /var/www/html/.\nBut welcome anyway :-)\n";
            send(acc,line.c_str(),line.length(),0);
	}

    }
}
