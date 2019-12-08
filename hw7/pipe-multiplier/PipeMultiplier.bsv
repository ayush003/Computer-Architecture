package PipeMultiplier; 

// Multiplier IFC

typedef Bit#(16) Tin;
typedef Bit#(32) Tout;

interface Multiplier_IFC;
    method Action  multiply(Tin m1, Tin m2);
    method Tout result(); 
endinterface
        
endpackage
