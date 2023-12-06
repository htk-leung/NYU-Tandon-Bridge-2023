Focus of week 7 was arrays and pointers.
This directory contains solutions to the following problems:

Q1/
Write a program that will 
- read in a line of text and 
- output the number of words in the line and
- the number of occurrences of each letter.

Define a word to be any string of letters that is delimited at each end 
by either whitespace, a period, a comma, or the beginning or end of the line.

You can assume that the input consists entirely of letters, whitespace, commas, and periods.
When outputting the number of letters that occur in a line, be sure to count upper and
lowercase versions of a letter as the same letter.

Output the letters in alphabetical order and 
list only those letters that do occur in the input line.


Q2/
Two strings are anagrams if the letters can be rearranged to form each other. 

Write a program that determines if two strings are anagrams. 
The program should not be case sensitive and 
should disregard any punctuation or spaces.


Q3/
Implement the function:
void oddsKeepEvensFlip(int arr[], int arrSize)

This function gets an array of integers arr and its logical size arrSize.
When called, it should reorder the elements of arr so that:
1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).

For example, if arr = [5, 2, 11, 7, 6, 4],
after calling oddsKeepEvensFlip(arr, 6), arr will be:
[5, 11, 7, 4, 6, 2]

Implementation requirements:
1. Your function should run in linear time. That is, if there are n items in arr, 
   calling oddsKeepEvensFlip(arr, n) will run in 𝜃(𝑛).
2. Write a main() program that tests this function.
3. Note that at the end, the elements should be stored starting 
   at the same base address, as was given in arr.


Q4/
Implement the function:
string* createWordsArray(string sentence, int& outWordsArrSize)

This function gets a string sentence containing a sentence.
When called, it should create and return a new array (of strings), 
that contains all the words in sentence. 

The function should also update the output parameter, outWordsArrSize, 
with the logical size of the new array that was created.

Note: Assume that the words in the sentence are separated by a single space.
For example, if sentence=”You can do it”, after calling
createWordsArray(sentence, outWordsArrSize), the function should create
and return an array that contains [”You” , ”can” , ”do” , ”it”], and update the
value in outWordsArrSize to be 4.

Implementation requirements:
1. You may want to use some of the string methods, such as find, substr, etc.
2. Your function should run in linear time. 
3. Write a main() program that tests this function.


Q5/
Write four versions of a function getPosNums that 
- gets an array of integers arr, and 
- its logical size. 

When called it creates a new array containing only the positive numbers from arr.
Include a main function.


Q6/
Write two versions of a program that reads from the user 
a sequence of positive integers ending with -1, 
and another positive integer num that the user wishes to search for.

The program should then print all the line numbers in sequence entered by the user,
that contain num, or a message saying that num does not show at all in the sequence.

a/ The first version of the program, is not allowed to use the vector data structure.
b/ The second version of the program, should use the vector data structure.

Implementation requirements (for both programs):
1. Think how to break down your implementation to functions.
2. Your programs should run in linear time.
3. Write the two programs in two functions named main1() and main2(). 
  Also have the main() test these two functions.


Q7/
Implement the function:
int* findMissing(int arr[], int n, int& resArrSize)

This function gets an array of integers arr and its logical size n. 
All elements in arr are in the range {0, 1, 2, … , n}.

Note that since the array contains n numbers taken from a range of size n+1, 
there must be at least one number that is missing 
(could be more than one number missing, if there are duplicate values in arr).

When called, it should create and return a new array, that contains all the numbers in
range {0, 1, 2, … , n} that are not in arr. The function should also update the output
parameter, resArrSize, with the logical size of the new array that was created.

For example, if arr=[3, 1, 3, 0, 6, 4], after calling
findMissing(arr, 6, resArrSize), the function should create and return an
array that contains [2, 5], and update the value in resArrSize to be 2.

Implementation requirements:
1. Your function should run in linear time.
2. Write a main() program that tests this function.