# SIM-Microprocessor
This program is done as a part of the course Object Oriented Programming in The American University in Cairo as instructed in Fall 2018 and taught by Dr. Sherif El Qasas.

# Description
The project provide the implementation of a class called SIM and its dependencies that simulate the behaviour of a microprocessor which has both an instruction memory and data memory. The microprocessor has support for the main instructions described below.

# Input instructions syntax:

ADD in1, in2, out
MUL in1, in2, out
LE  in1, in2, out

NEG in, out
ASS in, out

JMP a1
JMP0 in1, a1

READ x
WRITE x

HALT

# Notes on syntax
1) Operands can spaced seperated or comma seperated
2) Some operands are allowed to either addresses or operands
3) Address Operands should be preceeded directly by x i.e x0 or x1
4) For immediate values and memory addresses kindly use decimal representations.


# Notes on Usage

