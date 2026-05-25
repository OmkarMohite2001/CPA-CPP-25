#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(void)
{
    const char* exe_path = "./hello";
    pid_t pid;
    int exit_code;
    unsigned char val;

    pid = fork();
    if(pid == -1)
    {
        fprintf(stderr,"fork():%s\n",stderr(errno));
        exit(EXIT_FAILURE);
    }
    if(pid == 0)
    {
        execlp(exe_path,"hello",(char*)NULL);
        fprintf(stderr,"execlp():%s\n",stderr(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(&exit_code);
        printf("CHILD HAS TERMINATED : PRINTING RETURN VALUE FORM IT'S MAIN\n");
        val = *(unsigned char*)((char*)&exit_code + 1);
        printf("Val = %hhu\n",val)
    }
    exit(EXIT_SUCCESS);
}