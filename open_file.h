#include <iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include "edge.h"
#include "node.h"
#include "my_function.h"
using namespace std;

void print_vector( vector<  vector<string>  > str_array );
vector< vector<int> > str_vector2num_vector(vector<  vector<string>  > str_array);
void read_node_info(char file_name[],vector<node * > & nodeList);
void read_edge_info(char file_name[], vector<edge * > & edgeList, vector<node * > & nodeList);
void Csv2MyClass(vector<node * > & nodeList, vector<edge * > & edgeList, char node_file_name[], char edge_file_name[]);