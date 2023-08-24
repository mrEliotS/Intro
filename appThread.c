#include "./appThread.h"
#include "./appStr.h"
#include <sys/types.h>
#include <sys/shm.h>

#define __MQ_LEN__ 30

extern gsList* gspInfo;
long long int lliCount = 0;
pthread_mutex_t mutex;

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
void* fMutexTest(void* lvArg){

	while(1){
		pthread_mutex_lock(&mutex);
		printf("Current Thread -> [%s] - [%d] \n",(char*)lvArg,lliCount++);
		pthread_mutex_unlock(&mutex);
		usleep(100000);
	}

	return NULL;
}
void fStartThread(void){
	pthread_t pthread[2];
	int thr_id,status;
	thr_id = status = 0;
	char thread_n[4][20] = {"thread_1","thread_2","mutex_1","mutex_2"};

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
	if(0 > (thr_id = pthread_create(&pthread[2],NULL,fMutexTest,(void*)thread_n[2]))){
		perror("Mutex_1");
		exit(-1);
	}
	if(0 > (thr_id = pthread_create(&pthread[3],NULL,fMutexTest,(void*)thread_n[3]))){
		perror("Mutex_2");
		exit(-1);
	}
	pthread_detach(pthread[0]);
	pthread_detach(pthread[1]);
	pthread_join(pthread[2], NULL);
	pthread_join(pthread[3], NULL);
	pthread_mutex_destroy(&mutex);
}
