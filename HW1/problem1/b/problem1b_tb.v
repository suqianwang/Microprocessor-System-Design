module problem1_tb;
wire X_out, Y_out, Z_out;
reg A_in, B_in, C_in;

problem1b inst(X_out, Y_out, Z_out, A_in, B_in, C_in);

initial begin
	// initialize inputs to 0
	A_in = 0;
	B_in = 0;
	C_in = 0;

	$monitor ($time, " inputs A: %b, B: %b, C: %b -> outputs X: %b, Y: %b, Z: %b", A_in, B_in, C_in, X_out, Y_out, Z_out);
	
	// delay 10 units each time before inputs change values
	#10 
	// inputs A = 0, B = 1, C = 0, outputs should be X = 0, Y = 1, Z = 1
	A_in = 1'b0;
	B_in = 1'b1;
	C_in = 1'b0;

	#10 
	// inputs A = 1, B = 1, C = 0, outputs should be X = 1, Y = 1, Z = 1
	A_in = 1'b1;
	B_in = 1'b1;
	C_in = 1'b0;

	#10 
	// inputs A = 1, B = 0, C = 1, outputs should be X = 1, Y = 0, Z = 1
	A_in = 1'b1;
	B_in = 1'b0;
	C_in = 1'b1;

	#10 
	// inputs A = 0, B = 0, C = 1, outputs should be X = 0, Y = 0, Z = 0
	A_in = 1'b0;
	B_in = 1'b0;
	C_in = 1'b1;

	#20
	$finish;
end

endmodule