#ifndef PRNG_H
#define PRNG_H

unsigned long long int xorshift64star(void);
extern long random(long);
long EXPORT_SYMBOL(long random(long));

#endif