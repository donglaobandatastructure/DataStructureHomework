
#include "node.h"
#include "edge.h"
#include<iostream>
using namespace std;


void relax(node * u, node * v, int w);
edge * foundEdge(node * n1, node * n2, vector<edge *> edgeList);
node * extract_min(vector<node *> Q);
void printPath(node * node1, node* node2);
void FindShortestPath(vector<node * > & nodeList, vector<edge * > & edgeList);
void PrintOnePath(vector<node *> nodeList);
void PrintAllPath(vector<node *> nodeList);
//static int time;