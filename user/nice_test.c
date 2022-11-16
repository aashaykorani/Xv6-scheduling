#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int main() {

   printf(1,"--Running PS--\n"); 
   char * command = "ps";
   char **arg = (char *[]){};
   exec(command,arg);

   printf(1,"--Changing the nice value of sh to 5--\n");
   char * command1 = "nice";
   char **arg1 = (char *[]){"2","5"};
   exec(command1,arg1);

   printf(1,"--Changing the nice value of pid = 40--\n");
    char * command1 = "nice";
   char **arg1 = (char *[]){"2","5"};
   exec(command1,arg1);
   exit();
}