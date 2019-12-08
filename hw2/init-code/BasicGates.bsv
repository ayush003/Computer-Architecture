function Bit#(1) and1(Bit#(1) a, Bit#(1) b); 
    return a & b; 
endfunction 
 
function Bit#(1) or1(Bit#(1) a, Bit#(1) b); 
    return a | b; 
endfunction 
 
function Bit#(1) xor1( Bit#(1) a, Bit#(1) b ); 
    return a ^ b; 
endfunction 
 
function Bit#(1) not1(Bit#(1) a); 
    return ~ a; 
endfunction 
