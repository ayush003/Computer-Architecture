package RCA; 

// Ripple Carry Adder

import AdderInterface::*;

(* synthesize *)
module mkRCA( Adder_IFC );

function Bit#(2) fa(Bit#(1) a, Bit#(1) b, Bit#(1) c_in);
   Bit#(1) s = (a ^ b)^ c_in; 
   Bit#(1) c_out = (a & b) | (c_in & (a ^ b)); 
   return {c_out,s}; 
endfunction 

function Bit#(33) rca32(Bit#(32) x, Bit#(32) y); 
   Bit#(32) s; 
   Bit#(33) c=0; 
   c[0] = 0;
   for(Integer i=0; i<32; i=i+1)
   begin
      let cs = fa(x[i],y[i],c[i]);
      c[i+1] = cs[1]; s[i] = cs[0];
   end	
return {c[32],s}; 
endfunction

method  Tout add32(Tin m1, Tin m2);
	return rca32(m1, m2);
endmethod

endmodule : mkRCA
   
endpackage : RCA
