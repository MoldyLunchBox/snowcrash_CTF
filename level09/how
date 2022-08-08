# what we found

and the home sirectory we found executable eith suid/guid

    level09@SnowCrash:~$ ls -l
    total 12
    -rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
    ----r--r-- 1 flag09 level09   26 Mar  5  2016 token
    level09@SnowCrash:~$ cat token
    f4kmm6p|=�p�n��DB�Du{��
we try to know more and with ltrace we found nothing but that a phrase with you should not reverse it 

we try to enter diferent inputs to see what going to happen 
        
        level09@SnowCrash:~$ ./level09 token
        tpmhr
        level09@SnowCrash:~$ ./level09 ramoukha
         hfnos
        level09@SnowCrash:~$ ./level09 aaaaaa
        abcdefg
finding that the we can pass a string input to the executable and encodes it by rotating each character by increpting an index 

we can create a script to do that and we get the flag
