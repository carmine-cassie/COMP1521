#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *other_thread(void *data) {
    char *message = data;
    while (1) {
        printf("Thread B says: %s\n", message);
    }

    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(
        &tid,
        NULL,
        other_thread,
        "hhellloooooooo"
    );

    while (1) {
        printf("Hello from thread A!\n");
    }

    return 0;
}