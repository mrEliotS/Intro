#ifndef __APP_GATE__
#define __APP_GATE__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#include <error.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>
#include <poll.h>

bool fCreateShm(void);
bool fCreateMq(void);
#endif

//SOCKET
#ifdef __APP_SSL__
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

//OPEN SSL
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/ssl.h>
#endif
