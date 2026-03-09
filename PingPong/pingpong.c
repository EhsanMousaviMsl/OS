#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int p1[2];
    int p2[2];

    pipe(p1);
    pipe(p2);

    char buf = 'a';

    int pid = fork();

    if(pid == 0) {
        // child
        read(p1[0], &buf, 1);
        printf("%d: recieve ping\n", getpid());
        write(p2[1], &buf, 1);
        exit(0);
    } else {
        //parent
        write(p1[1], &buf, 1);
        read(p2[0], &buf, 1);

        printf("%d: recieve pong\n", getpid());

        exit(0);
        
        
    }
}