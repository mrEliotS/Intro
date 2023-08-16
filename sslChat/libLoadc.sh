#!/bin/bash

export gCurrentPwd=`pwd`
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$gCurrentPwd
gcc *.c -I. -L. -lSSLc -lrt -lssl -lcrypto -o execCLIENT
