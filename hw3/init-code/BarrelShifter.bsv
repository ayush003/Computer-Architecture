import Vector::*;


function Bit#(32) multiplexer32(Bit#(1) sel, Bit#(32) a, Bit#(32) b);
    
	return (sel == 0)?a:b; 

endfunction

function Bit#(32) logicalBarrelShifter(Bit#(32) operand, Bit#(5) shamt);
	Bit#(32) rs = 0;
	Bit#(32) s0=0;
	Bit#(32) s1 = 0;
	rs[31] = 0;
	for(Integer i = 31;i>0;i=i-1)
	begin
		rs[i-1] = operand[i];
	end
	s0 = multiplexer32(shamt[0],operand,rs);
	
	rs[31:30] = 0;
	for(Integer i = 31;i>1;i=i-1)
	begin
		rs[i-2] = s0[i];
	end
	s1 = multiplexer32(shamt[1],s0,rs);
	
	rs[31:28] = 0;
	for(Integer i = 31;i>3;i=i-1)
	begin
		rs[i-4] = s1[i];
	end
	s0 = multiplexer32(shamt[2],s1,rs);
	
	rs[31:24] = 0;
	for(Integer i =31;i>7;i=i-1)
	begin
		rs[i-8] = s0[i];
	end	
	s1 = multiplexer32(shamt[3],s0,rs);

	rs[31:16] = 0;
	for(Integer i = 31;i>15;i=i-1)
	begin
		rs[i-16] = s1[i];
	end
		s0 = multiplexer32(shamt[4],s1,rs);

	return s0;
endfunction

function Bit#(32) arithmeticBarrelShifter(Bit#(32) operand, Bit#(5) shamt);
        Bit#(32) rs = 0;
        Bit#(32) s0=0;
        Bit#(32) s1 = 0;
        rs[31] = operand[31];
        for(Integer i = 31;i>0;i=i-1)
        begin
                rs[i-1] = operand[i];
        end
        s0 = multiplexer32(shamt[0],operand,rs);
	
        rs[31] = s0[31];
	rs[30] = s0[31];
        for(Integer i = 31;i>1;i=i-1)
        begin
                rs[i-2] = s0[i];
        end
        s1 = multiplexer32(shamt[1],s0,rs);

	for(Integer i =31;i>27;i=i-1)
	begin
		rs[i] = s1[31];
	end
        for(Integer i = 31;i>3;i=i-1)
        begin
                rs[i-4] = s1[i];
        end
        s0 = multiplexer32(shamt[2],s1,rs);

	  for(Integer i =31;i>23;i=i-1)
        begin
                rs[i] = s0[31];
        end
        for(Integer i =31;i>7;i=i-1)
        begin
                rs[i-8] = s0[i];
        end
        s1 = multiplexer32(shamt[3],s0,rs);

	  for(Integer i =31;i>15;i=i-1)
        begin
                rs[i] = s1[31];
        end

        for(Integer i = 31;i>15;i=i-1)
        begin
                rs[i-16] = s1[i];
        end
        s0 = multiplexer32(shamt[4],s1,rs);

        return s0;	
endfunction

function Bit#(32) logicalLeftRightBarrelShifter(Bit#(1) shiftLeft, Bit#(32) operand, Bit#(5) shamt);
	Bit#(32) sr =0;
	Bit#(32) ans = 0;
	Bit#(32) rev = 0;
	Bit#(32) slTemp = 0;	
	sr = logicalBarrelShifter(operand,shamt);
	for(Integer i = 0;i<32;i=i+1)
	begin
		rev[i] = operand[31-i];
	end
	slTemp = logicalBarrelShifter(rev,shamt);
	for(Integer i =0;i<32;i=i+1)
	begin
		rev[i] = slTemp[31-i];
	end
	ans = multiplexer32(shiftLeft,sr,rev);
	return ans;
endfunction

