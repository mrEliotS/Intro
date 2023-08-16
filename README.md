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
------------------------------------------
20230816
ChangeLog

-Modify SSL Module(Not Stable)
server -> source libLoad.sh
client -> source libLoadc.sh

<Descriptions>
1.Port 7114 fix
2.Ip 127.0.0.1 fix

No Modify 
Loopback test only!
Requ Openssl lib =  v1.0.2
------------------------------------------






