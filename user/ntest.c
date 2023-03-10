// #include "kernel/defs.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

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

int main() {
   printf(1,"==Running PS to show the inital state==\n\n"); 
   static char *arg[]= {"./ps",NULL};
   my_system(arg);

   printf(1,"\n==Changing the priority of sh to 5==\n");
   static char *arg1[]= {"./nice","2","5",NULL};
   my_system(arg1);
   printf(1,"\n");
   my_system(arg);
   
   printf(1,"\n==Changing the priority of sh to -5==\n");
   static char *arg3[]= {"./nice","2","-5",NULL};
   my_system(arg3);
   printf(1,"\n");
   my_system(arg);

   printf(1,"\n==Changing the priority of sh to 20==\n\n");
   static char *arg4[]= {"./nice","2","20",NULL};
   my_system(arg4);
   printf(1,"\n");
   my_system(arg);
   
   printf(1,"\n==Changing the priority of sh to -22==\n\n");
  static char *arg5[]= {"./nice","2","-22",NULL};
   my_system(arg5);
   printf(1,"\n");
   my_system(arg);


   printf(1,"\n==Changing the priority of pid = 40==\n\n");
   static char *arg2[]= {"./nice","40","5",NULL};
   my_system(arg2);

printf(1,"\n==Changing the priority of sh back to 10==\n\n");
   static char *arg6[]= {"./nice","2","10",NULL};
   my_system(arg6);


   exit();
}