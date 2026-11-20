#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "defs.h"
#include "proc.h"
#include "qlock.h"

void initqlock(struct qlock *q, char *name) {
  initlock(&q->lk, name);
  q->locked = 0;
}

void acquireq(struct qlock *q) {
  acquire(&q->lk);
  while(q->locked)
    sleep(q, &q->lk);
  q->locked = 1;
  release(&q->lk);
}

void releaseq(struct qlock *q) {
  acquire(&q->lk);
  if(q->locked == 0)
    panic("releaseq");
  q->locked = 0;
  wakeup(q);
  release(&q->lk);
}
