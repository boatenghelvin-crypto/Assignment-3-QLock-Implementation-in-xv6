#include "types.h"
#include "spinlock.h"
#include "defs.h"
#include "qlock.h"

// Basic single-process smoke test only; not a contention/FIFO test.
void qlocktest(void) {
  struct qlock q;
  initqlock(&q, "testlock");
  printf("QLock Test Started\n");
  acquireq(&q);
  printf("QLock Acquired\n");
  releaseq(&q);
  printf("QLock Released\n");
  printf("QLock Test Completed\n");
}
