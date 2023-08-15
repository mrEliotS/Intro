MakeBy seliot 2023

1.Make build folder 
-> mkdir -p /app/sBuild

2.Move source file to /app/sBuild

3.Change Dir /app/sBuild
-> cd /app/sBuild

4.Build src <SSL-Server + IPC>
------------------------------------------
****gcc -o $name is options...******
-> gcc *.c -I. -L. -lSSLs -l__list -lrt -lssl -lcrypto

5.Build src <SSL-Client>
********gcc -o $name is options...******
->cd sslChat
->gcc *.c -I. -L. -lSSLc -lssl -lcrypto

6.Exec shell
-> sh libLoad.sh

6.Run file

------------------------------------------
20230815
ChangeLog

-Add SSL Socket Module(Not Stable)
------------------------------------------


