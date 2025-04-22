# push_swap

> 🎯 A sorting algorithm challenge using only two stacks and a limited set of operations — part of the 42 curriculum.

## 📚 About

**push_swap** is a project from 42 that challenges students to sort a stack of integers using a constrained set of operations and an auxiliary stack. The goal is to produce the most optimized and efficient sequence of operations possible.

This project is a deep dive into algorithm design, optimization strategies, and working with data structures like linked lists. It also pushes you to balance performance with strict coding constraints.

## 🧠 Objectives

- Implement a sorting algorithm using a restricted set of operations.
- Optimize the number of moves required to sort a stack of up to 500 integers.
  -  
- Handle edge cases and invalid inputs gracefully.
- Understand and implement chunking, indexing, and stack manipulation strategies.

## ⚙️ How It Works

The program takes integers as command-line arguments ( 1 2 3 or " 1 2 3" and outputs the operations needed to sort them in ascending order using only.
The program was designed for up to 500 integers between INT_MAX and INT_MIN.


### Allowed Operations to sort Stack A

- `sa`, `sb`, `ss` — swap top elements of stack A, B, or both
- `pa`, `pb` — push top element from one stack to the other
- `ra`, `rb`, `rr` — rotate stacks (first becomes last)
- `rra`, `rrb`, `rrr` — reverse rotate stacks (last becomes first)

## ✅ Allowd functions
read, write, malloc, free, exit

## ✅ Usage Example

```bash
$ ./push_swap 3 2 1
rra
sa

## 📊 Project Validation Criteria

For maximum project validation (100%) and eligibility for bonuses, you must:
Sort 100 random numbers in fewer than 700 operations.
Sort 500 random numbers in no more than 5500 operations.
For minimal project validation (which implies a minimum grade of 80%), you can succeed with the following averages:
100 numbers in under 1100 operations and 500 numbers in under 8500 operations.
100 numbers in under 700 operations and 500 numbers in under 11500 operations.
