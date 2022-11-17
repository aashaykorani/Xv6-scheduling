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
    for(int i = 1; i<=10;i++){
        printf(1,"%d\n",XORShift());
    }
    exit();
}