module adder_4_bit_tb;
	reg [3:0] a, b;
	reg cin;
	wire [3:0] sum;
	wire cout;

	four_bit_adder inst(a, b, cin, sum, cout);

	initial begin

		a = 4'b0000;
		b = 4'b0000;
		cin = 1'b0;

		$monitor ($time, " %b + %b (carry in is %b) = %b (carry out is %b)", a, b, cin, sum, cout);

		// should output 0011 with carry 0
		#100
		a = 4'b0001;
		b = 4'b0001;
		cin = 1'b1;

		// should output 1000 with carry 1
		#100
		a = 4'b1001;
		b = 4'b1111;
		cin = 1'b0;

		// should output 1000 with carry 0
		#100
		a = 4'b0101;
		b = 4'b0011;
		cin = 1'b1; 

		#20
		$finish;
	end
endmodule
