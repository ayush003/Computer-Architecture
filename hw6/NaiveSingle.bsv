package NaiveSingle; 


import SingleMultiplier::*;

(* synthesize *)
module mkNaiveSingle( Multiplier_IFC );

function Bit#(128) mul16(Bit#(64) a, Bit#( 64)b);
  Bit#(128) product=0;
  Bit#(128) mcand = extend(b);
  Bit#(128) mplr = extend(a);

  for(Integer i=0; i < 64; i = i+1)
  begin
    if (mplr[i]==1) product = product + mcand;
    mcand = mcand << 1;
  end

  return product;
endfunction

method  Tout multiply(Tin m1, Tin m2);
	return mul16(m1, m2);
endmethod

endmodule : mkNaiveSingle
   
endpackage : NaiveSingle 
