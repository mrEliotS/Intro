#!/bin/bash

export gCurrentPwd=`pwd`
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$gCurrentPwd
gcc *.c -I. -L. -pthread -lSSLs -l__list -lAPPMON -lAPPCSS -lrt -lssl -lcrypto -lcurl -o  execSERVER -std=gnu99
