# level 08 

# what we found 

in our home directory , we see an executable with /suid/guid permissions and another file token that we can't acess to it

```
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token

```

when we try to execute the file 

```
./level08 [file to read]

```

we get output like that 

## how to solve the challenge 

when we try with a file that we have the executable shows its content:

let's try with token  
```
level08@SnowCrash:~$ ./level08 token
You may not access 'token'
```
so what's going to happen if we try to create another file and will just give the file a token name 

it won't work and it will give us the same error and it's not the same file 

let's try to debug the to see what happening 

```
strstr("token", "token")                                                         = "token"
printf("You may not access '%s'\n", "token"You may not access 'token'
)                                     = 27
exit
```

we can see that the program checks the name of the file if its token so the output going to be "you don't have acess to token" 

## solve the challenge 

the first thing come to our mind is chaging the file name 

let's try to change it and see what going to happen

mv token my_token

level08@SnowCrash:~$ ./level08 ro
quif5eloekouj29ke0vouxean
