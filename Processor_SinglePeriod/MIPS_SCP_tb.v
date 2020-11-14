
`include "MIPS_SCP.v"

`timescale 1ns/1ns

module MIPS_SCP_tb;

	//Inputs
	reg clk;
    	reg reset;

	//Outputs


	//Instantiation of Unit Under Test
	MIPS_SCP uut (
		.clk(clk),
		.reset(reset)
	);

    always #5 clk=!clk;
	initial begin
      
      $dumpfile("dump.vcd"); $dumpvars;
      
	clk=0;
	reset=1;
	#10; //cycle 1
      repeat(10000) begin
	reset=0;
	#10;
      end
      $finish;
  	end
 

endmodule

