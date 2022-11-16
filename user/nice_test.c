#include "kernel/defs.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#define MAXARGS 10

int main() {
    struct execcmd {
        int type;
        char *argv[MAXARGS];
        char *eargv[MAXARGS];
    };
   // printf() displays the string inside quotation
   printf(1,"Hello, World!\n");
   char * command = "ps";
   char **arg = (char *[]){};
   exec(command,arg);
   exit();
}