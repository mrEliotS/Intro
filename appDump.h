#include <stdio.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>

void fPacketCapture(u_char*, const struct pcap_pkthdr*, const u_char* );
int fStartCapture(void);
