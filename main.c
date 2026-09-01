//#include "cachelab.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  
int main(int argc, char *const argv[]) {
    int opt;
    char *filename = NULL;
    int verbose = 0;
    int s = 0;
    int E = 0;
    int b = 0;

    while((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch (opt) {
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                filename = optarg;
                break;
            case 'v':
                verbose = 1;
                break;
            case 'h':
                printf("Usage: %s [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n", argv[0]);
                exit(EXIT_SUCCESS);
            default:
                printf("Usage: %s [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    /*
    filename pointer -> stores the address the the valgrind trace file.
    s -> stores the number of set index bits; S = 2^s;
    E -> number of cache lines
    b -> the block offset bits;
    */
   FILE *fptr;
   fptr = fopen(filename, "r");

   char buffer[2];// The string that will hold every single line of information in the file.
   if(fptr == NULL) {
        perror("Error: Unable to access the file name specified.");
        return 1;
   }
   char operation;
   unsigned long address;
   int size;
   while(fscanf(fptr, " %c %lx %d", &operation, &address, &size)) {
        // We now directly have the variables we need to calculate the s, E, b.
   }
   //printSummary(0, 0, 0);
   return 0;
}