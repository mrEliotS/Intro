#include "./appGate.h"

#define __SHM_KEY__ 71143321
#define __SHM_SIZE__ ((1500) * (2))
#define __SHM_MASK__ 0666
#define __MQ_NAME__ "/SELIOT_RC"
#define __MQ_SIZE__ 5
#define __MQ_LEN__ 4096
#define __MQ_MASK__ 0666

int giShmFd = 0;
mqd_t giMqFd = 0;
struct mq_attr giMqAttr;

bool fCreateShm(void){
	int liFd = 0;

	if(!(writeStamp("SHM INIT")) ){
		return false;
	}
	if(-1 == (liFd = shmget(__SHM_KEY__,__SHM_SIZE__
					,IPC_CREAT|__SHM_MASK__)) ){
		perror("error");
		return false;
	}
	giShmFd = liFd;
	return true;
}
bool fCreateMq(void){
	if(!(writeStamp("MQ INIT")) ){
		return false;
	}
	giMqAttr.mq_maxmsg = __MQ_SIZE__;
	giMqAttr.mq_msgsize = __MQ_LEN__;
	if(-1 == (giMqFd = mq_open(__MQ_NAME__,O_CREAT|O_RDWR,__MQ_MASK__,&giMqAttr)) ){
		perror("mq error");
		return false;
	}
	return true;
}
