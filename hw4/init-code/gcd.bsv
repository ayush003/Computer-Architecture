interface LGCD;
    method Action start(int a, int b);
    method int result();
    method Bool busy;
endinterface

module mkLGCD (LGCD);
    /*DO NOT change these registers, remove or add more registers*/
    Reg#(int) x <- mkReg(0);
    Reg#(int) y <- mkReg(0);
    Reg#(Bool) bz <- mkReg(False);

    /*feel FREE to add delete or change the name of the rules*/
    rule swapANDsub (x>y && bz == True);
	x <= y;
	y <= x-y;  
    endrule
    rule subtract (y >= x && bz == True);
	y <= y-x;
    endrule
    rule stop (x == 0);
	bz <= False;	
    endrule

    /*Do not change the signature of the method */
    method Action start(int a, int b) if(bz == False); 
	if(a <=0 ||  b <=0)
	begin
	 $display("ERROR");
	end
	else
	begin		
		x <= a;
		y <= b;
		bz <= True;
	end
    endmethod
    method int result() if(bz == False);
	return y;
    endmethod
    method Bool busy;
        return bz;
    endmethod

endmodule

