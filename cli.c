/* @INFO POSIX C
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  
int main(int argc, const char *argv[]) {
    int opt;
    char *filename = NULL;
    int verbose = 0;
    int s = 0;
    int E = 0;
    int b = 0;

    while((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch (opt) {
            case 's':
                s = optarg;
            case 'E':
                E = optarg;
            case 'b':
                b = optarg;
            case 't':
                filename = optarg;
            case 'v':
                verbose = 1;
            case 'h':
                printf("Usage: %s [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n", argv[0]);
                exit(EXIT_SUCCESS);
            default:
                printf("Usage: %s [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
}