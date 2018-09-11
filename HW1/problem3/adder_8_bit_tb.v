module adder_8_bit_tb;
	reg [7:0] a, b;
	reg cin;
	wire [7:0] sum;
	wire cout;

	eight_bit_adder inst(a, b, cin, sum, cout);

	initial begin

		a = 8'b0;
		b = 8'b0;
		cin = 1'b0;

		$monitor ($time, " %b + %b (carry in is %b) = %b (carry out is %b)", a, b, cin, sum, cout);

		// should output 01000011 with carry 1
		#100
		a = 8'b11110001;
		b = 8'b01010001;
		cin = 1'b1;

		// should output 00000111 with carry 1
		#100
		a = 8'b10010111;
		b = 8'b11110000;
		cin = 1'b0;

		// should output 10111000 with carry 0
		#100
		a = 8'b00110101;
		b = 8'b10000011;
		cin = 1'b1; 

		#20
		$finish;
	end
endmodule