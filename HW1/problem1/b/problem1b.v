module problem1b(X, Y, Z, A, B, C);
	input A, B, C;
	output X, Y, Z;

	assign X = A | (B & C);
	assign Y = B & (~C);
	assign Z = A | Y;

endmodule