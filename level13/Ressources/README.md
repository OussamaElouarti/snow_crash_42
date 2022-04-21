## Level13

we got an suid binary level13

when we execute it it return:

```
UID 2013 started us but we we expect 4242
```

so the program execute getuid to compare it with 4242 to use it for output

lunch gdb to see what is happening 

`gdb -q ./level13`

```
level13@SnowCrash:~$ gdb -q ./level13                                                                                                                                                                       
Reading symbols from /home/user/level13/level13...(no debugging symbols found)...done.
```

`disas main` to disasemble the main

```
  (gdb) disas main                                   
Dump of assembler code for function main:
   0x0804858c <+0>:     push   %ebp
   0x0804858d <+1>:     mov    %esp,%ebp
   0x0804858f <+3>:     and    $0xfffffff0,%esp
   0x08048592 <+6>:     sub    $0x10,%esp
   0x08048595 <+9>:     call   0x8048380 <getuid@plt>
=> 0x0804859a <+14>:    cmp    $0x1092,%eax
   0x0804859f <+19>:    je     0x80485cb <main+63>
   0x080485a1 <+21>:    call   0x8048380 <getuid@plt>
   0x080485a6 <+26>:    mov    $0x80486c8,%edx
   0x080485ab <+31>:    movl   $0x1092,0x8(%esp)
   0x080485b3 <+39>:    mov    %eax,0x4(%esp)
   0x080485b7 <+43>:    mov    %edx,(%esp)
   0x080485ba <+46>:    call   0x8048360 <printf@plt>
   0x080485bf <+51>:    movl   $0x1,(%esp)
   0x080485c6 <+58>:    call   0x80483a0 <exit@plt> 
   0x080485cb <+63>:    movl   $0x80486ef,(%esp)
   0x080485d2 <+70>:    call   0x8048474 <ft_des>
   0x080485d7 <+75>:    mov    $0x8048709,%edx
   0x080485dc <+80>:    mov    %eax,0x4(%esp)
   0x080485e0 <+84>:    mov    %edx,(%esp)
   0x080485e3 <+87>:    call   0x8048360 <printf@plt>
   0x080485e8 <+92>:    leave  
   0x080485e9 <+93>:    ret    
End of assembler dump.
```

as we see after getuid lunch we user cmp that is the assembly compare function
that probably compare our uid with 4242
so we need to put a breakpoint at main+14 the run

```
(gdb) b *main+14                                                                                                                                                                                            
Breakpoint 1 at 0x804859a                                                                                                                                                                                   
(gdb) r                                            
Starting program: /home/user/level13/level13 

Breakpoint 1, 0x0804859a in main ()
```

now lets print the content of eax register then modify it to 4242 and continue the program :

```
(gdb) display $eax                                 
1: $eax = 2013                                     
(gdb) set $eax = 4242                              
(gdb) n                                            
Single stepping until exit from function main,
which has no line number information.
your token is 2A31L79asukciNyi8uppkEuSx
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
1: $eax = 40
```
It worked!
