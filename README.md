# graph-coloring

  Graph coloring problem:  given a undirected graph, G = (N, E)
	the graph coloring problem is to find the minumum number of colors to color all nodes in N, 
	such that two adjacent nodes, ni, nj, can not be colored with the same color.  
	
## Notes

   Input [argv[1]: an undirected graph, represented by a list of edges, <ni, nj>, 
   (a bidirectional edge from ni to nj and from nj to ni thw cost is c.)  
   The name of the input file should be given in argv[1].

The first text line is the number of nodes, N, in G, follows by a list of bidirectional edges, <ni, nj>

There are three data input files included in the repository folder

The output file will be generated with the corresponding colors inside the diagonal line (of the adjacency matrix)

## Algorithm Steps

step 0: numNode <-- get from input file
	  - dynamically allocate adjacencyMatrix // initiallize to 0
	  - load adjacencyMatrix from the input pairs
 	  - print adjacencyMatrix
	  - newColor <-- 0
	 
// get new new color (using 1, 2, 3, ... as the color scheme)
step 1: newColor ++
	
//use the newColor to color as many un-colored nodes as possible 
Step 2: uncolorNode <-- get an uncolor node // check adjacentMatrix [i][i] == 0 
	   if newNode does not have any adjacent node that are already colored with the newColor // check adjancyMatrix
	   adjacentMatrix[uncolorNode][uncolorNode] <-- newColor

Step 3: repeat step 2 until all uncolored nodes are checked.

Step 4: print adjacencyMatrix 

Step 5: repeat steps 1 to 3 until all nodes are colored.

Step 6: print adjacencyMatrix 
