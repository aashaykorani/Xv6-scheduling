#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"

void forker(int nprocesses, int parent)
{
    int pid;

    if(nprocesses > 0)
    {
        if ((pid = fork()) < 0)
        {
            exit();
        }
        else if (pid == 0)
        {
            printf(1,)
            int x;
            for(int z = 0; z < 400000000; z+=1)
                x = x + 3.14*89.64;
        }
        else if(pid > 0)
        {
            //parent
            forker(nprocesses - 1,parent);
        }
    }
}

int main(int argc, char * argv[]){
    forker(3,getpid());
    exit();
}