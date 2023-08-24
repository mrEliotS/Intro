#include "./appGate.h"
#include "./commLog.h"
#include "./appStr.h"
#include "./appSignal.h"
#include "./appSrv.h"
#include "./appMon.h"
#include "./appCss.h"
#include "./appThread.h"
#include "./appETC.h"

extern struct sigaction gsAfter;
extern struct sigaction gsBefore;
gsList* gspInfo;

int giCnt[2] = {0,};
int giIdx = 0;

int main(int argc,char** argv){
	//fShowMon();//Show os & res info

	puts("Want ssl chat mode?");
	int liFlag = 0;
	puts("yes = anykey no = 0");
	scanf("%d",&liFlag);
	if(liFlag){
		signal(SIGUSR1,fReqPoll);
		fStartSSL();
	}

	if(!(writeStamp(NULL)) ){
		exit(-1);
	}
	fDaemon();
	gspInfo = fCreateNode(gspInfo); //Create New Node
	fCreateShm();
	fCreateMq();
	{
		gsAfter.sa_handler = fReqKill;
		gsAfter.sa_flags = 0;
		sigemptyset(&gsAfter.sa_mask);
		sigaction(15,&gsAfter,&gsBefore);
	}
	fStartThread();
	//********************
	while(1){
		printf("MAIN = %u\n",(unsigned int)getpid());
		sleep(1);
	}

		return 0;
}
