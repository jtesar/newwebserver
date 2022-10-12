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
#include "control_loop.h"
using namespace std;
 
int main()
{
    // Two buffers for message communication
    char buffer1[256], buffer2[1024];
    int server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0)
        printf("Error in server creating\n");
    else
        printf("Server Created\n");
         
    struct sockaddr_in my_addr, peer_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
     
    // This ip address will change according to the machine
    my_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
     
    my_addr.sin_port = htons(8080);
 
    if (bind(server, (struct sockaddr*) &my_addr, sizeof(my_addr)) == 0)
        printf("Binded Correctly\n");
    else
        printf("Unable to bind\n");
         
    if (listen(server, 3) == 0)
        printf("Listening ...\n");
    else
        printf("Unable to listen\n");
     
    ctrl_loop(server, &peer_addr);

    return 0;
}
