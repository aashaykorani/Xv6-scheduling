#include "kernel/defs.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int main() {
   // printf() displays the string inside quotation
   printf(1,"Hello, World!\n");
   constant char * c = 'ps';
   exec(c);
   exit();
}