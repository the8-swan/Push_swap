
This project has been created as part of the 42 curriculum by **obakri**
# Push_swap project
A sorting algorithm project that sorts data on a stack using a limited set of operations, with the goal of using the fewest number of operations possible.
## Description : 
Push_swap is an algorithmic project that challenges you to sort a stack of integers using only two stacks (A and B) and a specific set of operations. The goal is to sort stack A in ascending order with the minimum number of moves.

Performance Targets :

- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700-900 operations
- 500 numbers: ≤ 5500 operations

**Bonus: Checker Program**

The bonus part includes a checker program that reads operations from standard input and verifies whether they correctly sort the stack.
## Instruction : 

### Compilation :
``` bash
# Compile push_swap
make

# Compile bonus (checker)
make bonus

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
  ```
### Execution :
#### Push swap :
```bash
# space separated arguments
./push_swap 3 2 1 5 4

# Single string argument
./push_swap "3 2 1 5 4"

# With negative numbers
./push_swap -5 2 -8 0 3

# Test with random numbers
./push_swap $(shuf -i 1-100 -n 100 | tr '\n' ' ')
```
#### Checker : 
```bash 
# Pipe push_swap output to checker
./push_swap 3 2 1 | ./checker 3 2 1
```
## Resources

- [Push Swap an Efficient Positional Sorting Algorithm Mia Combeau](https://www.scribd.com/document/867832808/Push-Swap-an-Efficient-Positional-Sorting-Algorithm-Mia-Combeau)
- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [push_swap | Guide - GitBook](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
- [Push_Swap Turk algorithm explained in 6 steps](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

## AI Usage :
- Testing strategies: Generating comprehensive test cases and edge case scenarios
- Documentation: Structuring this README file

### Author :
**obakri - 42 Student**

_For questions or improvements, feel free to open an issue or submit a pull request._