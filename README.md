## Push_swap
### About the 42 Norm:
- Each file must contain no more than 5 functions.
- Each function must not exceed 25 lines.
- The project must be written solely in C.
- Global variables are not allowed.
- Any crash, leak, or conditional jump is forbidden.
- Allowed external functions are: `read`, `write`, `malloc`, `free`, `exit`.

### Project Overview:
This project aims to implement a **sorting algorithm using two stacks**. Sorting values is simple, sorting them the fastest way possible is another deal.

The program must use two stacks, `a` and `b`. Initially, stack `a` contains unique positive or negative numbers, while stack `b` is empty. The goal is to achieve a fully sorted stack `a` by performing operations within and between the two stacks, using the minimum number of moves.

Only certain operations were allowed:

- sa : Swap the first 2 elements at the top of stack `a`.
- sb : Swap the first 2 elements at the top of stack `b`.
- ss : sa and sb at the same time.

- pa : Take the first telement at the top of `b` and put it at the top of `a`.
- pb : Take the first telement at the top of `a` and put it at the top of `b`.
  
- ra : Shift up all elements of stack `a` by 1.
- rb : Shift up all elements of stack `b` by 1.
- rr : ra and rb at the same time.

- rra : Shift down all elements of stack `a` by 1.
- rrb : Shift dowb all elements of stack `b` by 1.
- rrr : rra and rrb at the same time.

The choice of the algorithm was open, but maximum move thresholds were imposed. I preferred a **butterfly sorting algorithm**, which ensures a small difference between unfavorable and optimal conditions and achieves a good average number of moves.

On execution, the program displays the moves needed to sort the numbers in the most efficient way.

## Preview:

I am using [o-reo's visualizer](https://github.com/o-reo/push_swap_visualizer) to display how the algorithm operates. 500 values are sorted with an average of 5000 moves.

![image](https://github.com/user-attachments/assets/34a6d26f-7b87-4b9b-a08f-239cbf7a2ac8)

![image](https://github.com/user-attachments/assets/096afc0e-7a01-460f-9ac1-fe28c0e327eb)

This shows what the program normally displays:

![image](https://github.com/user-attachments/assets/1e99e5aa-e22e-4f68-b01d-852f6d2c8dae)
