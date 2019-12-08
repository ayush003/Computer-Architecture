.globl _start;
_start:
ADDI x5,x0,256
ADDI x6,x0,512
ADD x5,x5,x5
ADD x5,x5,x5
q:
BLT x5,x6,if1
SUB x5,x5,x6
BNE x6,x0,q
JAL x0,done
if1:
ADD x11,x0,x5
ADD x5,x0,x6
ADD x6,x0,x11
JAL x0,q
done:
ADD x7,x0,x5
JALR x0,0(x0) 
_exit:

