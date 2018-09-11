
module problem2 (clk, rst, in, out);
	input clk, rst, in;
	output out;

	parameter s0 = 2'b00;	// all other states
	parameter s1 = 2'b01;	// have input sequence 1
	parameter s2 = 2'b10;	// have input sequence 11
	parameter s3 = 2'b11;	// have input sequence 110

	reg [1:0] p_state, n_state;
    reg out;

    // synchronize state
    always @ (posedge clk)
	begin
		if (rst) 
			p_state <= s0;
		else
			p_state <= n_state;
	end

	// transfer state based on input and generate output
	always  @ (p_state, in, rst)
	begin
	    if (rst)
	    begin
	       out = 1'b0;
	       n_state = s0;
	    end
		case(p_state)
			s0: if (in == 1'b1)
				begin
					n_state = s1;
					out = 1'b0;
				end
				else
				begin
					n_state = s0;
					out = 1'b0;
				end
			s1: if (in == 1'b1)
				begin
					n_state = s2;
					out = 1'b0;
				end
				else
				begin
					n_state = s0;
					out = 1'b0;
				end
			s2: if (in == 1'b0)
				begin
					n_state = s3;
					out = 1'b0;
				end
				else
				begin
					n_state = s2;
					out = 1'b0;
				end
			s3: if (in == 1'b1)
				begin
					n_state = s1;
					out = 1'b1;
				end
				else
				begin
					n_state = s0;
					out = 1'b0;
				end
			default:
			    begin
				    n_state = s0;
				    out = 1'b0;
				end
		endcase
	end
	
endmodule