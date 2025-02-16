#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *other_thread(void *data) {
    while (1) {
        sleep(1);
        printf("Please enter input!\n");
    }

    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(
        &tid,
        NULL,
        other_thread,
        NULL
    );

    while (1) {
        char buffer[512];
        fgets(buffer, 512, stdin);
        printf("%s", buffer);
    }

    return 0;
}