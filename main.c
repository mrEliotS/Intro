#include "./appGate.h"
#include "./commLog.h"
#include "./appStr.h"
#include "./appSignal.h"

extern struct sigaction gsAfter;
extern struct sigaction gsBefore;

int giCnt[2] = {0,};
int giIdx = 0;

int main(void){
	if(!(writeStamp(NULL)) ){
		exit(-1);
	}
	fCreateShm();
	
	{
		gsAfter.sa_handler = fReqKill;
		gsAfter.sa_flags = 0;
		sigemptyset(&gsAfter.sa_mask);
		sigaction(15,&gsAfter,&gsBefore);
	}
	while(1){
		puts("______");
		sleep(1);
	}

		return 0;
}
