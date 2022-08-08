# find the files owned by the user flag00
to find all files owned by a spesific user we use the command
	find / -user flag00
we will see a big output with a lot of permission denied errors 
i just looked manually in the output i found two paths without permission denied error
we can show all the user have SUID permission 
 using htis command 

find / -perm -4000 2> /dev/null -exec ls -la {} + 

# we have:
	/usr/sbin/jhon
	/rofs/usr/sbin/jhon
# we can use this command to redirect all error to /dev/null
	 find / -user flag00  2>/dev/null

/dev/null is treated as black hole in Linux/unix so we can put anything want to ignore 
further 2> will filter out the errors so that they will not output to the console 

in more detail: 2 represents the error descriptor, which is where errors are written to by default they are printed out on the console 
# for addition 

we can use this command find / -user flag00 2>/dev/null -exec cat {} +

{} will replaced by the files found by find
+  will enable us to read as many arguments as possible per invocation of cat, as cat can take multiple arguments.

# the output of the file is
	cdiiddwpgswtgt

# trying to access failed

start thinking maybe we need to decode it we're just going to go to 
 going to 
 https://www.dcode.fr/caesar-cipher

first recomended cipher is ceasar, give us output result 
 	nottoohardhere

# try to log in with the first output 

$ su flag00
$ not too hard here 

and we get the flag 

Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
