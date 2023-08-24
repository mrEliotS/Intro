#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void* fStartJob(void*);
void* fReadShm(void*);
void* fMutexTest(void*);
void fStartThread(void);
