package Pipe; 

import PipeMultiplier::*;

typedef struct{
  Reg#(Bool) valid;
  Reg#(Tin) mplr;
  Reg#(Tout) mpcand;
  Reg#(Tout) psum;
} PipeRegister;

(* synthesize *)
module mkPipe( Multiplier_IFC );

// Input register creation and initialization
   PipeRegister inputReg;
   inputReg.valid <- mkReg(False);
   inputReg.mplr <- mkRegU();
   inputReg.mpcand <- mkRegU();
   inputReg.psum <- mkReg(0);

// Output register creation and initialization
   PipeRegister outputReg;
   outputReg.valid <- mkReg(False);
   outputReg.mplr <- mkRegU();
   outputReg.mpcand <- mkRegU();
   outputReg.psum <- mkRegU();

// Inter-stage pipeline registers creation and initialization
   PipeRegister stageRegs[15];
   for(Integer i=0; i < 15; i=i+1) 
   begin
   	stageRegs[i].valid <- mkReg(False);
   	stageRegs[i].mplr <- mkRegU();
   	stageRegs[i].mpcand <- mkRegU();
   	stageRegs[i].psum <- mkRegU();
   end

//This rule fires all the time.
   rule cycle ;
  // This is where the actual compute logic is. Fill it in.


    
   endrule

   method Action multiply(Tin m1, Tin m2) ;
        // How do you supply inputs. Fill it in.



   endmethod

   method Tout result() ; 
        // How do you read the output. Fill it in.


   endmethod

endmodule : mkPipe
   
endpackage : Pipe 
