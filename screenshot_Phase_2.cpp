samievghayrat@samievghayrat-lenovo:~/bomb57$ gdb bomb

(gdb) break phase_2
Breakpoint 1 at 0x400e81
(gdb) r input.txt
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
1 2 3 4 5 6

Breakpoint 1, 0x0000000000400e81 in phase_2 ()
(gdb) disas
Dump of assembler code for function phase_2:
=> 0x0000000000400e81 <+0>:     push   %rbp
   0x0000000000400e82 <+1>:     push   %rbx
   0x0000000000400e83 <+2>:     sub    $0x28,%rsp
   0x0000000000400e87 <+6>:     mov    %rsp,%rsi
   0x0000000000400e8a <+9>:     call   0x401369 <read_six_numbers>
   0x0000000000400e8f <+14>:    cmpl   $0x1,(%rsp)
   0x0000000000400e93 <+18>:    jne    0x400e9e <phase_2+29>
   0x0000000000400e95 <+20>:    mov    %rsp,%rbx
   0x0000000000400e98 <+23>:    lea    0x14(%rbx),%rbp
   0x0000000000400e9c <+27>:    jmp    0x400eae <phase_2+45>
   0x0000000000400e9e <+29>:    call   0x401347 <explode_bomb>
   0x0000000000400ea3 <+34>:    jmp    0x400e95 <phase_2+20>
   0x0000000000400ea5 <+36>:    add    $0x4,%rbx
   0x0000000000400ea9 <+40>:    cmp    %rbp,%rbx
   0x0000000000400eac <+43>:    je     0x400ebe <phase_2+61>
   0x0000000000400eae <+45>:    mov    (%rbx),%eax
   0x0000000000400eb0 <+47>:    add    %eax,%eax
   0x0000000000400eb2 <+49>:    cmp    %eax,0x4(%rbx)
   0x0000000000400eb5 <+52>:    je     0x400ea5 <phase_2+36>
   0x0000000000400eb7 <+54>:    call   0x401347 <explode_bomb>
   0x0000000000400ebc <+59>:    jmp    0x400ea5 <phase_2+36>
   0x0000000000400ebe <+61>:    add    $0x28,%rsp
   0x0000000000400ec2 <+65>:    pop    %rbx
   0x0000000000400ec3 <+66>:    pop    %rbp
   0x0000000000400ec4 <+67>:    ret
End of assembler dump.
(gdb) break read_six_numbers
Breakpoint 2 at 0x401369
(gdb) ni
0x0000000000400e82 in phase_2 ()
(gdb)
0x0000000000400e83 in phase_2 ()
(gdb)
0x0000000000400e87 in phase_2 ()
(gdb)
0x0000000000400e8a in phase_2 ()
(gdb)

Breakpoint 2, 0x0000000000401369 in read_six_numbers ()
(gdb)
0x000000000040136d in read_six_numbers ()
(gdb)
0x0000000000401370 in read_six_numbers ()
(gdb)
0x0000000000401374 in read_six_numbers ()
(gdb)
0x0000000000401378 in read_six_numbers ()
(gdb)
0x0000000000401379 in read_six_numbers ()
(gdb)
0x000000000040137d in read_six_numbers ()
(gdb)
0x000000000040137e in read_six_numbers ()
(gdb)
0x0000000000401382 in read_six_numbers ()
(gdb)
0x0000000000401386 in read_six_numbers ()
(gdb)
0x000000000040138b in read_six_numbers ()
(gdb)
0x0000000000401390 in read_six_numbers ()
(gdb)
0x0000000000401395 in read_six_numbers ()
(gdb)
0x0000000000401399 in read_six_numbers ()
(gdb)
0x000000000040139c in read_six_numbers ()
(gdb)
0x000000000040139e in read_six_numbers ()
(gdb)
0x00000000004013a2 in read_six_numbers ()
(gdb)
0x0000000000400e8f in phase_2 ()
(gdb)
0x0000000000400e93 in phase_2 ()
(gdb)
0x0000000000400e95 in phase_2 ()
(gdb)
0x0000000000400e98 in phase_2 ()
(gdb)
0x0000000000400e9c in phase_2 ()
(gdb)
0x0000000000400eae in phase_2 ()
(gdb)
0x0000000000400eb0 in phase_2 ()
(gdb)
0x0000000000400eb2 in phase_2 ()
(gdb)
0x0000000000400eb5 in phase_2 ()
(gdb)
0x0000000000400ea5 in phase_2 ()
(gdb)
0x0000000000400ea9 in phase_2 ()
(gdb) i r
rax            0x2                 2
rbx            0x7fffffffe5a4      140737488348580
rcx            0x0                 0
rdx            0x7fffffffe5b4      140737488348596
rsi            0x0                 0
rdi            0x7fffffffdf10      140737488346896
rbp            0x7fffffffe5b4      0x7fffffffe5b4
rsp            0x7fffffffe5a0      0x7fffffffe5a0
r8             0x0                 0
r9             0x0                 0
r10            0x7ffff7b80bc0      140737349422016
r11            0x402434            4203572
r12            0x400c50            4197456
r13            0x7fffffffe6c0      140737488348864
r14            0x0                 0
r15            0x0                 0
rip            0x400ea9            0x400ea9 <phase_2+40>
eflags         0x202               [ IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
(gdb) x/d 140737488348580
0x7fffffffe5a4: 2
(gdb) r input.txt
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
1 2 4 8 16 32

Breakpoint 1, 0x0000000000400e81 in phase_2 ()
(gdb) n
Single stepping until exit from function phase_2,
which has no line number information.

Breakpoint 2, 0x0000000000401369 in read_six_numbers ()
(gdb) n
Single stepping until exit from function read_six_numbers,
which has no line number information.
0x0000000000400e8f in phase_2 ()
(gdb) n
Single stepping until exit from function phase_2,
which has no line number information.
main (argc=<optimized out>, argv=<optimized out>) at bomb.c:83
warning: Source file is more recent than executable.
83          phase_defused();
(gdb) 