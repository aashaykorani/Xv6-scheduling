#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

unsigned int x = 548787455, y = 842502087, z = 3579807591, w = 273326509;

unsigned int XORShift() {
	unsigned int t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ t ^ (t >> 8);
}

int main(){
    unsigned int values[10];
    for(int i = 0; i<10;i++){
        values[i] = XORShift();
    }
    int max,min,mean = 0;
    for(int i = 0; i<10;i++){
        // printf(1,"%d\n",values[i]);
        if (i==0){
            max = values[i];
            min = values[i];
            mean += values[i];
        }
        else{
            if (values[i] > max)
                max = values[i];
            else
                min = values[i];
            mean += values[i];
        }
    }
    exit();
}