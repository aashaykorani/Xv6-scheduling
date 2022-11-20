#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"

#define NULL 0

void my_system(char *arg[]){

    int pid = fork();
    if (pid == -1)
        exit();
    if (pid == 0)
        exec(arg[0],arg);
    else
        wait();
}

int main(int argc, char *argv[]) {
  assign_tickets(100);
  printf(1,"==Running PS to show the inital state==\n\n"); 
   static char *arg[]= {"./ps",NULL};
   my_system(arg);
  int x;
  for(int z = 0; z < 40000000; z+=1)
	    x = x + 3.14*89.64;
    
  exit();
//   int pid;
//   int k, n;
//   int x, z;
//   if(argc < 2)
// 	n = 1; //Default
//   else
// 	n = atoi(argv[1]);
//   if (n < 0 ||n > 20)
// 	n = 2;
//   x = 0;
//   pid = 0;

//   for ( k = 0; k < n; k++ ) {
//     pid = fork ();
//     if ( pid < 0 ) {
//       printf(1, "%d failed in fork!\n", getpid());
//     } else if (pid > 0) {
//       // parent
//       printf(1, "Parent %d creating child %d\n",getpid(), pid);
//       wait();
//       }
//       else{
// 	printf(1,"Child %d created\n",getpid());
// 	for(z = 0; z < 4000000; z+=1)
// 	    x = x + 3.14*89.64; //Useless calculation to consume CPU Time
// 	break;
//       }
//   }
//   exit();
}