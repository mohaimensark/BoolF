# BoolF

BoolF is a Boolean function-based method designed to infer Gene Regulatory Networks (GRNs) from time-series gene expression data. It works by exhaustively searching for optimal regulatory genes for a target gene using conjunction and disjunction Boolean functions. This process identifies the set of regulatory genes that best fits the target gene with minimal errors. The method represents genes as binary states—active (ON) or inactive (OFF)—and uses Boolean logic to model the regulatory interactions between genes.

# How to run this method

Setup environment for C++ programming language and clone this repository. Then, edit the Network_input, output, and goldStandardNetwork file path. Finally, run the BoolF.cpp file

# Input network file 

The first value of the first row is the number of genes and the second value of the first row presents the length of the time series. The next lines contain the time-series Boolean data. 
### Example Input
10 20 <br/>
0 0 1 1 0 1 0 0 1 0 <br/>
0 1 1 1 0 1 0 0 1 1 <br/>
0 1 1 1 0 1 0 0 0 1 <br/>
0 1 1 1 0 1 0 1 0 1 <br/>
0 1 1 0 0 1 0 1 0 1 <br/>
0 1 1 0 1 1 0 1 0 1 <br/>
0 1 1 1 1 1 1 1 0 1 <br/>
0 0 1 1 0 1 1 1 0 0 <br/>
0 0 1 0 0 1 0 1 1 0 <br/>
0 1 0 0 1 1 0 0 1 1 <br/>
0 1 1 1 1 1 1 0 0 1 <br/>
0 0 1 1 0 0 1 1 0 0 <br/>
1 0 1 1 0 1 0 1 1 0 <br/>
0 1 1 0 0 1 0 0 1 1 <br/>
0 1 1 1 1 1 0 0 0 1 <br/>
0 1 1 1 0 0 1 1 0 1 <br/>
1 0 1 1 0 1 0 1 0 0 <br/>
0 1 1 0 0 1 0 1 1 1 <br/>
0 1 0 0 1 1 0 0 0 1 <br/>
0 1 1 1 1 1 1 1 0 1 <br/>


# Gold standard network file
 
The first column denotes the regulatory genes and the third column denotes the target gene. Here, the second column presents the relationship type between both genes. For example, in the first row, the gene 8 regulates the gene 7. 
### Example gold standard network
8	-1	7 <br/>
6	-1	9 <br/>
2	1	0 <br/>
3	1	0 <br/>
4	-1	0 <br/>
3	1	2 <br/>
5	-1	0 <br/>
6	-1	1 <br/>
3	-1	4 <br/>
2	-1	5 <br/>
7	1	0 <br/>
4	1	3 <br/>
5	-1	3 <br/>
7	-1	2 <br/>
4	-1	5 <br/>
1	-1	8 <br/>
4	1	6 <br/>
7	-1	3 <br/>
8	-1	2 <br/>
7	1	5 <br/>

