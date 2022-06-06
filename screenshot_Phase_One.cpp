samievghayrat@samievghayrat-lenovo:~/bomb57$ gdb bomb
GNU gdb (Ubuntu 10.2-0ubuntu1~18.04~2) 10.2
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from bomb...
(gdb) b phase_1
Breakpoint 1 at 0x400e63
(gdb) r
Starting program: /home/samievghayrat/bomb57/bomb
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
hi

Breakpoint 1, 0x0000000000400e63 in phase_1 ()
(gdb) disas
Dump of assembler code for function phase_1:
=> 0x0000000000400e63 <+0>:     sub    $0x8,%rsp
   0x0000000000400e67 <+4>:     mov    $0x402230,%esi
   0x0000000000400e6c <+9>:     call   0x40124a <strings_not_equal>
   0x0000000000400e71 <+14>:    test   %eax,%eax
   0x0000000000400e73 <+16>:    jne    0x400e7a <phase_1+23>
   0x0000000000400e75 <+18>:    add    $0x8,%rsp
   0x0000000000400e79 <+22>:    ret
   0x0000000000400e7a <+23>:    call   0x401347 <explode_bomb>
   0x0000000000400e7f <+28>:    jmp    0x400e75 <phase_1+18>
End of assembler dump.
(gdb) x/s 0x402230
0x402230:       "Why make trillions when we could make... billions?"
(gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/samievghayrat/bomb57/bomb
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Why make trillions when we could make... billions?

Breakpoint 1, 0x0000000000400e63 in phase_1 ()
(gdb) n
Single stepping until exit from function phase_1,
which has no line number information.
main (argc=<optimized out>, argv=<optimized out>) at bomb.c:75
warning: Source file is more recent than executable.
75          phase_defused();                 /* Drat!  They figured it out!
(gdb) n
77          printf("Phase 1 defused. How about the next one?\n");
(gdb)
