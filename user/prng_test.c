// #include "kernel/defs.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/prng.c"


int main(){
    int size = 900;
    int values[size];
    // int start = uptime();
    for(int i = 0;i<size;i++){
        do{
        values[i] = random(200);
        }while(values[i]==0); // Calling random function from the included prng file.
    }
    int max,min,mean= 0;
    for(int i = 0; i<size;i++){
        printf(1,"%d, ",values[i]);
        if (i==0){
            max = values[i];
            min = values[i];
        }
        else{
            if (values[i] > max)
                max = values[i];
            else if (values[i] < min)
                min = values[i];
        }
        mean += values[i];
    }
    printf(1,"\nMax = %d, Min = %d, Mean = %d\n",max,min,mean/size);
    // printf(1,"END = %d\n",uptime()-start);
    exit();
}








