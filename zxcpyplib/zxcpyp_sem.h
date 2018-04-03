/*
 * zxcpyp's lib
 *
 * zxcpyp semaphore header (System V)
 */

#ifndef ZXCPYP_SEM_H
#define ZXCPYP_SEM_H

#include "systemV_ipc.h"

/* Used in calls to semctl() */
union semun {
  int val;
  struct semid_ds *buf;
  unsigned short *array;
#if defined(__linux__)
  struct seminfo *__buf;
#endif // __linux__
};

extern int UseSemUndo;    /* Whether using SEM_UNDO in semop() */
extern int RetryOnEintr;  /* Whether retry when semop() is interrupted */

/*
 * init_sem_available - Initial a semaphore to 1
 */
int init_sem_available(int sem_id, int sem_num);

/*
 * init_sem_available - Initial a semaphore to 1
 */
int init_sem_in_use(int sem_id, int sem_num);

/*
 * init_sem_available - Initial a semaphore to 1
 */
int sem_p(int sem_id, int sem_num);

/*
 * init_sem_available - Initial a semaphore to 1
 */
int sem_v(int sem_id, int sem_num);

#endif // !ZXCPYP_SEM_H
