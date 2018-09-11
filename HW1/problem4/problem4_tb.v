module problem4_tb;
    
    reg A;
    reg B;
    wire F;
    
    problem4 uut_problem4(
        .A(A),
        .B(B),
        .F(F)
    );
    
    initial begin
        A = 0;
        B = 0;
        
        #10;
        
        $monitor($time, " A = %b, B = %b, F = %b", A, B, F);
        
        #10 A = 0; B = 0;   // should output 0
        #10 A = 0; B = 1;   // should output 1
        #10 A = 1; B = 0;   // should output 1              
        #10 A = 1; B = 1;   // should output 0
        #10 $finish;
        
    end
endmodule
