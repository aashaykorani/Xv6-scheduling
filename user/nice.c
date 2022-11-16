#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
  int priority, pid;
  if(argc < 3){
    printf(2,"Usage: nice pid priority\n");
    exit();
  }
  pid = atoi(argv[1]);
  // priority = atoi(argv[2]);
  if (argv[2][0] == '-'){
    // printf(1,"Yeh %c",argv[2][0]);
    printf(1,"2nd char = %c",argv[2][1]);
    priority = atoi(argv[2][1]);
  }
  else{
    priority = atoi(argv[2]);
    printf(1,"Positive");
  }
  // printf(1,"This is the atoi %d",priority);
  if (priority < 0 || priority > 20){
    printf(2,"Invalid priority (0-20)!\n");
    exit();
  }
  chpr(pid, priority);
  exit();
}