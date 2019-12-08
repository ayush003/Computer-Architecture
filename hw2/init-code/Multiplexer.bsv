import BasicGates::*;

function Bit#(1) multiplexer1(Bit#(1) sel, Bit#(1) a, Bit#(1) b);
	Bit#(1) s0 = 0;
	s0 = or1(and1(not1(sel),a),and1(sel,b));
    	return s0;
endfunction

function Bit#(4) multiplexer4(Bit#(1) sel, Bit#(4) a, Bit#(4) b);
	Bit#(4) s0 = 0;
	for(Integer i = 0;i<4;i=i+1)
	begin
		s0[i] =	multiplexer1(sel,a[i],b[i]);
	end
    return s0;
endfunction

function Bit#(n) multiplexer_n(Bit#(1) sel, Bit#(n) a, Bit#(n) b);
	Bit#(n) s1 = 0;
	for(Integer i = 0;i<valueOf(n);i=i+1)
	begin
		s1[i] = multiplexer1(sel,a[i],b[i]);
	end
    return s1;
endfunction
