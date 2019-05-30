// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here 
    FILE *file = fopen("text.txt", "w");

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("In child process\n");
        char *child = "Writing from child\n";
        fwrite(child, sizeof(char), strlen(child), file);
    } else {
        printf("In parent process\n");
        char *parent = "Parent here\n";
        fwrite(parent, sizeof(char), strlen(parent), file);
    }
    fclose(file);
    
    return 0;
}

// Both child and parent can access and write to the file .  If both process write to the file concurrently, then the file ends up containing what was written from both processes.
