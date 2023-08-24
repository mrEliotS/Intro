#include "./appETC.h"

#define SMALL -1
#define BIG	1
#define EQU 0

int fCompare(const void* cvArgA,const void* cvArgB){
	int liNumA = *(int*)cvArgA;
	int liNumB = *(int*)cvArgB;
	if(liNumA < liNumB)
		return SMALL;
	else if(liNumA > liNumB)
		return BIG;
	else
		return EQU;
}

	
