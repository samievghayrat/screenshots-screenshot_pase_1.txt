

samievghayrat@samievghayrat-lenovo:~$ cd bomb57
samievghayrat@samievghayrat-lenovo:~/bomb57$ gdb bomb

(gdb) break phase_3             //setting breakpoint
Breakpoint 1 at 0x400ec5
(gdb) r input.txt   //input file
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
1234 

Breakpoint 1, 0x0000000000400ec5 in phase_3 ()
(gdb) disas //disassembling
Dump of assembler code for function phase_3:
=> 0x0000000000400ec5 <+0>:     sub    $0x18,%rsp
   0x0000000000400ec9 <+4>:     lea    0x8(%rsp),%rcx
   0x0000000000400ece <+9>:     lea    0xc(%rsp),%rdx
   0x0000000000400ed3 <+14>:    mov    $0x40242f,%esi
   0x0000000000400ed8 <+19>:    mov    $0x0,%eax
   0x0000000000400edd <+24>:    call   0x400bc0 <__isoc99_sscanf@plt>
   0x0000000000400ee2 <+29>:    cmp    $0x1,%eax
   0x0000000000400ee5 <+32>:    jle    0x400ef9 <phase_3+52>
   0x0000000000400ee7 <+34>:    cmpl   $0x7,0xc(%rsp)
   0x0000000000400eec <+39>:    ja     0x400f31 <phase_3+108>
   0x0000000000400eee <+41>:    mov    0xc(%rsp),%eax
   0x0000000000400ef2 <+45>:    jmp    *0x4022a0(,%rax,8)
   0x0000000000400ef9 <+52>:    call   0x401347 <explode_bomb>
   0x0000000000400efe <+57>:    jmp    0x400ee7 <phase_3+34>
   0x0000000000400f00 <+59>:    mov    $0x15b,%eax
   0x0000000000400f05 <+64>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f07 <+66>:    mov    $0x3c6,%eax
   0x0000000000400f0c <+71>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f0e <+73>:    mov    $0x5a,%eax
   0x0000000000400f13 <+78>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f15 <+80>:    mov    $0x1e5,%eax
   0x0000000000400f1a <+85>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f1c <+87>:    mov    $0x22b,%eax
   0x0000000000400f21 <+92>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f23 <+94>:    mov    $0x218,%eax
   0x0000000000400f28 <+99>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f2a <+101>:   mov    $0xe6,%eax
   0x0000000000400f2f <+106>:   jmp    0x400f42 <phase_3+125>
   0x0000000000400f31 <+108>:   call   0x401347 <explode_bomb>
   0x0000000000400f36 <+113>:   mov    $0x0,%eax
   0x0000000000400f3b <+118>:   jmp    0x400f42 <phase_3+125>
   0x0000000000400f3d <+120>:   mov    $0x1dc,%eax
   0x0000000000400f42 <+125>:   cmp    %eax,0x8(%rsp)
   0x0000000000400f46 <+129>:   je     0x400f4d <phase_3+136>
   0x0000000000400f48 <+131>:   call   0x401347 <explode_bomb>
   0x0000000000400f4d <+136>:   add    $0x18,%rsp
   0x0000000000400f51 <+140>:   ret
End of assembler dump.
(gdb) x/s 0x40242f  //here I found that input must be digit and digit then I re-run 
0x40242f:       "%d %d"
(gdb) r input.txt
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
1 5

