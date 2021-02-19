C programming tasks
=============================

Task #1
------------
Write a function which reverse bits of a given number

Task #2
------------
Implement detection of loop in linked-list
For example loop in list:

1 -> 2 -> 3 -|

     ^-------|

Task #3
------------
Write a function with single-linked list as input. Output is pointer to node in the middle of this list. If count of nodes is even, return the left one node on the middle

Task #4
------------
Write function with string as input 
the string could contain 3 types of braces (), {}, []

Function must validate if braces are correct or not
example:
({)} = not valid
{()} = valid

Task #5
------------
Write a function for counting islands. Input a matrix:

{{1, 1, 0, 0, 0},
 {0, 1, 0, 0, 1},
 {1, 0, 0, 1, 1},
 {0, 0, 0, 0, 0},
 {1, 0, 1, 0, 1}} 
 
Where:
1 - ground, 0 - water.
Ground connects with ground only horizontally or vertically
So, count of islands in the example is 6

Task #6
------------
modify previous solution. Now ground is connecting to ground in any direction 
So, now the count of islands in the example is 5

Task #7
------------
Implement cache with next operations:
put() - add element to the cache
get() - receive last added element from the cache
remove() - delete element from the cache

All operations should have time complexity O(1)

Task #8
------------
Read data from file
The first number is N, the second M, all next numbers are elements of the matrix NxM. Elements type int

Matrix is the map where element is altitude.
Calculate the volume of water if this region will be flooded

Example
{{1, 1, 1, 1, 1},
 {1, 0, 0, 0, 1},
 {1, 0, 8, 0, 1},
 {1, 0, -5, 0, 1},
 {1, 0, 0, 0, 1},
 {1, 1, 1, 1, 1},} 
 
Answer is 15
