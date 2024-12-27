# BoolF

BoolF is a Boolean function-based method designed to infer Gene Regulatory Networks (GRNs) from time-series gene expression data. It works by exhaustively searching for optimal regulatory genes for a target gene using conjunction and disjunction Boolean functions. This process identifies the set of regulatory genes that best fits the target gene with minimal errors. The method represents genes as binary states—active (ON) or inactive (OFF)—and uses Boolean logic to model the regulatory interactions between genes.

# How to run this method

Setup environment for C++ programming language and clone this repository. Then, edit the Network_input, output, and goldStandardNetwork file path. Finally, run the BoolF.cpp file

# Input network file 

The first value of the first row is the number of genes and the second value of the first row presents the length of the time series. The next lines contain the time-series Boolean data. For example, 
10 20
0 0 1 1 0 1 0 0 1 0 
0 1 1 1 0 1 0 0 1 1 
0 1 1 1 0 1 0 0 0 1 
0 1 1 1 0 1 0 1 0 1 
0 1 1 0 0 1 0 1 0 1 
0 1 1 0 1 1 0 1 0 1 
0 1 1 1 1 1 1 1 0 1 
0 0 1 1 0 1 1 1 0 0 
0 0 1 0 0 1 0 1 1 0 
0 1 0 0 1 1 0 0 1 1 
0 1 1 1 1 1 1 0 0 1 
0 0 1 1 0 0 1 1 0 0 
1 0 1 1 0 1 0 1 1 0 
0 1 1 0 0 1 0 0 1 1 
0 1 1 1 1 1 0 0 0 1 
0 1 1 1 0 0 1 1 0 1 
1 0 1 1 0 1 0 1 0 0 
0 1 1 0 0 1 0 1 1 1 
0 1 0 0 1 1 0 0 0 1 
0 1 1 1 1 1 1 1 0 1 


# Gold standard network file
 
The first column denotes the regulatory genes and the third column denotes the target gene. Here, the second column presents the relationship type between both genes. For example, the gene 8 regulates the gene 7. 
8	1	7
