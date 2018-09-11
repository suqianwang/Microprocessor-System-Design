1.(25pt)
Implement the circuit X =A+BC, Y =BC′, Z =A+Y in Verilog.

1) (6pt) Implement the circuit using structural modeling.

2) (6pt) Implement the circuit using data-flow modeling.

3) (6pt) Implement the circuit using behavioral modeling.

4) (7pt) Design a testbench to test the above three circuits. Your testbench needs to include at least four different inputs. In your code, explain the inputs that you are testing, and the outputs that you anticipate to see for each of your three circuits. Attach screenshots for the waveforms of these three circuits. (Use the same testbench for all three circuits.)



2. (25pt)
Design a sequential circuit with one synchronous input and one output. The output is ‘1’ if the last four inputs are “1101”. For example, if the inputs are
000111111011011, then the outputs are
000000000010010

1) (10pt) Draw a FSM for this circuit. Use as few states as possible.

2) (8pt) Implement the circuit in Verilog.

3) (7pt) Create a testbench to test your circuit. In your code, explain the inputs that you are testing,
and the outputs that you anticipate to see. Attach a screenshot for the waveforms.



3. (25pt)
In this problem, use hierarchical to implement ripple adders in Verilog. Your ripple adder should be built upon full adders, which are in turn built upon half adders. Assume that all logic gates have one unit delay.

1) (8pt) Implement a four-bit ripple adder.

2) (8pt) Implement an eight-bit ripple adder.

3) (9pt) Design two testbenches to test these two adders. In both testbenches, the inputs change at time
100. When does each adder produce the correct output after the inputs change? What does this say about delay?



4. (25pt)
See Fig. 1 in the next page. In class, I told you that this circuit usually does not make sense. In this problem, design Module X and Module Y so that the figure makes sense. In your design, the outputs of these modules cannot be the same all the time, and their outputs may change if inputs change. (For example, the solution on Fig. 2 is not acceptable.) You can only use the basic logic gates as listed on Page 15 of note01.
1) (15pt) Draw your design. Explain the functionality of your design. 

2) (10pt) Implement your design using structural modeling.
