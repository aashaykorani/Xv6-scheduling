#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

#define RAND_MAX 0x7fffffff

unsigned long long int xorshift64star() {
        static unsigned long long int x = 1;
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        return x * 0x2545F4914F6CDD1DULL;
}

long random(long max){
    unsigned long
        num_bins = (unsigned long) max + 1,
        num_rand = (unsigned long) RAND_MAX + 1,
        bin_size = num_rand / num_bins,
        defect   = num_rand % num_bins;

        long x;
        do {
        x = xorshift64star();
        }
        while (num_rand - defect <= (unsigned long)x);

        return x/bin_size;
}

int main(){
    int size = 900;
    int values[size];

    for(int i = 0;i<size;i++){
        values[i] = random(100);
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
    printf(1,"\nMax = %d, Min = %d, Mean = %d\n",max,min,mean/size);
    exit();
}








