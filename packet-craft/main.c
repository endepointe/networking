// use command: ldd --version
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main(void) {
    printf("%s\n","-----Packet Crafting for Improved Network Security-----");  

    int status = 0;
    char ipstr[INET6_ADDRSTRLEN];
    struct addrinfo hints, *servinfo, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo("endepointe.com","ftp", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n",gai_strerror(status));
        exit(1);
    };
    printf("getaddrinfo status: %d\n",status);
    for (res = servinfo; res != NULL; res = res->ai_next) {
        void *addr;
        char *ipver;
        if (res->ai_family == AF_INET) {
            struct sockaddr_in *ipv4 = (struct sockaddr_in*)res->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPV4";
            break;
        } else {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6*)res->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPV6";
            break;
        }

        inet_ntop(res->ai_family, addr, ipstr, sizeof(ipstr));
        printf(" %s: %s\n", ipver, ipstr);
    }

    //int sock = socket(domain, type, protocol);
    //printf("Socket returned: %d\n", sock);
    
    freeaddrinfo(servinfo);
    return 0;
}
