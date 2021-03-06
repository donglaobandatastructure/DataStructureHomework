#include "edge.h"
#include "node.h"
#include <easyx.h>			// Reference graphics library header file
#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <atlstr.h>
#include <Windows.h>


#define WINDOW_HIGHT 800
#define WINDOW_WIDTH 1000
#define RADIU 20
#define TEXT_HIGHT 20
#define TEXT_WIDTH 80
#define ID_WIDTH 20
#define ID_HIGHT 10

void DrawMap(vector<node *> nodeList, vector<edge *> edgeList);
void PreparForDrawing(vector<node *> & nodeList);
void DrawOneNode(node * node_input);
void DrawNodeList(vector<node * > nodeList);
void DrawOneEdge(edge * edge_input);
void DrawEdgeList(vector <edge *> edgeList);
LPCTSTR stringToLPCWSTR(std::string orig);