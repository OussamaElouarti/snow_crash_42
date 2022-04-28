### Level14


After days I just asked a friend for a hint and he said chech getflag!

```
  level14@SnowCrash:~$ which getflag
  /bin/getflag
```

I tried gdb

```
level14@SnowCrash:~$ gdb /bin/getflag
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /bin/getflag...(no debugging symbols found)...done.
(gdb) run
Starting program: /bin/getflag 
You should not reverse this
[Inferior 1 (process 2055) exited with code 01]
(gdb) 
```

but somthing dont let us debug the binary

```
level14@SnowCrash:~$ ltrace getflag
__libc_start_main(0x8048946, 1, 0xbffff7c4, 0x8048ed0, 0x8048f40 <unfinished ...>
ptrace(0, 0, 1, 0, 0)                                                                                                         = -1
puts("You should not reverse this"You should not reverse this
)                                                                                           = 28
+++ exited (status 1) +++
```

So its ptrace I googled bypass ptrace(0,0,1,0,0) and I got this  [Link](https://gist.github.com/poxyran/71a993d292eee10e95b4ff87066ea8f2)

```
(gdb) catch  syscall ptrace
Catchpoint 1 (syscall 'ptrace' [26])
(gdb) commands 1
Type commands for breakpoint(s) 1, one per line.
End with a line saying just "end".
>set $eax = 0
>continue
>end
```

We also. have a call to getuid just like the level before, so we need id of flag14 user

```
level14@SnowCrash:~$ id flag14
uid=3014(flag14) gid=3014(flag14) groups=3014(flag14),1001(flag)
```

```
(gdb) b getuid
Breakpoint 2 at 0xb7ee4cc0
(gdb) r
Starting program: /bin/getflag 

Catchpoint 1 (call to syscall ptrace), 0xb7fdd428 in __kernel_vsyscall ()

Catchpoint 1 (returned from syscall ptrace), 0xb7fdd428 in __kernel_vsyscall ()

Breakpoint 2, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
(gdb) display $eax
1: $eax = 32
(gdb) s
Single stepping until exit from function getuid,
which has no line number information.
0x08048b02 in main ()
1: $eax = 2014
(gdb) set $eax = 3014
(gdb) c
Continuing.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
[Inferior 1 (process 3832) exited normally]
```
Lets goo 

logged to flag14 with the flag and run getflag to get the same flag => 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ

```
level14@SnowCrash:~$ su flag14
Password: 
Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
flag14@SnowCrash:~$ 
```

congrats we did it!!
