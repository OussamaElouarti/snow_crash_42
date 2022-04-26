### Level05

-Nothing in home directory

-run ``` find / -name level05 2>/dev/null ```

-got a cron that run a script every 2 mins

-The script run another script that iterate on every file in /opt/openarenaserver and execute it if its executable as flag05 user then delete it

-So. I created a script in /opt/openarenaserver that call getflag and redirect it to a file in /tmp the script :
```
	#!/bin/bash
	
	getflag > /tmp/getflag 
```
-chmod +x scriptname

-then waited till it was deleted and cat /tmp/getflag => Check flag.Here is your token : viuaaale9huek52boumoomioc
