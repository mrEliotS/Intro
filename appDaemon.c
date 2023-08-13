#include "./appDaemon.h"

void fDaemon(void){
	switch(fork()){
		case -1:
			perror("Daemon error");
			exit(-1);
		case 0:
			if(-1 == setsid()){
				perror("Daemon season id error");
				exit(-1);
			}
			break;
		default:
			//perror("Parent is down");
			exit(0);
	}
	switch(fork()){
		case -1:
			perror("Daemon season leader error");
			exit(-1);
		case 0:
			umask(0);
			chdir("/");
			return;
		default:
			//perror("Is not season leader");
			exit(0);
	}
}

