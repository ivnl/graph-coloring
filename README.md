# graph-coloring

  Graph coloring problem:  given a undirected graph, G = <N, E>,  
	the graph coloring problem is to find the minumum number of colors to color all nodes in N, 
	such that two adjacent nodes, ni, nj, can not be colored with the same color.  
	
## Notes

I.  Input [argv[1]: an undirected graph, represented by a list of edges, <ni, nj>, 
   (a bidirectional edge from ni to nj and from nj to ni thw cost is c.)  
   The name of the input file should be given in argv[1].

The first text line is the number of nodes, N, in G, follows by a list of bidirectional edges, <ni, nj>
	Example:
		5	// there are 5 nodes in the graph 
		1  5  // an edge <1, 5> and <5, 1>
    2  3  // an edge <2, 3> and <3, 2>
    1  2  // an edge <1, 2> and <2, 1>
		3  5  // an edge <3, 5> and < 5, 3>
          	  	
II. Output(argv[2]):
    - Print input pairs
		- Print the initial adjacencyMatrix of the graph.
		- Pring the number of colors used to color.
		- Print the final adjacentcyMatrix with the assign colors in the diagonal of the matrix. 
