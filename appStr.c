#include "./appStr.h"

extern int giCnt[2];
extern int giIdx;

gsList* fCreateNode(gsList* spArg){
	gsList* lspTemp = spArg;
	gsList* lspNew = NULL;
	if(NULL == lspTemp){//IF HEAD IS NULL
		lspNew = (gsList*)malloc(sizeof(gsList));
		lspNew->pHead = lspNew;
		lspNew->pNext = NULL;
		lspNew->iIdx = ++giIdx;
		lspTemp = lspNew;
		return lspNew;
	}else if(NULL != lspTemp){//IF HEAD
		while(lspTemp->pNext)//MOVE END POINT
			lspTemp = lspTemp->pNext;
		lspNew = (gsList*)malloc(sizeof(gsList));
		lspNew->pHead = lspTemp->pHead;
		lspNew->pNext = NULL;
		lspNew->iIdx = ++giIdx;
		lspTemp->pNext = lspNew;
		lspTemp = lspNew;
		return  lspTemp;
	}
}
void fInsertNode(gsList* spArg,int iIdx){
	if(NULL == spArg){
		perror("Insert node is null");
		return;
	}
	bool lbFlag = false;
	gsList *lspNew,*lspNext,*lspPrev,*lspTemp;
	lspNew = lspNext = lspPrev = lspTemp = NULL;
	lspTemp = spArg->pHead;
	while(lspTemp){
		if(lspTemp->iIdx == iIdx){
			lbFlag = true;
			break;
		}
		lspTemp = lspTemp->pNext;
	}
	if(lbFlag != true){
		puts("Element not found");
		return;
	}
	if(lspTemp == lspTemp->pHead){//IF HEAD
		lspNew = (gsList*)malloc(sizeof(gsList));
		lspNew->pHead = lspNew;
		lspNew->pNext = lspTemp;
		lspNew->iIdx = ++giIdx;
		fReloadHead(lspNew);
		return;
	}else if(lspTemp != lspTemp->pHead){//IF NOT HEAD
		if(NULL == lspTemp->pNext){//NEXT IS NULL
			lspPrev = lspTemp;
			lspNew = (gsList*)malloc(sizeof(gsList));
			lspNew->pHead = lspTemp->pHead;
			lspNew->pNext = NULL;
			lspNew->iIdx = ++giIdx;
			lspPrev->pNext = lspNew;
			return;
		}else if(NULL != lspTemp->pNext){//NEXT IS NOT NULL
			lspPrev = lspTemp;
			lspNext = lspTemp->pNext;
			lspNew = (gsList*)malloc(sizeof(gsList));
			lspNew->pHead = lspTemp->pHead;
			lspNew->pNext = lspNext;
			lspNew->iIdx = ++giIdx;
			lspPrev->pNext = lspNew;
			return;
		}
	}
}
void fRemoveNode(gsList* spArg,int iIdx){
	if(NULL == spArg){
		perror("Remove node is null");
		return;
	}
	bool lbFlag = false;
	gsList *lspPrev,*lspTemp,*lspNext,*lspHead;
	lspPrev = lspTemp = lspNext = lspHead = NULL;
	lspTemp = spArg;

	while(lspTemp){
		if(lspTemp->iIdx == iIdx){
			lbFlag = true;
			break;
		}
		lspTemp = lspTemp->pNext;
	}

	if(spArg == spArg->pHead){//IF HEAD
		if(NULL == spArg->pNext){//IF NEXT IS NULL
			free(spArg);
			return;
		}else if(NULL != spArg->pNext){//IF NEXT IS NOT NULL
			lspTemp = spArg->pHead;
			while(lspTemp){
				if(lspTemp->pNext == spArg){
					lspPrev = lspTemp;
					break;
				}
				lspTemp = lspTemp->pNext;
			}
			lspPrev->pNext = spArg->pNext;
			free(spArg);
			return;
		}
	}else if(spArg != spArg->pHead){//IF NOT HEAD
		lspTemp = spArg->pHead;
		while(lspTemp){
			if(lspTemp->pNext == spArg){
				lspPrev = lspTemp;
				break;
			}
			lspTemp = lspTemp->pNext;
		}
		if(NULL == spArg->pHead){//IF NEXT IS NULL
			lspPrev->pNext = NULL;
			free(spArg);
			return;
		}else if(NULL != spArg->pHead){//IF NEXT IS NOT NULL
			lspPrev->pNext = spArg->pNext;
			free(spArg);
			return;
		}
	}
}
void fReloadHead(gsList* spArg){
	gsList* lspTemp = spArg;
	lspTemp->pHead = spArg;
	while(lspTemp){
		lspTemp->pHead = spArg;
		lspTemp = lspTemp->pNext;
	}
	return;
}
bool fFindIndex(gsList* spArg,int iArg){
	if(NULL == spArg)return false;
	gsList* lspTemp = spArg->pHead;
	while(lspTemp){
		if(lspTemp->iIdx == iArg)
			return true;
		lspTemp = lspTemp->pNext;
	}return false;
}
	
