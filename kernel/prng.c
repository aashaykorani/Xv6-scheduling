#define RAND_MAX 0x7fffffff

unsigned long long int xorshift64star(void) {
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