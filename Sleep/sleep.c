#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_number(char c) {
    return c >= '0' && c <= '9';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("use correct argument\n");
        exit(1);
    }

    char *p = argv[1];
    while (*p != '\0') {
        if (!is_number(*p)) {
            printf("argument should be a number\n");
            exit(1);
        }
        p++;
    }

    int number = atoi(argv[1]); 
    printf("Sleeping for %d seconds...\n", number);
    sleep(number);
    printf("Done sleeping!\n");

    return 0;
}