#include "./appGate.h"

#define __FD_SIZE__ 10

typedef struct gsList{
	int		iIdx;
	bool	bStat;
	int	bLogFlag;

	int		iFd[__FD_SIZE__];
	int		iShmId;
	key_t	kShmKey;
	void*	vhmAddr;

	mqd_t	mMqKey;

	struct gsList* pNext;
	struct gsList* pHead;
}gsList;

gsList* fCreateNode(gsList*);
void fInsertNode(gsList*,int);
void fRemoveNode(gsList*,int);
void fReloadHead(gsList*);
bool fFindNode(gsList*,int);
