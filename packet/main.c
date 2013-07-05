#include <sys/socket.h>
//#include <netpacket/packet.h>
#include <net/ethernet.h> /* the L2 protocols */
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
//#include <net/if.h>  
#include <linux/if_arp.h>

static int _get_id(int fd, const char *device)
{
    struct ifreq    req;
    
    memset(&req, 0, sizeof(req));
    snprintf(req.ifr_name, sizeof(req.ifr_name), "%s", device);

    if (ioctl(fd, SIOCGIFINDEX, &req) == -1) {
        printf("SIOCGIFINDEX failed\n");
        return -1;
    }

    return req.ifr_ifindex;
}

int main(int argc, char **argv) 
{
    struct sockaddr_ll socket_address;
    int sock;
    char buffer[256];
    const char *martin = "martin";
    unsigned char src_mac[6] = {0xde, 0xad, 0xbe, 0xef, 0x0, 0x0};
    unsigned char dest_mac[6] = {0xa, 0xb, 0xc, 0xd, 0xe, 0xf};
    char *p = buffer;
    memset(p, 0, sizeof(buffer));

    printf("hello\n");
    sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock == -1) {
        printf("cannot open packet socket\n");
        return 1;
    }   

    socket_address.sll_ifindex  = _get_id(sock, "eth1");
    printf("using ifindex %d\n", socket_address.sll_ifindex);

    memcpy((void*)p, (void*)dest_mac, ETH_ALEN);
    p += ETH_ALEN;
    memcpy((void*)p, (void*)src_mac, ETH_ALEN);
    p += ETH_ALEN;
    memset(p, 0, 2);
    p += 2;

    memcpy(p, martin, strlen(martin));
    while (1) {
        int sent = sendto(sock, buffer, sizeof(buffer), 0, 
	          (struct sockaddr*)&socket_address, sizeof(socket_address));
    //    int sent = write(sock, buffer, sizeof(buffer));
        if (sent != sizeof(buffer)) {
            printf("cannot send %d: %s\n", sent, strerror(errno));
        }
        sleep(1);
    }    
    return 0;
}
