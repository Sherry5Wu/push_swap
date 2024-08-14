# **push_swap**

The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted. You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.

Your goal? Write a program in C called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

**The rules**

• You have 2 stacks named a and b. At the beginning:

    ◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.

    ◦ The stack b is empty.

    • The goal is to sort in ascending order numbers into stack a. To do so you have the


**operations at your disposal:**

    sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

    sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

    ss : sa and sb at the same time.

    pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

    pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

    ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.

    rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

    rr : ra and rb at the same time. 

    rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

    rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

    rrr : rra and rrb at the same time.

# Algorithm

	- push everything from STACK_A to STACK_B but in descending order.Why? Because after I push them back to 
 	  STACK_A, they will be automatically sorted.

	- Stacks are kind of circular linked list. It means, the last element of the stack is actually not the 
 	  last element. It is actually an element before the first element.

	-  If the number you push from STACK_A to STACK_B is going to be the new biggest or the smallest number,
 	   you should place it just above the old biggest number in the STACK_B.

     For more clearly explaination, check "https://medium.com/@ayogun/push-swap-c1f5d2d41e97".

## how to find the cheapest cost of a number?
      		

# Resources

	https://medium.com/@ayogun/push-swap-c1f5d2d41e97
 
	https://github.com/ayogun/push_swap/blob/main/includes/push_swap.h
 
	https://github.com/48d31kh413k/1337-push_swap-42/blob/main/src/quicksort.c
 
	https://github.com/LeeSinLiang/Push-Swap/tree/main/srcs

# Testers and Visualizer

	https://github.com/LeoFu9487/push_swap_tester

	https://github.com/o-reo/push_swap_visualizer

# Note

	- Based on the Norminette rules,you just can add comments at the top of the each file. So, please delete the function comments
 	before you push to git.

	- When I included my previous projects libft and get_next_line, I re-edit both of Makefiles and changed some functions' name in 		get_next_line. So you might need adjust yours too, if it is needed.
