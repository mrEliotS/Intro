#!/bin/bash

export gCurrentPwd=`pwd`
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$gCurrentPwd
gcc *.c -I. -L. -lSSLs -l__list -lrt -lssl -lcrypto -o execSERVER
