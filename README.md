<h1 align="center">
  
Backtracking Sudoku Solver

![image](https://user-images.githubusercontent.com/54891285/120130520-ff4e7180-c1e3-11eb-8e18-47b4e73f071b.png)

![Cpp](https://img.shields.io/badge/-++-333333?style=flat-square&logo=C) 
<h1>



## STEP Wise Algorithm : 
STEP 1 : Find a block that has no predefined number.

STEP 2 : Return a positive boolean result if all blocks are filled.

STEP 3 : Run a loop running ‘$order_of_matrix’ times

STEP 4a: Assign a digit, that is not already assigned in the row or column or the respective sub-domain, to the block.

STEP 4b: If the digit cannot be filled in the block, the subtree is nullified and the possibility is removed.

STEP 4c: Move on to the next iteration.

STEP 4d: This process is repeated till the criteria of “STEP 2” is fulfilled.

STEP 5 : Return a negative boolean result if none of the digits can be placed in a block(which breaks out of the backtracking algorithm).



