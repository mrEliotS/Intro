#include "./appSignal.h"

#define __REQ_KILL__ 15

extern int giShmFd;
struct sigaction gsAfter;
struct sigaction gsBefore;

void fReqKill(int iNum){
	puts("REMOVE SHM");
	shmctl(giShmFd,IPC_RMID,0);
	if(-1 == kill(getpid(),15)){
		perror("SIGKILL");
		exit(-1);
	}
	sigaction(__REQ_KILL__,&gsBefore,NULL);
}
