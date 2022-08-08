# first thing we look at it 
we know that the /etc/passw file stores essential information requered during
login it stores user account information

[//]: #  (the file contain a list of the system’s accounts, giving for each account some useful information like user ID, group ID, home directory, shell, and more)

# decode the value

first we tried to submet the value in the 
	su flag01 
got 
		level00@SnowCrash:~$ su flag01
		Password:
		su: Authentication failure

trying to decode the value by using https://www.dcode.fr/caesar-cipher
trying to submit every pass got nothing 
starting by looking at another rool to crack the password finding jhon the ripper 

# what is jhon the ripper password 
John the Ripper is a fast password cracker, ts primary purpose is to detect weak Unix passwords. Besides several crypt(3) password hash types most commonly found on various Unix flavors

# how to use 

To run John, you need to supply it with some password files and optionally specify a cracking mode, like this, using the default order of modes and assuming that "passwd" is a copy of your password file:

		┌──(kali㉿kali)-[~]
		└─$ john hash.txt

# To retrieve the cracked passwords, run:

		┌──(kali㉿kali)-[~]
		└─$  john hash.txt --show
		?:abcdefg
		1 password hash cracked, 0 left

trying the passwd and we got the flag 
