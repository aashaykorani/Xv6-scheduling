#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

void my_system(char * command,char ** arg){

    int pid = fork();
    if (pid == -1)
        exit();
    if (pid == 0) // child
        exec(command,arg);
    else
        wait();
}

int main() {

   printf(1,"==Running PS==\n\n"); 
   char * command = "ps";
   char **arg = (char *[]){};
   my_system(command,arg);

   printf(1,"==Changing the priority of sh to 5==\n\n");
   char * command1 = "nice";
   char **arg1 = (char *[]){"2","5"};
   my_system(command1,arg1);
   my_system(command,arg);
   
   printf(1,"==Changing the priority of sh to -5==\n\n");
   char * command3 = "nice";
   char **arg3 = (char *[]){"2","-5"};
   my_system(command3,arg3);
   my_system(command,arg);

   printf(1,"==Changing the priority of sh to 20==\n\n");
   char * command4 = "nice";
   char **arg4 = (char *[]){"2","20"};
   my_system(command4,arg4);
   my_system(command,arg);
   
   printf(1,"==Changing the priority of sh to -22==\n\n");
   char * command5 = "nice";
   char **arg5 = (char *[]){"2","-22"};
   my_system(command5,arg5);
   my_system(command,arg);


   printf(1,"==Changing the priority of pid = 40==\n");
   char * command2 = "nice";
   char **arg2 = (char *[]){"40","5"};
   my_system(command2,arg2);
   my_system(command,arg);

   exit();
}