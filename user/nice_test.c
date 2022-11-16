#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

void my_system(char * command,char ** arg){

    int pid = fork();
    if (pid == 0) // child
        exec(command);
    else
        
}

int main() {

   printf(1,"==Running PS==\n"); 
   char * command = "ps";
   char **arg = (char *[]){};
   exec(command,arg);

   printf(1,"==Changing the priority of sh to 5==\n");
   char * command1 = "nice";
   char **arg1 = (char *[]){"2","5"};
   exec(command1,arg1);
   exec(command,arg);
   
   printf(1,"==Changing the priority of sh to -5==\n");
   char * command3 = "nice";
   char **arg3 = (char *[]){"2","-5"};
   exec(command3,arg3);
   exec(command,arg);

   printf(1,"==Changing the priority of sh to 20==\n");
   char * command4 = "nice";
   char **arg4 = (char *[]){"2","20"};
   exec(command4,arg4);
   exec(command,arg);
   
   printf(1,"==Changing the priority of sh to -22==\n");
   char * command5 = "nice";
   char **arg5 = (char *[]){"2","-22"};
   exec(command5,arg5);
   exec(command,arg);


   printf(1,"==Changing the priority of pid = 40==\n");
   char * command2 = "nice";
   char **arg2 = (char *[]){"40","5"};
   exec(command2,arg2);
   exec(command,arg);

   
   exit();
}