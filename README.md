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

# Sample output for the given input

Here, the left side of the arrow presents the target gene and the right side of the arrow presents the respective regulatory gene for the target gene.
For example, "Current genes for 1 ---> 6" presents BoolF inferred the regulatory gene 6 for the target gene 1. Additionally, "Actual genes for 1 ---> 3 4 5 6 8" means, in the gold standard network for the target gene 1 there are regulatory genes 3,4,5,6, and 8. <br/>

Current genes for 1 --->  6 <br/>
Actual genes for  1 --->  3 4 5 6 8 <br/>
Current genes for=2 --->  7 <br/>
Actual genes for  2 --->  7 <br/>
Current genes for 3 --->  1 8 9 <br/>
Actual genes for  3 --->  4 8 9 <br/>
Current genes for 4 --->  5 6 8 <br/>
Actual genes for  4 --->  5 6 8 <br/>
Current genes for 5 --->  4 <br/>
Actual genes for  5 --->  4 <br/>
Current genes for 6 --->  3 5 8 <br/>
Actual genes for  6 --->  3 5 8 <br/>
Current genes for 7 --->  5 <br/>
Actual genes for  7 --->  5 <br/>
Current genes for 8 --->  9 <br/>
Actual genes for  8 --->  9 <br/>
Current genes for 9 --->  2 <br/>
Actual genes for  9 --->  2 <br/>
Current genes for 10 --->  7 <br/>
Actual genes for  10 --->  7 <br/>
TP 15  FP 1  TN 69  FN 5 parameters <br/>

F-score for this file = 0.833333 <br/>
Recall/TPR for this file is 0.75 <br/>
FPR for this file is 0.0142857 <br/>
MCC for this file is 0.800014 <br/>
Precision for this file is0.9375 <br/>


