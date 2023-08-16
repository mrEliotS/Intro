#define __APP_SSL__

#define PORT 7114
#define SERVER_ADDRESS "127.0.0.1"

#include "./appGate.h"

void ssl_info_callback(const SSL *s, int where, int ret);
int fStartSSL(void);
