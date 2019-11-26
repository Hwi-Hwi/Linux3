#include<sys/types.h>
#include<unistd.h>
#include <stdio.h>

void main(int argc ,char *argv[])
{
    pid_t pid;
    printf("Calling fork \n");
    pid = fork();
    if(pid == 0)
    {
        printf("I'm the child process.\n");
    }
    else if(pid>0)
        printf("I'm the parent process.\n");
    else
        printf("fork failed.\n");
}

