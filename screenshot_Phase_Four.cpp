    +----------------------------------------------------------------------+
 
samievghayrat@samievghayrat-lenovo:~/bomb57$ gdb bomb
.
(gdb) break phase_4
Breakpoint 1 at 0x400f91
(gdb) r input.txt
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
1 347
Halfway there!
1234

Breakpoint 1, 0x0000000000400f91 in phase_4 ()
(gdb) disas
Dump of assembler code for function phase_4:
=> 0x0000000000400f91 <+0>:     sub    $0x18,%rsp
   0x0000000000400f95 <+4>:     lea    0x8(%rsp),%rcx
   0x0000000000400f9a <+9>:     lea    0xc(%rsp),%rdx
   0x0000000000400f9f <+14>:    mov    $0x40242f,%esi
   0x0000000000400fa4 <+19>:    mov    $0x0,%eax
   0x0000000000400fa9 <+24>:    call   0x400bc0 <__isoc99_sscanf@plt>
   0x0000000000400fae <+29>:    cmp    $0x2,%eax
   0x0000000000400fb1 <+32>:    jne    0x400fba <phase_4+41>
   0x0000000000400fb3 <+34>:    cmpl   $0xe,0xc(%rsp)
   0x0000000000400fb8 <+39>:    jbe    0x400fbf <phase_4+46>
   0x0000000000400fba <+41>:    call   0x401347 <explode_bomb>
   0x0000000000400fbf <+46>:    mov    $0xe,%edx
   0x0000000000400fc4 <+51>:    mov    $0x0,%esi
   0x0000000000400fc9 <+56>:    mov    0xc(%rsp),%edi
   0x0000000000400fcd <+60>:    call   0x400f52 <func4>
   0x0000000000400fd2 <+65>:    cmp    $0x4,%eax
   0x0000000000400fd5 <+68>:    jne    0x400fde <phase_4+77>
   0x0000000000400fd7 <+70>:    cmpl   $0x4,0x8(%rsp)
   0x0000000000400fdc <+75>:    je     0x400fe3 <phase_4+82>
   0x0000000000400fde <+77>:    call   0x401347 <explode_bomb>
   0x0000000000400fe3 <+82>:    add    $0x18,%rsp
   0x0000000000400fe7 <+86>:    ret
End of assembler dump.
(gdb) x/s 0x40242f
0x40242f:       "%d %d"
(gdb) r input.txt
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
1 347
Halfway there!
1 2

Breakpoint 1, 0x0000000000400f91 in phase_4 ()
(gdb) disas
Dump of assembler code for function phase_4:
=> 0x0000000000400f91 <+0>:     sub    $0x18,%rsp
   0x0000000000400f95 <+4>:     lea    0x8(%rsp),%rcx
   0x0000000000400f9a <+9>:     lea    0xc(%rsp),%rdx
   0x0000000000400f9f <+14>:    mov    $0x40242f,%esi
   0x0000000000400fa4 <+19>:    mov    $0x0,%eax
   0x0000000000400fa9 <+24>:    call   0x400bc0 <__isoc99_sscanf@plt>
   0x0000000000400fae <+29>:    cmp    $0x2,%eax
   0x0000000000400fb1 <+32>:    jne    0x400fba <phase_4+41>
   0x0000000000400fb3 <+34>:    cmpl   $0xe,0xc(%rsp)
   0x0000000000400fb8 <+39>:    jbe    0x400fbf <phase_4+46>
   0x0000000000400fba <+41>:    call   0x401347 <explode_bomb>
   0x0000000000400fbf <+46>:    mov    $0xe,%edx
   0x0000000000400fc4 <+51>:    mov    $0x0,%esi
   0x0000000000400fc9 <+56>:    mov    0xc(%rsp),%edi
   0x0000000000400fcd <+60>:    call   0x400f52 <func4>
   0x0000000000400fd2 <+65>:    cmp    $0x4,%eax
   0x0000000000400fd5 <+68>:    jne    0x400fde <phase_4+77>
   0x0000000000400fd7 <+70>:    cmpl   $0x4,0x8(%rsp)
   0x0000000000400fdc <+75>:    je     0x400fe3 <phase_4+82>
   0x0000000000400fde <+77>:    call   0x401347 <explode_bomb>
   0x0000000000400fe3 <+82>:    add    $0x18,%rsp
   0x0000000000400fe7 <+86>:    ret
