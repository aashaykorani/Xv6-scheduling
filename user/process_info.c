// #include "kernel/defs.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"


int
main(int argc, char *argv[]){
    if(argc<2){
    printf(1,"Usage: process_info 1 || process_info 0\n");
    exit();
    }
    int flag = atoi(argv[1]);
    if(flag != 0 && flag != 1){
        printf(1,"Usage: process_info 1 || process_info 0\n");
        exit();
    }
    proc_info(flag);
}