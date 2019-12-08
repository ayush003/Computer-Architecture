package PipeTbLFSR;

// testbench for Pipe

import PipeMultiplier::*;
import Pipe::*;
import LFSR::*;
import FIFO::*;


typedef struct { Tin op1; Tin op2; Tout product; } TestData deriving (Bits);

Tin notestinputs=100;



(* synthesize *)
module mkPipeTbLFSR (Empty);

   Reg#(Bit#(32)) cyclecount <- mkReg(0);
   FIFO#(TestData) testdata <-mkSizedFIFO(20);
   LFSR#(Bit#(32)) lfsr1 <- mkLFSR_32;
   LFSR#(Bit#(32)) lfsr2 <- mkLFSR_32;

   Reg#(Tin) x <- mkReg(1);
   Reg#(Bool) starting <- mkReg(True);

   
   // The dut
   Multiplier_IFC dut <- mkPipe;
   
   // RULES ----------------
   
   rule countcycles;
  	cyclecount <= cyclecount + 1;
        $display("Cycle%0d\n", cyclecount);
   endrule

   rule start (starting);
	   starting <= False;
	   lfsr1.seed('h11);
	   lfsr2.seed('h21);
   endrule

   rule rule_tb ((x < notestinputs) && !starting );
      TestData testpoint;
  // Uncomment the following 2 lines for randomized testing
     //Tin op1 = truncate(lfsr1.value());
     // Tin op2 = truncate(lfsr2.value());
      Tin op1 = x;
      Tin op2 = x+1;
      Tout expected;
      $display("Sending op1 %d op2 %d\n for multiplication\n", op1, op2);
      dut.multiply (op1, op2);
      expected = extend(op1)*extend(op2);
      testpoint.op1 = op1;
      testpoint.op2 = op2;
      testpoint.product = expected;
      testdata.enq(testpoint);
      lfsr1.next();
      lfsr2.next();
      x <= x + 1;
   endrule
   
   rule readoutput (x>=18 && x<=notestinputs+18);
	TestData exp;
	Tout act;
	exp = testdata.first(); testdata.deq();
	act = dut.result();
	if (exp.product!=act) 
        begin
		$display("Bug @x=%d: op1 %d op2 %d result %d expected %d\n",x, exp.op1,exp.op2, act, exp.product );
		$finish(0);
        end 
   endrule

   // TASK: Add a rule to invoke $finish(0) at the appropriate moment
   rule stop (x >= notestinputs);
       $finish(0);
   endrule
      
   
endmodule : mkPipeTbLFSR

endpackage : PipeTbLFSR
