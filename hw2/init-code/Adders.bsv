import Multiplexer::*;
import BasicGates::*;
// Full adder functions


function Bit#(1) fa_sum( Bit#(1) a, Bit#(1) b, Bit#(1) c_in );
    return xor1( xor1( a, b ), c_in );
endfunction

function Bit#(1) fa_carry( Bit#(1) a, Bit#(1) b, Bit#(1) c_in );
    return or1( and1( a, b ), and1( xor1( a, b ), c_in ) );
endfunction

// 4 Bit full adder

function Bit#(5) add4( Bit#(4) a, Bit#(4) b, Bit#(1) c_in );
	Bit#(4) sum = 0;
	Bit#(5) carry = 0;
	carry[0] = c_in;
	for(Integer i=0;i<4;i=i+1)
	begin
		sum[i] = fa_sum(a[i],b[i],carry[i]);
		carry[i+1] = fa_carry(a[i],b[i],carry[i]);
	end
    	return {carry[4],sum};
endfunction

// 8 Bit ripple carry adder
function Bit#(9) add8( Bit#(8) a, Bit#(8) b, Bit#(1) c_in );
	Bit#(5) ansTemp=0;
	Bit#(2) carry = 0;
	Bit#(8) sum = 0;
	ansTemp = add4(a[3:0],b[3:0],c_in);
	carry[0] = ansTemp[4];
	sum[3:0] = ansTemp[3:0];
	ansTemp = add4(a[7:4],b[7:4],carry[0]);
	sum[7:4] = ansTemp[3:0];
	carry[1] = ansTemp[4];
	return {carry[1],sum};
endfunction

// 8 Bit carry select adder
function Bit#(9) cs_add8( Bit#(8) a, Bit#(8) b, Bit#(1) c_in );
	Bit#(5) s2 = 0;
	Bit#(2) carry = 0;
	Bit#(5) s0 = 0;
	Bit#(5) s1 = 0;
	Bit#(8) s00 = 0;
	Bit#(8) s10 = 0;
	Bit#(8) s3 = 0;
	Bit#(1) car = 0;
	s2 = add4(a[3:0],b[3:0],c_in);
	carry[0] = s2[4];
	s0 = add4(a[7:4],b[7:4],0);
	s1 = add4(a[7:4],b[7:4],1);	

	for(Integer i =0 ;i<4;i=i+1)
	begin
		s00[i] = s2[i];
		s10[i] = s2[i];
	end
	for(Integer i = 4;i<8;i=i+1)
	begin
		s00[i]=s0[i-4];
		s10[i] = s1[i-4];
	end
	
	s3 = multiplexer_n(carry[0],s00,s10);	    
	car = multiplexer_n(carry[0],s0[4],s1[4]);
return {car,s3};
endfunction
