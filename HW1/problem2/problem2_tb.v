module problem2_tb;
reg clk, rst, in;
wire out;

problem2 inst(clk, rst, in, out);

initial begin
	clk = 0;
	forever #5 clk = ~clk;
end

initial begin
    rst = 0;
    in = 0;
    
	$monitor ($time, " input: %b -> output: %b", in, out);
	#10 rst = 1;
	#10 rst = 0;
	#6;
	
	#10 in = 0;
	#10 in = 0;
	#10 in = 0;
	#10 in = 1;
	#10 in = 1;
	#10 in = 1;
	#10 in = 1;
	#10 in = 1;
	#10 in = 1;
	#10 in = 0;
	#10 in = 1;
	#10 in = 1;
	#10 in = 0;
	#10 in = 1;
	#10 in = 1;
	#20 $finish;
end

endmodule

