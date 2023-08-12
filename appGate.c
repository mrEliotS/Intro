#include "./appGate.h"

#define __SHM_KEY__ 71143321
#define __SHM_SIZE__ ((1500) * (2))
#define __SHM_MASK__ 0666

int giShmFd = 0;

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
