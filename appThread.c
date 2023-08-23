#include "./appThread.h"
#include "./appStr.h"
#include <sys/types.h>
#include <sys/shm.h>

#define __MQ_LEN__ 30

extern gsList* gspInfo;

void* fStartJob(void* lvArg){
	char lcSendMsg[__MQ_LEN__] = "ACK";
	if(0 != mq_send(gspInfo->mMqKey,lcSendMsg,__MQ_LEN__,1)){
		puts("MSG Q SEND ERROR");
		exit(-1);
	}
	puts("MSG Q SEND SUCCESS");
	return NULL;
}
void* fReadShm(void* lvArg){
	void* lvHideItem = NULL;
	char lcSendMsg[__MQ_LEN__] = {0x00,};
	struct mq_attr lsAttr = {0x00,};
	if(-1 == mq_getattr(gspInfo->mMqKey,&lsAttr)){
		puts("MSG Q GET SIZE ERROR");
		exit(-1);
	}
	if(-1 == mq_receive(gspInfo->mMqKey,lcSendMsg,lsAttr.mq_msgsize,NULL)){
		puts("MSG Q RECV ERROR");
		exit(-1);
	}
	puts("MSG Q RECV SUCCESS");
	if(strncmp(lcSendMsg,"ACK",3)){
		perror("Nq msg :");
		exit(-1);
	}
	if((void*)-1 == (lvHideItem = shmat(gspInfo->iShmId,NULL,0))){
		puts("SHM attach error 1");
		exit(-1);
	}
	printf("Item is %s\n",(char*)lvHideItem);
	return NULL;
}
void fStartThread(void){
	pthread_t pthread[2];
	int thr_id,status;
	thr_id = status = 0;
	char thread_n[2][20] = {"thread_1","thread_2"};

	if(0 > (thr_id = pthread_create(&pthread[0],NULL,fStartJob,(void*)thread_n[0]))){
		perror("ThreadA : ");
		exit(-1);
	}
	sleep(1); //SYNC
	puts("");
	if(0 > (thr_id = pthread_create(&pthread[1],NULL,fReadShm,(void*)thread_n[1]))){
		perror("ThreadB : ");
		exit(-1);
	}
	pthread_detach(pthread[0]);
	pthread_detach(pthread[1]);
}
