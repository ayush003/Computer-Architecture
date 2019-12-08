package Multi; 

// Simple (naive) binary multiplier
function Bit#(128) mul16(Bit#(8) a, Bit#(128)b);
    Bit#(128) product=0;
    Bit#(128) mcand = extend(b);
    Bit#(128) mplr = extend(a);
  
    for(Integer i=0; i < 8; i = i+1)
    begin
      if (mplr[i]==1) product = product + mcand;
      mcand = mcand << 1;
    end
  
    return product;
  endfunction
  

import Multiplier::*;

(* synthesize *)
module mkMulti( Multiplier_IFC );
   Reg#(Bool)    available <- mkReg(True);
   Reg#(Tout)    product   <- mkReg(?);
   Reg#(Tout)    mcand     <- mkReg(?);
   Reg#(Tin)     mplr      <- mkReg(0);

   rule cycle ( mplr != 0 );
      $display("Rule cycle fired mcand=%0d mplr=%0d", mcand, mplr);
      //if (mplr[0] == 1) product <= product + mcand;
      product<=product+mul16(mplr[7:0],mcand);
      mcand   <= mcand << 8;
      mplr    <= mplr  >> 8;
   endrule

   method Action start(Tin m1, Tin m2) if ((mplr == 0) && available);
       product <= 0;
       mcand   <= {0, m1};
       mplr    <= m2;
       available <= False;
   endmethod

   method Tout result() if (mplr == 0);
      return product;
   endmethod

   method Action acknowledge() if ((mplr == 0) && !available);
      available <= True;
   endmethod
   
endmodule : mkMulti
   
endpackage : Multi
