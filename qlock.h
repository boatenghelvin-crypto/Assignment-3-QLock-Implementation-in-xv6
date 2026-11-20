#ifndef XV6_QLOCK_H
#define XV6_QLOCK_H
#include "spinlock.h"

// Sleep-based lock modeled after xv6 sleeplock (not a FIFO queue lock).
struct qlock {
  struct spinlock lk;
  int locked;
};

void initqlock(struct qlock *q, char *name);
void acquireq(struct qlock *q);
void releaseq(struct qlock *q);
#endif
