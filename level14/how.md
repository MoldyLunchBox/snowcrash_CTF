lets use the command uname - a to check the release date of the kernel

level14@SnowCrash:~$ uname -a
Linux SnowCrash 3.2.0-89-generic-pae #127-Ubuntu SMP Tue Jul 28 09:52:21 UTC 2015 i686 i686 i386 GNU/Linux

the year is 2015, knowing that there is an exploit called dirty cow that came out in 2016 and affects most of the kernels that came out before it

dirty Cow exploit was found in the way the Linux kernel's memory subsystem handled the copy-on-write (COW) breakage of private read-only memory mappings. An unprivileged local user could use this flaw to gain write access to otherwise read-only memory mappings and thus increase their privileges on the system

we simply download the script from https://github.com/FireFart/dirtycow/blob/master/dirty.c

and follow the instructions, we will at the end have root privilege.

