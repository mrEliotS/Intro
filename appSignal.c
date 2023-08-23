#include "./appSignal.h"
#include "./commLog.h"

#define __REQ_KILL__ 15
#define __REQ_POLL__ 10
#define __MQ_NAME__ "/SELIOT_RC"

extern int giShmFd;
extern mqd_t giMqFd;

struct sigaction gsAfter;
struct sigaction gsBefore;

void fReqKill(int iNum){
	puts("REMOVE SHM");
	shmctl(giShmFd,IPC_RMID,0);
	if(-1 == mq_close(giMqFd)){
		perror("mq close");
		exit(-1);
	}
	if(-1 == mq_unlink(__MQ_NAME__)){
		perror("mq remove");
		exit(-1);
	}
	puts("REMOVE MQ");
	if(-1 == kill(getpid(),15)){
		perror("SIGKILL");
		exit(-1);
	}
	sigaction(__REQ_KILL__,&gsBefore,NULL);
	return;
}
void fReqPoll(int iNum){
	writeStamp("Arrived client message time =");
	return;
}
