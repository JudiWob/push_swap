Push_swap is a sorting algorithm project designed for the 42 curriculum, written in C.

The goal of the program is to sort a stack of integers from standard input using the fewest number of operations possible.

The project involves two stacks, A and B, and uses predefined operations to manipulate these stacks.

The program must output the sequence of operations required to achieve a sorted stack.

The challenge lies in finding an efficient way to sort the numbers while adhering to the constraints.

Allowed operations:

sa: Swap the first two elements of stack A.

sb: Swap the first two elements of stack B.

ss: Perform sa and sb simultaneously.

pa: Push the top element from stack B to stack A.

pb: Push the top element from stack A to stack B.

ra: Rotate stack A (move the first element to the bottom).

rb: Rotate stack B (move the first element to the bottom).

rr: Perform ra and rb simultaneously.

rra: Reverse rotate stack A (move the last element to the top).

rrb: Reverse rotate stack B (move the last element to the top).

rrr: Perform rra and rrb simultaneously.


The input must be a list of integers separated by spaces.

-The integers must be unique (no duplicates).

-Negative numbers are allowed.

-The program assumes valid input; invalid input (e.g., non-integer values) will result in an error.

Example input:

$./pushswap 7 2 1

or

$./pushswap "7 2 1" 

The output represents the sequence of operations needed to sort stack A.

