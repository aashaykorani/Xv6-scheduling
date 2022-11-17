#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"


struct xorwow_state {
    unsigned int x[5];
    unsigned int counter;
};

/* The state array must be initialized to not be all zero in the first four words */
unsigned int xorwow(struct xorwow_state *state)
{
    /* Algorithm "xorwow" from p. 5 of Marsaglia, "Xorshift RNGs" */
    unsigned int t  = state->x[4];
 
    unsigned int s  = state->x[0];  /* Perform a contrived 32-bit shift. */
    state->x[4] = state->x[3];
    state->x[3] = state->x[2];
    state->x[2] = state->x[1];
    state->x[1] = s;
 
    t ^= t >> 2;
    t ^= t << 1;
    t ^= s ^ (s << 4);
    state->x[0] = t;
    state->counter += 362437;
    return t + state->counter;
}

unsigned long long int xorshift64star(void) {

    for(int i = 1;i<=10;i++){
        static unsigned long long int x = 1; /* initial seed must be nonzero, don't use a static variable for the state if multithreaded */
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        return x * 0x2545F4914F6CDD1DULL;
    }
}

int main(){
    printf(1,"%d\n",xorshift64star());
    exit();
}















// unsigned int x = 548787455, y = 842502087, z = 3579807591, w = 273326509;

// unsigned int XORShift() {
// 	unsigned int t = x ^ (x << 11);
// 	x = y; y = z; z = w;
// 	return w = w ^ (w >> 19) ^ t ^ (t >> 8);
// }

// int main(){
//     unsigned int values[100];
//     for(int i = 0; i<5;i++){
//         values[i] = XORShift();
//     }
//     // int max,min,mean = 0;
//     for(int i = 0; i<5;i++){
//         printf(1,"%d\n",values[i]);
//         // if (i==0){
//         //     max = values[i];
//         //     min = values[i];
//         //     // mean += values[i];
//         // }
//         // else{
//         //     if (values[i] >= max)
//         //         max = values[i];
//         //     else
//         //         min = values[i];
//         // }
//         // mean += values[i];
//     }
//     // printf(1,"Max = %d, Min = %d, Mean = %d\n",max,min,mean/100);
//     exit();
// }