# Graph Exercise
Given the following undirected graph, answer the following questions:

![](graph.png)

When choosing which node to explore next (e.g., depth-first traversal, breadth-first traversal, use the nodes in numeric order).


1. Starting at "Node 9", perform a depth-first traversal.  List the nodes separated by a comma with no spaces.

2. Starting at "Node 1", perform a depth-first traversal.  List the nodes separated by a comma with no spaces.

3. Starting at "Node 9", perform a breadth-first traversal.  List the nodes separated by a comma with no spaces.

4. Starting at "Node 1", perform a breadth-first traversal.  List the nodes separated by a comma with no spaces.

5. Write an adjacency matrix to represent the graph.  Use 0 if there is no path. Should have 10 rows and columns.  Use the following comma-separated format:
   ```
   0,1,0
   1,0,1
   0,1,0
   ```
   Note: it may help to first write this down in a matrix/spreadsheet

6. Using Prim's algorithm (as presented in class and CLRS), find the minimum spanning tree.  List the edges in tbe order that they are explored.  Start at node 0. Your answer should look like (note - these are not the correct start values):
   ```
   0-8
   0-7
   ...
   ```

7. Starting at node 3, and ending at node 8, what is the shortest path.  list each
node traversed in order separated by commas without spaces.


On the final exam, be prepared to answer these questions, demonstrating proof that you have followed the appropriate algorithm.
