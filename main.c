#include "./appGate.h"
#include "./commLog.h"
#include "./appStr.h"
#include "./appSignal.h"
#include "./appSrv.h"
#include "./appMon.h"
#include "./appCss.h"

extern struct sigaction gsAfter;
extern struct sigaction gsBefore;


int giCnt[2] = {0,};
int giIdx = 0;

int main(int argc,char** argv){

	fShowMon();//Show os & res info

	puts("Want ssl chat mode?");
	int liFlag = 0;
	puts("yes = anykey no = 0");
	scanf("%c",&liFlag);
	if(liFlag){
		signal(SIGUSR1,fReqPoll);
		fStartSSL();
	}

	if(!(writeStamp(NULL)) ){
		exit(-1);
	}
	fDaemon();
	fCreateShm();
	fCreateMq();
	{
		gsAfter.sa_handler = fReqKill;
		gsAfter.sa_flags = 0;
		sigemptyset(&gsAfter.sa_mask);
		sigaction(15,&gsAfter,&gsBefore);
	}
	while(1){
		puts("run");
		sleep(1);
	}

		return 0;
}
