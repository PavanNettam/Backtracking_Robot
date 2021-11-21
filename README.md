# Backtrack
Backtracking algorithm is constructed with an explicit stack

A particular ‘RPA’ firm is in the process of developing a restaurant which has bot waiters. Bot needs to deliver the food from the specified exit door, of the kitchen with multiple exit doors to the specified table.
The restaurant has blocked areas where Bot cannot move and the passages where it can move. The layout of restaurant can be rectangular or square.
Layout map can be considered as a matrix of cells where cell with ‘0’ represents the passage and cell with ‘1’, the blocked area. Bot has memorised this map in a particular format for faster processing. Given a particular table location bot needs to find the path from the kitchen from the specified exit door to the table to serve the customer. Bot has a constraint it can move only in either right or down direction one step at a time (i.e. only to the adjacent cell in right or down direction provided it is not blocked) with first preference to right direction.
Layout matrix is stored in the file input.txt
You need to provide the code that helps the bot with the path form specific exit door of the kitchen to the mentioned table if there exists the one. If multiple paths exists your code should find any one.
Implementation
Your code should provide the following functionalities 1. Readmap
Layout matrix consists for ‘0’ (allowed for moving) and ‘1’ (Blocked area)
Your code should read the layout matrix from the file input.txt (file reading) and store as multilist data structure (Reference multilinked list representation of sparse matrix).
You need to scan layout matrix and create node whenever ‘0’ is encountered in input file. Node should maintain x coordinate, y coordinate (coordinate position with respect to input file, indexing starts from 0) for each location
  with ‘0’ value, link to the next node in the same row, link to the next node in the same column.
2. Findpath
Help bot to find path from the start point to the end point if one exists.
You should access data only from the created multilinked list structure. You should provide iterative implementation for this functionality. You can use any data structure studied in unit2 as auxiliary data structure to hold the nodes. There could be multiple paths, you program should find out any one of the available paths which satisfy the constraint.
3. Storepath
Your program should create output file out.txt
If path exits, program should store path coordinates in sorted order (ascending order of x, for each x ascending order of y) (No other format for output is accepted). If no path exists ‘-1’ should be stored in output file.
Input file description
First line indicates the start point for the Bot, second line termination point, 3rd line onwards represent the layout matrix.
Sample Input file: 00
33
0111
0010
0011
1000
Sample Output file:

00
10
11
21
31
32
33
