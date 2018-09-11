module problem1c(X, Y, Z, A, B, C);
	input A, B, C;
	output reg X, Y, Z;

	always @ (A, B, C)
	begin
		X <= A | (B & C);
		Y <= B & (~C);
		Z <= A | Y;
	end

endmodule