# 1-graph

### Basic terms

**Adjoint graph** G= (V,A) directed graph H=(U,V) is 1-graph, that vertexes represent links from H and that have link from x to y, if in H end-vertex link x is first-vertex link y. 

**Directed linear graph is adjoint graph G of 1-graph H.** 

**1-graph** G=(V,A) is adjoint graph if and only when property is true for each pair x,y ∈ V:
N+(x) ∩ N+(y) ≠ Ø ⇒ N+(x) = N+(y)
when N+(x) is a set of successors x. :nerd_face:

For directed graph: adjoint graph is linear if and only when it doesn't have as subgraph any of the shown below structures:

![Images of stuctures](/images/structures.png)

### What does this alghoritm?

- reads from txt-file directed graph as list of successors in given format: 
```
*count of all vertexes*
*number of vertex*  *successors separated tabbing*
```

Example: 
```
10
1	1	2	0
2	1	2	0
3	7	4	0
4	5	10	0
5	8	6	0
6	0
7	9	0
8	9	0
9	10	5	0
10	1	2	0
```
- checks that readed graph is adjoint
- if graph is adjoint checks if it is linear
- if graph is adjoint transforms it to original graph
- saves the result to txt file
