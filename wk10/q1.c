#include <stdio.h>
#include <spawn.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

int main() {

    pid_t pid;
    char *p_argv[] = {"/usr/bin/whoami", NULL};

    int spawn_status = posix_spawn(
        &pid,
        "/usr/bin/whoami",
        NULL,
        NULL,
        p_argv,
        environ
    );

    if (spawn_status != 0){
        errno = spawn_status;
        perror("Error spawning thread");
        exit(1);
    }

    int return_status;
    waitpid(pid, &return_status, 0);

    if (return_status != 0) {
        fprintf(stderr, "Process returned with exit code %d\n", return_status);
        exit(1);
    }

    return 0;
}