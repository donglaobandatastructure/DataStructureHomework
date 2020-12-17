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
vector< vector<int> > read_csv(char file_name[], vector<string> & node_name);
void Csv2MyClass(vector<node * > & nodeList, vector<edge * > & edgeList, char csv_file_name[]);