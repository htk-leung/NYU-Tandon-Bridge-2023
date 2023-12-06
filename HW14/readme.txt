Focus of week 14 was sorting and searching algorithms.
This directory contains solution to the following problem:

The following divide-and-conquer algorithm is proposed for 
finding the simultaneous maximum and minimum: 

- If there is one item, it is the maximum and minimum, and 
- if there are two items, then compare them, and in one comparison 
  you can find the maximum and minimum. 
- Otherwise, split the input into two halves, divided as evenly as possible 
  (if N is odd, one of the two halves will have one more element than the other). 
  Recursively find the maximum and minimum of each half, and then 
  in two additional comparisons produce the maximum and minimum for the entire problem.

Setup:
Write the above function which will take in a vector.
Include a main that tests your function.

Output: 
Produce a vector of two elements, the min and max. 