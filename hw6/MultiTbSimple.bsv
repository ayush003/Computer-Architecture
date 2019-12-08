package MultiTbSimple;

// testbench for Multi

import Multiplier::*;
import Multi::*;
import LFSR::*;

Tin notestinputs=1;

(* synthesize *)
module mkMultiTbSimple (Empty);

   Reg#(Tin) x    <- mkReg(0);
   Reg#(Bool) starting <- mkReg(True);

   
   // The dut
   Multiplier_IFC dut <- mkMulti;
   
   // RULES ----------------
   
   rule start (starting);
	   starting <= False;
	endrule

   rule rule_tb_1 ((x < notestinputs) && !starting );
      dut.start ('b100, 'b110);
   endrule
   
   rule rule_tb_2 (x < notestinputs);
      let z = dut.result();
	  Tout expected = 'b100 * 'b110;
      x <= x + 1;
      dut.acknowledge();

      $display("    Result = %d Expected = %d", z, expected);
	  if (z != expected) $finish(0);
   endrule

   // TASK: Add a rule to invoke $finish(0) at the appropriate moment
   rule stop (x >= notestinputs);
       $finish(0);
   endrule
      
   
endmodule : mkMultiTbSimple

endpackage : MultiTbSimple

