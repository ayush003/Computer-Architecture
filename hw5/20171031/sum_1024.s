.globl _start;
_start:
ADDI x5 , x0 , 512;
ADD x5,x5,x5;
ADDI x6 , x0 ,0 ;
ADDI x10 , x0 ,0 ;
q:
ADDI x10,x10,1;
ADD x6,x6,x10;
BNE x10, x5 ,q;
_exit:
