
<h1 align="center">Stack, Queues - LIFO, FIFO</h1>




<h2>Description</h2>

I built a monty files (.m) interpreter with C programming language. Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. We implement some op_codes like add, pop and print elements from the stack/queue.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:


<h2>Usage</h2>

You have to clone this repo and compile with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

<br>$ git clone https://github.com/tennin12/monty
<br>$ cd monty
<br>$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
<br>$ ./monty 000.m
<br><br><br>000.m is the file containing monty commands


<h2>Valid op_codes</h2>

 <br><strong>push</strong>: pushes an element to the stack
 <br><strong>pall</strong>: prints all the values on the stack
 <br><strong>pint</strong>: prints the value at the top of the stack
 <br><strong>pop</strong>: removes the top element of the stack
 <br><strong>swap</strong>: swaps the top two elements of the stack
 <br><strong>add</strong>: adds the top two elements of the stack
 <br><strong>nop</strong>: doesn’t do anything
 <br><strong>sub</strong>: subtracts the top element of the stack from the second top element of the stack
 <br><strong>div</strong>: divides the second top element of the stack by the top element of the stack
 <br><strong>mul</strong>: multiplies the second top element of the stack with the top element of the stack
 <br><strong>mod</strong>: computes the rest of the division of the second top element of the stack by the top element of the stack
 <br>#: Every good language comes with the capability of commenting.
 <br><strong>pchar</strong>: prints the char at the top of the stack
 <br><strong>pstr</strong>: prints the string starting at the top of the stack
 <br><strong>rotl</strong>: rotates the stack to the top
 <br><strong>rotr</strong>: rotates the stack to the bottom
 <br><strong>stack</strong>: sets the format of the data to a stack (LIFO). This is the default behavior of the program
 <br><strong>queue</strong>: sets the format of the data to a queue (FIFO)



<h2>Examples</h2>

<pre>$ cat 00.m
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
</pre>

<pre>$ cat 01.m
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
2</pre>

<pre>$ cat 02.m
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
</pre>

<pre>$ cat 03.m
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
</pre>


<h2>Authors</h2>

Bassem B. Yahia.
