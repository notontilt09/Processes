// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    printf("hello world (pid: %d)\n", (int) getpid());

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("This is child process (pid: %d), value of x is %d)\n", (int) getpid(), x);
        x++;
        printf("New value of x in child: %d\n", x);

    } else {
        printf("This is parent process (pid: %d), child is (pid: %d), x is %d\n", (int) getpid(), rc, x);
        x--;
        printf("new value of x in parent: %d\n", x);
    }



    return 0;
}

// The fork retains the values of variables before fork was called.  Updating the values of varaibles in a specific process has no effect on the variables in the parent/child process.