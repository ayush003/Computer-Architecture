package Tb;

// testbench for Multi

import AdderInterface::*;
import RCA::*;

Tin notestinputs=100;

(* synthesize *)
module mkTb (Empty);


   Reg#(Tin) x    <- mkReg(1);
   Reg#(Tin) y    <- mkReg(0);
   Reg#(Bool) starting <- mkReg(True);

   
   // The dut
   Adder_IFC dut <- mkRCA;
   
   // RULES ----------------
   
   rule start (starting);
	   starting <= False;
   endrule

   rule rule_tb ((x < notestinputs) && !starting );
      Tin op1 = x;
      Tin op2 = y;
      Tout result, expected;
      $display ("    x = %d, y = %d", op1, op2);
      result = dut.add32 (op1, op2);
      expected = extend(op1+op2);
      $display("    Result = %d Expected = %d",result , expected);
      if (result != expected) $finish(0);
      x <= x + 1;
   endrule
   
   // TASK: Add a rule to invoke $finish(0) at the appropriate moment
   rule stop (x >= notestinputs);
       $finish(0);
   endrule
      
   
endmodule : mkTb

endpackage : Tb
