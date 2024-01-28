#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("%s\n","------------Packet Crafting for Improved Network Security------------");
    int domain = 0,type = 0, protocol = 0;
    int sock = socket(domain, type, protocol);
    printf("Socket returned: %d\n", sock);
    return 0;
}
