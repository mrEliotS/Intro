#ifndef __APP_MON__
#define __APP_MON__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/param.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <pwd.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

void fShowMon(void);
void fShowKern(void);
void fShowMem(void);
void fShowUsr(void);
void fShowNet(void);

#endif
