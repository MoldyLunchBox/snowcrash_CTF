
# what we found 

when we log into the level08 we found a 2. file a token file that we havo no permssion to read it and a script 

the first thing we do is execute the script got a ouptput with You may not access 'token'

trying to pass another random file and we got permission deniend 

trying to see what ltrace going to give us

    level08@SnowCrash:~$ ltrace ./level08 /tmp/mytoken
    __libc_start_main(0x8048554, 2, 0xbffff7d4, 0x80486b0, 0x8048720 <unfinished ...>
    strstr("/tmp/mytoken", "token")                                 = "token"
    printf("You may not access '%s'\n", "/tmp/mytoken"You may not access '/tmp/mytoken'
    )             = 34
    exit(1 <unfinished ...>
    +++ exited (status 1) +++

finding that use strstr fucntion to compare between the file with token 
chnaging the link or we can chang the name of the file by using mv and we execute it 

and we get the flag 

level08@SnowCrash:~$ ./level08 something 
XXXXXXXXXXXXXXXXXXXXXXXXXx
