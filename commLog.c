#include "./commLog.h"

#define __LOG_NAME__ "appLog.log"
#define __FILE_MASK__ 0755
#define __MAX_BUF__ 30


bool writeStamp(void* vaArg){

	int liFd = 0;
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	char lcBuf[__MAX_BUF__] = {0,};
	char lcTmp[__MAX_BUF__] = {0,};

	if(NULL == vaArg){
		strcpy(lcTmp,"INIT");
	}else{
		strcpy(lcTmp,(char*)vaArg);
	}

	if(-1 == (liFd = open(__LOG_NAME__,O_WRONLY | O_CREAT | O_APPEND,__FILE_MASK__)) ){
		perror("ERROR");
		return false;
	}
	
	sprintf(lcBuf,"%s %d.%d.%d %d:%d:%d\n",lcTmp,
			t->tm_year + 1900,t->tm_mon + 1,
			t->tm_mday,t->tm_hour,t->tm_min,
			t->tm_sec);

	if(-1 == write(liFd,lcBuf,strlen(lcBuf)) ){
		perror("ERROR");
		close(liFd);
		return false;
	}
	close(liFd);
	return true;
}
