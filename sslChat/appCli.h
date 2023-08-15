#ifndef __APP_C_SSL__

#define PORT 7114
#define SERVER_ADDRESS "10.0.0.13"

//STD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>

//SSL
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>


//SYS
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <arpa/inet.h>

#endif
void fStartCli(void);
