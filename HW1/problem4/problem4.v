module X (
    input A,
    input B,
    output F
    );
    
    bufif0 (F, A, B);
    
endmodule

module Y (
    input A,
    input B,
    output F
    );
    
    wire Abar;
    not invA (Abar, A);
    bufif1 (F, Abar, B);
    
endmodule
    

module problem4(
    input A,
    input B,
    output F
    );
    
    X uut_X(
        .A(A),
        .B(B),
        .F(F)
    );
    
    Y uut_Y(
        .A(A),
        .B(B),
        .F(F)
    );
    
endmodule
