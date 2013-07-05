#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

//#define USE_LOCALHOST
int main(int argc, char **argv)
{
    int sock;
    int err;
    struct sockaddr_in addr;
#ifdef USE_LOCALHOST
    const char *get_command = "GET /video/Bear.wmv HTTP/1.0\n\n";
#else
    const char *get_command = "GET /domenech.wmv HTTP/1.0\nHost: stuff.mbonnin.net\n\n";
#endif
    char buf[4096];
    uint64_t bytes = 0;
    time_t now;
    time_t last_time;
        
    printf("starting\n");
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("cannot open socket, %s\n", strerror(errno));
        return 1;
    }
    
    if (argc > 1) {
        int window_size;
        int clamp_size;
        
        window_size = atoi(argv[1]);
        printf("set rcvbuf to %d\n", window_size);
        err = setsockopt(sock, SOL_SOCKET, SO_RCVBUF, &window_size, sizeof(window_size));
        if (err == -1) {
            printf("cannot set rcvbuf, %s\n", strerror(errno));
            return 1;
        }

        /*clamp_size = window_size / 2;

        printf("set clamp to %d\n", clamp_size / 2);

        setsockopt(sock, SOL_TCP, SO_RCVBUF, &clamp_size, sizeof(clamp_size));
        if (sock == -1) {
            printf("cannot set clamp, %s\n", strerror(errno));
            return 1;
        }*/
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port =  htons(80);
#ifdef USE_LOCALHOST
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
#else
    inet_pton(AF_INET, "203.42.5.221", &addr.sin_addr);
    //inet_pton(AF_INET, "213.186.33.19", &addr.sin_addr);
#endif
    err = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    if (err == -1) {
        printf("cannot connect\n");
        return 2;
    }
    
    write(sock, get_command, strlen(get_command));
    
    time_t start = time(NULL);
    last_time = start;
    
    while(1) {
        err = read(sock, buf, sizeof(buf) -1 );
        if (err == -1) {
            printf("cannot read %s\n", strerror(errno));
            continue;
            
        } else if (err == 0) {
            printf("connection closed\n");
            break;
        }
        
        //buf[err] = '\0';        
        //printf("GOT: %s\n", buf);
        bytes += err;
        
        now = time(NULL);
        if (now - last_time > 1) {
            printf("\r%8dkbit/s", (int)((bytes * 8)/ (1000 * (now - start))));
            fflush(stdout);
            last_time = now;
        }
    }
    
    printf("\n");
    
    close(sock);
    return 0;
}

