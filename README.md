MakeBy seliot 2023

REQ = gcc 4.8.5 , openssl 1.0.2 , libcurl-devel

1.git clone [Folder]<br/>
2.cd [Folder]/<br/>
3.source libLoad.sh<br/>
4.cd sslChat<br/>
5.source libLoadc.sh<br/>
6.start app<br/>
<br/>
20230817 ChangeLog
- add SSL SOCK MOD
- add CHECK SYSTEM INFO
- add COLOR TEXT

20230818 ChangeLog
- add CHECK NICARD INFO

20230821 ChangeLog
- add CHECK MAC ADDR INFO

20230822 ChangeLog
- add CHECK PUBLIC IP ADDR INFO

20230823 ChangeLog
- add POLL MODULE , WRITE TRANSFER DATA LOG
- add THREAD -|<br/>
              ---- SEND MESSAGE MQ - thread A<br/>
			  |<br/>
			  ---- RECV MESSAGE MQ - thread B<br/>
- add MAPPING SHM A ------ B COMMUNICATIONS

=Descriptions=<br/>
This module and app is test only<br/>
Stable version ? = Unstable
