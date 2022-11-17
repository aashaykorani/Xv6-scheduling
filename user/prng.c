#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"


unsigned long long int xorshift64star(void) {
        static unsigned long long int x = 1; /* initial seed must be nonzero, don't use a static variable for the state if multithreaded */
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        return (x * 0x2545F4914F6CDD1DULL);
}

int main(){
    for(int i = 0;i<10;i++){
        int q = xorshift64star();
        printf(1,"Q = %d")
        if (q < 0){
            printf(1,"%d",q*-1);
        }
        else{
            printf(1,"%d",q);
        }
    }
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