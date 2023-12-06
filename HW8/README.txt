Focus of week 8 was recursive functions.
This directory contains solutions to the following problems:

Q1a/
Give a recursive implement to the following function:
void printTriangle(int n)

This function is given a positive integer n, 
and prints a textual image of a right triangle
(aligned to the left) made of n lines with asterisks.

For example, printTriangle(4), should print:
*
**
***
****


Q1b/
Give a recursive implement to the following function:
void printOppositeTriangles(int n)

This function is given a positive integer n, 
and prints a textual image of a two opposite right
triangles (aligned to the left) with asterisks, 
each containing n lines.

For example, printOppositeTriangles(4), should print:
****
***
**
*
*
**
***
****


Q1c/
Give a recursive implement to the following function:
void printRuler(int n)

This function is given a positive integer n, 
and prints a vertical ruler of 2! − 1 lines. 
Each line contains ‘-‘ marks as follows:
- The line in the middle (1/2) of the ruler contains n ‘-‘ marks
- The lines at the middle of each half (1/4 and 3/4) of the ruler 
  contains (n-1) ‘-‘ marks
- The lines at the 1/8, 3/8, 5/8 and 7/8 of the ruler 
  contains (n-2) ‘-‘ marks
- And so on …
- The lines at the 1/2^k, 3/2^k, 5/2^k, ... 2^k-1/2^k of the ruler 
  contains 1 ‘-‘ mark

For example, printRuler(4), should print (only the blue marks):
-
--
-
---
-
--
-
----
-
--
-
---
-
--
-
*/


Q2a/
Give a recursive implement to the following function:
int sumOfSquares(int arr[], int arrSize)

This function is given arr, an array of integers, 
and its logical size, arrSize. 
When called, it returns the sum of the squares of each of the values in arr.

For example, if arr is an array containing [2, -1, 3, 10], 
calling sumOfSquares(arr, 4)will return 114 
(since, 2^2 + (-1)^2 + 3^2 + 10^2 = 114).


Q2b/ 
Give a recursive implement to the following function:
bool isSorted(int arr[], int arrSize)

This function is given arr, an array of integers, 
and its logical size, arrSize. 
When called, it should return 
true if the elements in arr are sorted in an ascending order, 
or false if they are not.


Q3/
Write two recursive versions of the function minInArray. 
The function will be given a sequence of elements 
and should return the minimum value in that sequence. 
The two versions differ from one another in the technique we use 
to pass the sequence to the function.

In version 1 – The prototype of the function should be:

int minInArray1(int arr[], int arrSize)
Here, the function is given arr, an array of integers, and its logical size, arrSize.
The function should find the minimum value out of all the elements in positions:
0, 1, 2, …, arrSize-1.

In version 2 – The prototype of the function should be:

int minInArray2(int arr[], int low, int high)
Here, the function is given arr, an array of integers, 
and two additional indices: low and high (low ≤ high), 
which indicate the range of indices that need to be considered.
The function should find the minimum value out of all the elements in positions:
low, low+1, …, high.


Q4/
The game of “Jump It” consists of a board with n positive integers in a row, 
except for the first column, which always contains zero. 
These numbers represent the cost to enter each column.

Here is a sample game board where n is 6:
0 3 80 6 57 10

The object of the game is to move from the first column to the last column 
with the lowest total cost.
You always start the game in the first column and have two types of moves. 
You can either move to the adjacent column or jump over the adjacent column 
to land two columns over. 
The cost of a game is the sum of the costs of the visited columns.

Write a recursive function that solves this problem and 
returns the lowest cost of a game board represented and passed as an array.