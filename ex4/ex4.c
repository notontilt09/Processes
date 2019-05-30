// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child process here, about to ls -l this directory\n");
        // execl("/bin/ls", "ls", "-l", (char *) NULL);

        char *args[] = { "ls", "-l", (char *) NULL };
        char *path = "/bin/ls";
        execv(path, args);

    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("I'm just a parent watching my kid do all the work.\n");
    }

    return 0;
}

// I'm guessing there are a lot of variants to deal with a bunch of different operating systems and file structures.  Different variants allow us to perform same functionality, while allowing us to change environment settings, path settings, etc.