End of assembler dump.
(gdb) ni
0x0000000000400f95 in phase_4 ()
(gdb)
0x0000000000400f9a in phase_4 ()
(gdb)
0x0000000000400f9f in phase_4 ()
(gdb)
0x0000000000400fa4 in phase_4 ()
(gdb)
0x0000000000400fa9 in phase_4 ()
(gdb)
0x0000000000400fae in phase_4 ()
(gdb) i r
rax            0x2                 2 //I found 2 the first digit by digging into the loop
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
rip            0x400fae            0x400fae <phase_4+29>
eflags         0x206               [ PF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
(gdb) ni
0x0000000000400fb1 in phase_4 ()
(gdb)
0x0000000000400fb3 in phase_4 ()
(gdb)
0x0000000000400fb8 in phase_4 ()
(gdb)
0x0000000000400fbf in phase_4 ()
(gdb)
0x0000000000400fc4 in phase_4 ()
(gdb)
0x0000000000400fc9 in phase_4 ()
(gdb)
0x0000000000400fcd in phase_4 ()
(gdb)
0x0000000000400fd2 in phase_4 ()
(gdb) i r
rax            0x0                 0
rbx            0x7fffffffe6c8      140737488348872
rcx            0x1                 1
rdx            0x2                 2
rsi            0x0                 0
rdi            0x1                 1
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
rip            0x400fd2            0x400fd2 <phase_4+65>
eflags         0x206               [ PF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
(gdb) disas
Dump of assembler code for function phase_4:
   0x0000000000400f91 <+0>:     sub    $0x18,%rsp
   0x0000000000400f95 <+4>:     lea    0x8(%rsp),%rcx
   0x0000000000400f9a <+9>:     lea    0xc(%rsp),%rdx
   0x0000000000400f9f <+14>:    mov    $0x40242f,%esi
   0x0000000000400fa4 <+19>:    mov    $0x0,%eax
   0x0000000000400fa9 <+24>:    call   0x400bc0 <__isoc99_sscanf@plt>
   0x0000000000400fae <+29>:    cmp    $0x2,%eax
   0x0000000000400fb1 <+32>:    jne    0x400fba <phase_4+41>
   0x0000000000400fb3 <+34>:    cmpl   $0xe,0xc(%rsp)
   0x0000000000400fb8 <+39>:    jbe    0x400fbf <phase_4+46>
   0x0000000000400fba <+41>:    call   0x401347 <explode_bomb>
   0x0000000000400fbf <+46>:    mov    $0xe,%edx
   0x0000000000400fc4 <+51>:    mov    $0x0,%esi
   0x0000000000400fc9 <+56>:    mov    0xc(%rsp),%edi
   0x0000000000400fcd <+60>:    call   0x400f52 <func4>
=> 0x0000000000400fd2 <+65>:    cmp    $0x4,%eax
   0x0000000000400fd5 <+68>:    jne    0x400fde <phase_4+77>
   0x0000000000400fd7 <+70>:    cmpl   $0x4,0x8(%rsp)
   0x0000000000400fdc <+75>:    je     0x400fe3 <phase_4+82>
   0x0000000000400fde <+77>:    call   0x401347 <explode_bomb>
   0x0000000000400fe3 <+82>:    add    $0x18,%rsp
   0x0000000000400fe7 <+86>:    ret
End of assembler dump.
(gdb) x/d $eax
0x0:    Cannot access memory at address 0x0
(gdb) ni
0x0000000000400fd5 in phase_4 ()
(gdb)
0x0000000000400fde in phase_4 ()
(gdb)

BOOM!!!
The bomb has blown up.
[Inferior 1 (process 3937) exited with code 010]
(gdb) r input.txt
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
1 347
Halfway there!
1 3

Breakpoint 1, 0x0000000000400f91 in phase_4 ()
(gdb) disas
Dump of assembler code for function phase_4:
=> 0x0000000000400f91 <+0>:     sub    $0x18,%rsp
   0x0000000000400f95 <+4>:     lea    0x8(%rsp),%rcx
   0x0000000000400f9a <+9>:     lea    0xc(%rsp),%rdx
   0x0000000000400f9f <+14>:    mov    $0x40242f,%esi
   0x0000000000400fa4 <+19>:    mov    $0x0,%eax
   0x0000000000400fa9 <+24>:    call   0x400bc0 <__isoc99_sscanf@plt>
   0x0000000000400fae <+29>:    cmp    $0x2,%eax
   0x0000000000400fb1 <+32>:    jne    0x400fba <phase_4+41>
   0x0000000000400fb3 <+34>:    cmpl   $0xe,0xc(%rsp)
   0x0000000000400fb8 <+39>:    jbe    0x400fbf <phase_4+46>
   0x0000000000400fba <+41>:    call   0x401347 <explode_bomb>
   0x0000000000400fbf <+46>:    mov    $0xe,%edx
   0x0000000000400fc4 <+51>:    mov    $0x0,%esi
   0x0000000000400fc9 <+56>:    mov    0xc(%rsp),%edi
   0x0000000000400fcd <+60>:    call   0x400f52 <func4>
   0x0000000000400fd2 <+65>:    cmp    $0x4,%eax
   0x0000000000400fd5 <+68>:    jne    0x400fde <phase_4+77>
   0x0000000000400fd7 <+70>:    cmpl   $0x4,0x8(%rsp)
   0x0000000000400fdc <+75>:    je     0x400fe3 <phase_4+82>
   0x0000000000400fde <+77>:    call   0x401347 <explode_bomb>
   0x0000000000400fe3 <+82>:    add    $0x18,%rsp
   0x0000000000400fe7 <+86>:    ret
End of assembler dump.
(gdb) ni
0x0000000000400f95 in phase_4 ()
(gdb)
0x0000000000400f9a in phase_4 ()
(gdb)
0x0000000000400f9f in phase_4 ()
(gdb)
0x0000000000400fa4 in phase_4 ()
(gdb)
0x0000000000400fa9 in phase_4 ()
(gdb)
0x0000000000400fae in phase_4 ()
(gdb)
0x0000000000400fb1 in phase_4 ()
(gdb)
0x0000000000400fb3 in phase_4 ()
(gdb)
0x0000000000400fb8 in phase_4 ()
(gdb)
0x0000000000400fbf in phase_4 ()
(gdb)
0x0000000000400fc4 in phase_4 ()
(gdb)
0x0000000000400fc9 in phase_4 ()
(gdb)
0x0000000000400fcd in phase_4 ()
(gdb)
0x0000000000400fd2 in phase_4 ()
(gdb)
0x0000000000400fd5 in phase_4 ()
(gdb)
0x0000000000400fde in phase_4 ()
(gdb) x/d $rsp+0x8
0x7fffffffe5c8: 3
(gdb) x/d $rsp+0xc
0x7fffffffe5cc: 1
(gdb) x/d $rsp+0x12
0x7fffffffe5d2: -1
(gdb) r input/txt
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/samievghayrat/bomb57/bomb input/txt
/home/samievghayrat/bomb57/bomb: Error: Couldn't open input/txt
[Inferior 1 (process 4071) exited with code 010]
(gdb) r input.txt
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
1 347
Halfway there!
2 3

Breakpoint 1, 0x0000000000400f91 in phase_4 ()
(gdb) disas
Dump of assembler code for function phase_4:
=> 0x0000000000400f91 <+0>:     sub    $0x18,%rsp
   0x0000000000400f95 <+4>:     lea    0x8(%rsp),%rcx
   0x0000000000400f9a <+9>:     lea    0xc(%rsp),%rdx
   0x0000000000400f9f <+14>:    mov    $0x40242f,%esi
   0x0000000000400fa4 <+19>:    mov    $0x0,%eax
   0x0000000000400fa9 <+24>:    call   0x400bc0 <__isoc99_sscanf@plt>
   0x0000000000400fae <+29>:    cmp    $0x2,%eax
   0x0000000000400fb1 <+32>:    jne    0x400fba <phase_4+41>
   0x0000000000400fb3 <+34>:    cmpl   $0xe,0xc(%rsp)
   0x0000000000400fb8 <+39>:    jbe    0x400fbf <phase_4+46>
   0x0000000000400fba <+41>:    call   0x401347 <explode_bomb>
   0x0000000000400fbf <+46>:    mov    $0xe,%edx
   0x0000000000400fc4 <+51>:    mov    $0x0,%esi
   0x0000000000400fc9 <+56>:    mov    0xc(%rsp),%edi
   0x0000000000400fcd <+60>:    call   0x400f52 <func4>
   0x0000000000400fd2 <+65>:    cmp    $0x4,%eax
   0x0000000000400fd5 <+68>:    jne    0x400fde <phase_4+77>
   0x0000000000400fd7 <+70>:    cmpl   $0x4,0x8(%rsp)
   0x0000000000400fdc <+75>:    je     0x400fe3 <phase_4+82>
   0x0000000000400fde <+77>:    call   0x401347 <explode_bomb>
   0x0000000000400fe3 <+82>:    add    $0x18,%rsp
   0x0000000000400fe7 <+86>:    ret
End of assembler dump.
(gdb) ni
0x0000000000400f95 in phase_4 ()
(gdb)
0x0000000000400f9a in phase_4 ()
(gdb)
0x0000000000400f9f in phase_4 ()
(gdb)
0x0000000000400fa4 in phase_4 ()
(gdb)
0x0000000000400fa9 in phase_4 ()
(gdb)
0x0000000000400fae in phase_4 ()
(gdb)
0x0000000000400fb1 in phase_4 ()
(gdb)
0x0000000000400fb3 in phase_4 ()
(gdb)
0x0000000000400fb8 in phase_4 ()
(gdb)
0x0000000000400fbf in phase_4 ()
(gdb)
0x0000000000400fc4 in phase_4 ()
(gdb)
0x0000000000400fc9 in phase_4 ()
(gdb)
0x0000000000400fcd in phase_4 ()
(gdb)
0x0000000000400fd2 in phase_4 ()
(gdb) si
0x0000000000400fd5 in phase_4 ()
(gdb) i r
rax            0x4                 4                //Second digit is 4 I found it from the loop
rbx            0x7fffffffe6c8      140737488348872
rcx            0x2                 2
rdx            0x2                 2
rsi            0x2                 2
rdi            0x2                 2
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
rip            0x400fd5            0x400fd5 <phase_4+68>
eflags         0x246               [ PF ZF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
(gdb) Quit
(gdb) r input.txt
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/samievghayrat/bomb57/bomb input.txt
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
That's number 2.  Keep going!
Halfway there!

Breakpoint 1, 0x0000000000400f91 in phase_4 ()
(gdb) n
Single stepping until exit from function phase_4,
which has no line number information.
main (argc=<optimized out>, argv=<optimized out>) at bomb.c:96
warning: Source file is more recent than executable.
96          phase_defused();
(gdb) n
97          printf("So you got that one.  Try this one.\n");
(gdb) n
So you got that one.  Try this one.
100         input = read_line();
(gdb)
