LABNAME = Design and analysis of a 32-bit ripple carry adder circuit.
SHORTNAME = rca32 
SMOKENAME = rca32 

## Default simulator is iverilog
VSIM = -vsim iverilog

.PHONY: help
help:
	@echo "Lab: $(LABNAME)"
	@echo "Useful targets:"
	@echo "rca32 -- Builds a 32-bit ripple carry adder circuit."
	@echo "  clean          --  remove intermediate files"
	@echo "  help           --  display this message"

#.PHONY: single
rca32: AdderInterface.bsv RCA.bsv Tb.bsv
	@echo "Compiling into verilog files"
	bsc -verilog -u Tb.bsv	
	@echo "Generting the simulation object"
	bsc -verilog -e  mkTb -o rca32Tb.bsim

.PHONY: clean
clean:
	@rm -f *.bi *.bo *.ba mk*.c mk*.h mk*.o mk*.v *_c *_v *.vcd *~ *.fsdb *.log *.bsim
