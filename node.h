#pragma once
#include<vector>
using namespace std;

class edge;

class node
{
public:
	int id;
	int dis;
	std::string node_name;
	int position_x;
	int position_y;
	int draw_x;
	int draw_y;

	node * prevNode;
	vector<node *> adjNodes;

	static int countId;

	node(string name)
	{
		node_name = name;
		id = countId++;
		dis = 999999;
		prevNode = NULL;

	}


};



