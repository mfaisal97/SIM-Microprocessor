add 0,0, x0         #0  testing 2 immediates >> mem[0] = 0
add 0,x0,x0         #1  testing one immediate and one memory address >> mem[0] = 0
add x0,x0,x0        #2  testing 2 memory addresses >> mem[0] = 0
add x0,0,x0         #3  testing one immediate and one memory address(reverse) >> mem[0] = 0

add 1 ,0 , x1       #4  loading one in address one >> mem[1] = 1
ass 2,x2            #5  loading one in address two >> mem[2] = 2
add 3,0, x3         #6  loading one in address one >> mem[3] = 3

mul x2,2, x4        #7  mem[4] = 4
jmp  x10            #8  jmuping to 10
add   5, 0, x5      #9  mem[5] = 5      (if jmup working this should not be executed)
add 7,0, x7         #10 mem[7] = 7      ((if jmup working this should be execute))

jmp0 x1, x13        #11 should jump to 11
add 8,0, x8         #12 mem[8] = 8      should not be executed
add -9,18, x9       #13 mem[9] = 9      should be executed

neg x1,x1           #14 mem[1] = -mem[1] = -1
neg x1,x1           #15 mem[1] = -mem[1] = 1

le x1,x1, x15       #16 mem[15] = 1
le x1,x2,x16        #17 mem[16] = 1
le x2,x1,x16        #18 mem[18] = 0

read x17
write x17

halt
ass 21, x20
ass 20, x20
