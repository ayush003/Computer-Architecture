.globl _start;
_start:
ADDI x5,x0,10
ADDI x12,x0,2
ADDI x10,x0,1
ADDI x11,x0,1
q:
ADD x6,x10,x11
ADD x10,x0,x11
ADD x11,x0,x6
ADDI x12,x12,1
BNE x12,x5,loop
_exit:
