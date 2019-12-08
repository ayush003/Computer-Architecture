package AdderInterface; 

// Adder IFC

typedef Bit#(32) Tin;
typedef Bit#(33) Tout;

interface Adder_IFC;
    method Tout  add32(Tin m1, Tin m2);
endinterface
        
endpackage
