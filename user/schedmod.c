#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    int algo;
    if(argc < 2){
    printf(2,"Usage: schedmod lottery || schedmod rr\n");
    exit();
  }
  algo = atoi(argv[1]);
  change_scheduler(algo);
    exit();
}