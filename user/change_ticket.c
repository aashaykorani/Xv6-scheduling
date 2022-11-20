#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"

// #include <stdlib.h>

int isdigit(int c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int main(int argc, char * argv[]){
    if(argc<3){
        printf(1,"Usage: chng_ticket pid tickets\n");
        exit();
    }
    // int pid,tickets;
    if(!isdigit(argv[1][0]))
        printf(1,"PID cannot be negative");
    exit();
    // pid = atoi(argv[1]);
    // tickets = atoi(argv[2]);
    

}