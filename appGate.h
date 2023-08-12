#ifndef __APP_GATE__
#define __APP_GATE__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#include <error.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

bool fCreateShm(void);
bool fCreateMq(void);
#endif
