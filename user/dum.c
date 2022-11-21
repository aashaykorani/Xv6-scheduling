// #include "kernel/defs.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"

int isdigit(int c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int main(int argc, char *argv[]) {
  if(argc>1){
    if(argc>2){
        printf(1,"Usage: dum || dum <tickets>. Default tickets = 30.\n");
        exit();
        }
        if(argv[1][0] == '-' && argv[1][1]=='h')
        {
            printf(1,"Usage: dum || dum <tickets>. Default tickets = 30.\n");
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
    assign_tickets(getpid(),30);

  int x;
  for(int z = 0; z < 400000000; z+=1)
	    x = x + 3.14*89.64; 
  exit();
}