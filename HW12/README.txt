Focus of week 12 was object oriented programming.
This directory contains solutions to the following problem:

Write a checkbook balancing program. 

The program will read in, from the console, 
the following for all checks that were not cashed 
as of the last time you balanced your checkbook:
- The number of each check (int)
- The amount of the check (double)
- Whether or not it has been cashed (1 or 0, boolean in the array)

Setup:

- Use an array with the class as the type. 
- class for a check should have:
  - check number variable 
  - the check amount of type Money (as defined on page 662 in the book; Display 11.9)
  - whether or not the check was cashed 
  - accessor and mutator functions 
  - constructors 
  - functions for both input and output of a check
- program reads:
  - all the deposits (from the console; cin)
  - the old and the new account balance (read this in from the user at the console; cin)
  - You may want another array to hold the deposits. 
- The new account balance should be the old balance plus all deposits,
  minus all checks that have been cashed.

Output:

- total of the checks cashed
- the total of the deposits
- what the new balance should be
- how much this figure differs from what the bank says the new balance is
- two lists of checks: the checks cashed since the last time you balanced your checkbook 
  and the checks still not cashed. [ edit: if you can, Display both lists of checks in
  sorted order from lowest to highest check number.]