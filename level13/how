# what we found 

when we go to the home page folder we find a executable file when we exute it 
a message appear 

```

level13@SnowCrash:~$ ./level13 
UID 2013 started us but we we expect 4242

```
we checked the /etc/passwd file we found that the flag13 has a uid/gid of 2013/2013 

```

flag13:x:3013:3013::/home/flag/flag13:/bin/bash

```

we can see that the program is protected we sstart thinking how to change the  uid/gid  let's try to debug with gdb 



```

(gdb) set disassembly intel
(gdb) disassemble main
Dump of assembler code for function main:
   0x0804858c <+0>:     push   ebp
   0x0804858d <+1>:     mov    ebp,esp
   0x0804858f <+3>:     and    esp,0xfffffff0
   0x08048592 <+6>:     sub    esp,0x10
   0x08048595 <+9>:     call   0x8048380 <getuid@plt>
   0x0804859a <+14>:    cmp    eax,0x1092
   0x0804859f <+19>:    je     0x80485cb <main+63>
   0x080485a1 <+21>:    call   0x8048380 <getuid@plt>
   0x080485a6 <+26>:    mov    edx,0x80486c8
   0x080485ab <+31>:    mov    DWORD PTR [esp+0x8],0x1092
   0x080485b3 <+39>:    mov    DWORD PTR [esp+0x4],eax
   0x080485b7 <+43>:    mov    DWORD PTR [esp],edx
   0x080485ba <+46>:    call   0x8048360 <printf@plt>
   0x080485bf <+51>:    mov    DWORD PTR [esp],0x1
   0x080485c6 <+58>:    call   0x80483a0 <exit@plt>
   0x080485cb <+63>:    mov    DWORD PTR [esp],0x80486ef
   0x080485d2 <+70>:    call   0x8048474 <ft_des>
   0x080485d7 <+75>:    mov    edx,0x8048709
   0x080485dc <+80>:    mov    DWORD PTR [esp+0x4],eax
   0x080485e0 <+84>:    mov    DWORD PTR [esp],edx
   0x080485e3 <+87>:    call   0x8048360 <printf@plt>
   0x080485e8 <+92>:    leave  
   0x080485e9 <+93>:    ret    
End of assembler dump.

```
we see that after getting the uid we do a cmp let's see what is inside tha var eax

le'ts start a break point 

 b main

 and run the program 
ni to reatch the eax var print it 
 $2 = 2013

 change it to 4242

 your token is 2A31L79asukciNyi8uppkEuSx

 ```
 (gdb) print $eax 
$2 = 2013
(gdb) set $eax=4242
(gdb) ni
0x0804859f in main ()
(gdb) ni
0x080485cb in main ()
(gdb) ni
0x080485d2 in main ()
(gdb) ni
0x080485d7 in main ()
(gdb) ni
0x080485dc in main ()
(gdb) ni
0x080485e0 in main ()
(gdb) ni
0x080485e3 in main ()
(gdb) ni
your token is 2A31L79asukciNyi8uppkEuSx
0x080485e8 in main ()
(gdb) 
```
