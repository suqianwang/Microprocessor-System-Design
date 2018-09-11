module problem1a(X, Y, Z, A, B, C);
	input A, B, C;
	output X, Y, Z;
	wire cbar, andbc;

	not invC (cbar, C);
	and and1 (andbc, B, C);
	or or1 (X, A, andbc);
	and and2 (Y, B, cbar);
	or or2 (Z, Y, A);

endmodule