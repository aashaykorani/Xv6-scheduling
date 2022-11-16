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
    priority = atoi(&argv[2][1])*-1;
  }
  else{
    priority = atoi(argv[2]);
  }
  if (priority < -20 || priority > 19){
    printf(2,"Attempt to set nice value out of the range.\nNice values range from -20 to +19.\n");
    exit();
  }
  chpr(pid, priority);
  exit();
}