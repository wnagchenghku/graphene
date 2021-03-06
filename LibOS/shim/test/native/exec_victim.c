/* -*- mode:c; c-file-style:"k&r"; c-basic-offset: 4; tab-width:4; indent-tabs-mode:nil; mode:auto-fill; fill-column:78; -*- */
/* vim: set ts=4 sw=4 et tw=78 fo=cqt wm=0: */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv, const char ** envp)
{
    FILE * out = stdout;

    if (argc > 1) {
        int fd = atoi(argv[argc - 1]);
        printf("inherited file descriptor %d\n", fd);
        out = fdopen(fd, "a");
        if (!out) {
            perror("fdopen");
            exit(1);
        }
    }

    fprintf(out, "Hello World (%s)!\n", argv[0]);
    fprintf(out, "envp[\'IN_EXECVE\'] = %s\n", getenv("IN_EXECVE"));
    return 0;
}
