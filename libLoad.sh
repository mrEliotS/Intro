#!/bin/bash

export gCurrentPwd=`pwd`
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$gCurrentPwd
gcc *.c -I. -L. -pthread -lSSLs -l__list -lAPPMON -lAPPCSS -lAPPDUMP -lrt -lssl -lcrypto -lcurl -lpcap -o  execSERVER -std=gnu99
