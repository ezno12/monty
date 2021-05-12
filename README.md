                                             #Stack, Queues - LIFO, FIFO
                                             
                                             
##Description

I built a monty files (.m) interpreter with C programming language. Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. We implement some op_codes like add, pop and print elements from the stack/queue.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:


##Usage

You have to clone this repo and compile with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

$ git clone https://github.com/andergcp/monty
$ cd monty
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$ ./monty 000.m
000.m is the file containing monty commands


##Valid op_codes

 push: pushes an element to the stack
 pall: prints all the values on the stack
 pint: prints the value at the top of the stack
 pop: removes the top element of the stack
 swap: swaps the top two elements of the stack
 add: adds the top two elements of the stack
 nop: doesn’t do anything
 sub: subtracts the top element of the stack from the second top element of the stack
 div: divides the second top element of the stack by the top element of the stack
 mul: multiplies the second top element of the stack with the top element of the stack
 mod: computes the rest of the division of the second top element of the stack by the top element of the stack
 #: Every good language comes with the capability of commenting.
 pchar: prints the char at the top of the stack
 pstr: prints the string starting at the top of the stack
 rotl: rotates the stack to the top
 rotr: rotates the stack to the bottom
 stack: sets the format of the data to a stack (LIFO). This is the default behavior of the program
 queue: sets the format of the data to a queue (FIFO)



##Examples

$ cat 00.m
push 0 working with stacks
push 1
push 2
  push 3
                   pall
      push    4        
pall
pint

$ ./monty 00.m
3
2
1
0
4
3
2
1
0
4

$ cat 01.m
push 1
push 2
push 3
pall
pop
pint

$ ./monty 01.m
3
2
1
2

$ cat 02.m
push 1
push 2
push 3
pall
swap

$ ./monty 02.m
3
2
1
2
3
1

$ cat 03.m
push 1
push 2
push 3
pall
add
pall

$ ./monty 03.m
3
2
1
5
1

#Authors

Bassem B. Yahia.
