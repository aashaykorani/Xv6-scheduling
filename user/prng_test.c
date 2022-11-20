#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/prng.c"


int main(){
    int size = 900;
    int values[size];
    printf(1,"%d",uptime());
    for(int i = 0;i<size;i++){
        values[i] = random(200); // Calling random function from the included prng file.
    }
    int max,min,mean= 0;
    for(int i = 0; i<size;i++){
        // printf(1,"%d, ",values[i]);
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
    // printf(1,"\nMax = %d, Min = %d, Mean = %d\n",max,min,mean/size);
    exit();
}








