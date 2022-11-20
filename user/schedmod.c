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
    change_scheduler(-1);
    exit();
  }
  if(strcmp(argv[1],"lottery")==0)
    algo = 1;
  else if(strcmp(argv[1],"rr")==0)
    algo = 0;
  else{
    printf(2,"Usage: schedmod lottery || schedmod rr\n");
    change_scheduler(-1);
    exit();
  }
//   algo = atoi(argv[1]);
  change_scheduler(algo);
    exit();
}