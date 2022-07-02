# find the files owned by the user flag00
to find all files owned by a spesific user we use the command 
	find / -user flag00
we will see a big output with a lot of permission denied errors 
i just lookef manually in the output i found two paths without permission denied erroe 

# we have:
	/usr/sbin/jhon
	/rofs/usr/sbin/jhon
# we can use this command to redirect all error to /dev/null
	 find / -user flag00  2>/dev/null

/dev/null is treated as black hole in Linux/unix so we can put anything want to ignore 
further 2> will filter out the errors so that they will not output to the console 

in more detail: 2 represents the error descriptor, which is where errors are written to by default they are printed out on the console 

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
