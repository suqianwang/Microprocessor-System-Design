module half_adder(
    input a,
    input b,
    output sum,
    output carry
    );
    
    xor #1 xor1 (sum, a, b);
    and #1 and1 (carry, a, b);
    
endmodule

// build with two half adder
module full_adder(
    input a,
    input b,
    input cin,
    output sum,
    output cout
    );
    
    // wire outputs from the half adder
    wire sum_0;
    wire carry_0;
    wire carry_1;
    
    half_adder uut0_half_adder(a, b, sum_0, carry_0);
    half_adder uut1_half_adder(cin, sum_0, sum, carry_1);
    
    or #1 or1(cout, carry_0, carry_1);
    
endmodule

// build with four concatenate full adder 
module four_bit_adder(
    input [3:0] a,
    input [3:0] b,
    input cin,
    output [3:0] sum,
    output cout
    );
    
    // wire the carry generated by full adder
    wire [2:0] carry_inner;
    
    full_adder uut0_full_adder(
        .a(a[0]),
        .b(b[0]),
        .cin(cin),
        .sum(sum[0]),
        .cout(carry_inner[0])
        );
        
    full_adder uut1_full_adder(
        .a(a[1]),
        .b(b[1]),
        .cin(carry_inner[0]),
        .sum(sum[1]),
        .cout(carry_inner[1])
        );
        
    full_adder uut2_full_adder(
        .a(a[2]),
        .b(b[2]),
        .cin(carry_inner[1]),
        .sum(sum[2]),
        .cout(carry_inner[2])
        );
        
    full_adder uut3_full_adder(
        .a(a[3]),
        .b(b[3]),
        .cin(carry_inner[2]),
        .sum(sum[3]),
        .cout(cout)
        );
        
endmodule

// build with two concatenate 4-bit adder     
module eight_bit_adder(
    input [7:0] a,
    input [7:0] b,
    input cin,
    output [7:0] sum,
    output cout
    );
    
    wire carry_inner;
    
    four_bit_adder uut0_four_bit_adder(
        .a(a[3:0]),
        .b(b[3:0]),
        .cin(cin),
        .sum(sum[3:0]),
        .cout(carry_inner)
    );
    
    four_bit_adder uut1_four_bit_adder(
        .a(a[7:4]),
        .b(b[7:4]),
        .cin(carry_inner),
        .sum(sum[7:4]),
        .cout(cout)
    );
    
endmodule
