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

int isdigit(int c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int main(int argc, char *argv[]) {
    if(argc>1){
        if(argc>2){
        printf(1,"Usage: dum2 || dum2 <tickets>. Default tickets = 600.\n");
        exit();
        }
        if(argv[1][0] == '-' && argv[1][1]=='h')
        {
            printf(1,"Usage: dum2 || dum2 <tickets>. Default tickets = 600.\n");
            exit();
        }
        if(!isdigit(argv[1][0])){
            printf(1,"Ticket has to be positive integer\n");
            exit(); 
        }
        int tickets;
        tickets = atoi(argv[1]);
        if(tickets==0){
        printf(1,"Tickets cannot be 0.\n");
        exit();
        }
        assign_tickets(getpid(), tickets);
    }
    else
        assign_tickets(getpid(),600);
  printf(1,"==Running PS from dum2 to show the inital state==\n\n"); 
   static char *arg[]= {"./ps",NULL};
   my_system(arg);
  int x;
    for ( int k = 0; k < n; k++ ) {
    int pid = fork ();
    if ( pid < 0 ) {
      printf(1, "%d failed in fork!\n", getpid());
    } else if (pid > 0) {
      // parent
      printf(1, "Parent %d creating child %d\n",getpid(), pid);
      wait();
      }
      else{
	printf(1,"Child %d created\n",getpid());
	for(int z = 0; z < 4000000000; z+=1)
	    x = x + 3.14*89.64; //Useless calculation to consume CPU Time
	break;
      }
  }
//   for(int z = 0; z < 400000000; z+=1)
// 	    x = x + 3.14*89.64;
  exit();
}