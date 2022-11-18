#include "kernel/types.h"
#include "kernel/x86.h"
#include "kernel/defs.h"
#include "kernel/date.h"
#include "kernel/param.h"
#include "kernel/memlayout.h"
#include "kernel/mmu.h"
#include "kernel/proc.h"

int sys_fork(void) { return fork(); }

int sys_exit(void) {
  exit();
  return 0; // not reached
}

int sys_wait(void) { return wait(); }

int sys_kill(void) {
  int pid;

  if (argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int sys_getpid(void) { return proc->pid; }

int sys_sbrk(void) {
  int addr;
  int n;

  if (argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if (growproc(n) < 0)
    return -1;
  return addr;
}

int sys_sleep(void) {
  int n;
  uint ticks0;

  if (argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n) {
    if (proc->killed) {
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int sys_uptime(void) {
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_cps(void)
{
  return cps();
}

int
sys_chpr(void)
{
  int pid, pr;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &pr) < 0)
    return -1;

  return chpr(pid, pr);
}

#define RAND_MAX 0x7fffffff

unsigned long long int xorshift64star() {
        static unsigned long long int x = 1;
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        return x * 0x2545F4914F6CDD1DULL;
}

long sys_prng(long max){
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