Breakpoint 1, 0x0000000000400ec5 in phase_3 ()
(gdb) disas
Dump of assembler code for function phase_3:
=> 0x0000000000400ec5 <+0>:     sub    $0x18,%rsp
   0x0000000000400ec9 <+4>:     lea    0x8(%rsp),%rcx
   0x0000000000400ece <+9>:     lea    0xc(%rsp),%rdx
   0x0000000000400ed3 <+14>:    mov    $0x40242f,%esi
   0x0000000000400ed8 <+19>:    mov    $0x0,%eax
   0x0000000000400edd <+24>:    call   0x400bc0 <__isoc99_sscanf@plt>
   0x0000000000400ee2 <+29>:    cmp    $0x1,%eax
   0x0000000000400ee5 <+32>:    jle    0x400ef9 <phase_3+52>
   0x0000000000400ee7 <+34>:    cmpl   $0x7,0xc(%rsp)
   0x0000000000400eec <+39>:    ja     0x400f31 <phase_3+108>
   0x0000000000400eee <+41>:    mov    0xc(%rsp),%eax
   0x0000000000400ef2 <+45>:    jmp    *0x4022a0(,%rax,8)
   0x0000000000400ef9 <+52>:    call   0x401347 <explode_bomb>
   0x0000000000400efe <+57>:    jmp    0x400ee7 <phase_3+34>
   0x0000000000400f00 <+59>:    mov    $0x15b,%eax
   0x0000000000400f05 <+64>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f07 <+66>:    mov    $0x3c6,%eax
   0x0000000000400f0c <+71>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f0e <+73>:    mov    $0x5a,%eax
   0x0000000000400f13 <+78>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f15 <+80>:    mov    $0x1e5,%eax
   0x0000000000400f1a <+85>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f1c <+87>:    mov    $0x22b,%eax
   0x0000000000400f21 <+92>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f23 <+94>:    mov    $0x218,%eax
   0x0000000000400f28 <+99>:    jmp    0x400f42 <phase_3+125>
   0x0000000000400f2a <+101>:   mov    $0xe6,%eax
   0x0000000000400f2f <+106>:   jmp    0x400f42 <phase_3+125>
   0x0000000000400f31 <+108>:   call   0x401347 <explode_bomb>
   0x0000000000400f36 <+113>:   mov    $0x0,%eax
   0x0000000000400f3b <+118>:   jmp    0x400f42 <phase_3+125>
   0x0000000000400f3d <+120>:   mov    $0x1dc,%eax
   0x0000000000400f42 <+125>:   cmp    %eax,0x8(%rsp)
   0x0000000000400f46 <+129>:   je     0x400f4d <phase_3+136>
   0x0000000000400f48 <+131>:   call   0x401347 <explode_bomb>
   0x0000000000400f4d <+136>:   add    $0x18,%rsp
   0x0000000000400f51 <+140>:   ret
End of assembler dump.\

//now I am going to <+29> to for looking what is the actual first digit that is being 
//compared with my first digit


(gdb) ni
0x0000000000400ec9 in phase_3 ()
(gdb)
0x0000000000400ece in phase_3 ()
(gdb)
0x0000000000400ed3 in phase_3 ()
(gdb)
0x0000000000400ed8 in phase_3 ()
(gdb)
0x0000000000400edd in phase_3 ()
(gdb)
0x0000000000400ee2 in phase_3 ()

//then with x/d $rsp+0xc I am finding out the correct value of first digit not my input.
(gdb) x/d $rsp+0xc
0x7fffffffe5cc: 1

//I am going to <+129> to see the value of second digit that is being compared to my 
//second input
(gdb) ni
0x0000000000400ee5 in phase_3 ()
(gdb)
0x0000000000400ee7 in phase_3 ()
(gdb)
0x0000000000400eec in phase_3 ()
(gdb)
0x0000000000400eee in phase_3 ()
(gdb)
0x0000000000400ef2 in phase_3 ()
(gdb)
0x0000000000400f00 in phase_3 ()
(gdb)
0x0000000000400f05 in phase_3 ()
(gdb)
0x0000000000400f42 in phase_3 ()
(gdb)
0x0000000000400f46 in phase_3 ()
(gdb) $rsp+0x8
//I am finding the value of second digit
//It is 347
(gdb) i r
rax            0x15b               347
rbx            0x7fffffffe6c8      140737488348872
rcx            0x0                 0
rdx            0x7fffffffe5c8      140737488348616
rsi            0x0                 0
rdi            0x7fffffffdf50      140737488346960
rbp            0x402050            0x402050 <__libc_csu_init>
rsp            0x7fffffffe5c0      0x7fffffffe5c0
r8             0x0                 0
r9             0x0                 0
r10            0x7ffff7b80bc0      140737349422016
r11            0x402434            4203572
r12            0x400c50            4197456
r13            0x7fffffffe6c0      140737488348864
r14            0x0                 0
r15            0x0                 0
rip            0x400f46            0x400f46 <phase_3+129>
eflags         0x297               [ CF PF AF SF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0

//I hope I found both of the values 1 347, lets input them and see if they are correct or 
//not?
(gdb) r input.txt
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
1 347

Breakpoint 1, 0x0000000000400ec5 in phase_3 ()
(gdb) n
Single stepping until exit from function phase_3,
which has no line number information.
main (argc=<optimized out>, argv=<optimized out>) at bomb.c:90
warning: Source file is more recent than executable.
90          phase_defused();
(gdb) n
91          printf("Halfway there!\n"); //yes they are correct; ^^
(gdb)
