#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"
// #include <stdlib.h>

int main(int argc, char * argv[]){
    if(argc<3){
        printf(1,"Usage: chng_tickets pid tickets");
        exit();
    }
    int pid,tickets;
    if(argv[1][0])
    pid = atoi(argv[1]);
    tickets = atoi(argv[2]);
    

}