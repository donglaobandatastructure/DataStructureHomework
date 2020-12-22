#include"my_function.h"



void PrintAllPath(vector<node *> nodeList)
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (nodeList[i]->dis != 999999)
		{
			cout << "从起点到节点" << nodeList[i]->id << "的最短距离是" << nodeList[i]->dis << endl;
			cout << "最短路径为：" << endl;
			printPath(nodeList[0], nodeList[i]);
			cout << endl;
		}
		else
		{
			//cout << "从起点到节点" << nodeList[i]->id << "的最短距离是" << nodeList[i]->dis << endl;
			cout << "没有路" << endl;
		}
	}

}


void PrintOnePath( vector<node *> nodeList)
{
	int i;
	cout << "想要知道到哪个点的最短路径？" << endl;
	cin >> i;
	if (nodeList[i]->dis != 999999)
	{
		cout << "从起点到节点" << nodeList[i]->id << "的最短距离是" << nodeList[i]->dis << endl;
		cout << "最短路径为：" << endl;
		printPath(nodeList[0], nodeList[i]);
		cout << endl;
	}
	else
	{
		cout << "从起点到节点" << nodeList[i]->id << "的最短距离是" << nodeList[i]->dis << endl;
		cout << "没有路" << endl;
	}
}

void FindShortestPath(vector<node * > & nodeList, vector<edge * > & edgeList)
{
	vector<node *> S;  //节点S 向量
	nodeList[0]->dis = 0;  //给第一个节点的 dis 赋值
	S.push_back(nodeList[0]);  //存进 S 向量
	vector<node *> Q;  // 节点Q 向量

	for (int i = 0; i < nodeList.size(); i++)
		Q.push_back(nodeList[i]);   // 相当于复制  Q=nodeList

	while (!Q.empty())  //只要Q里面有元素，就一直执行
	{
		auto u = extract_min(Q);
		if (u != NULL)
		{
			for (vector<node *>::iterator it = Q.begin(); it != Q.end(); it++) {
				//如果遍历到 最小的dis ??
				if (*it == u) {
					Q.erase(it); //
					break;
				}
			}
			S.push_back(u);
			for (auto v : u->adjNodes)
			{
				auto e = foundEdge(u, v, edgeList);  // 到这一步，就找到了两个节点和一条路径
				relax(u, v, e->weight);			//储存上一节点
			}
		}
		else
			break;

	}

}

edge * foundEdge(node * n1, node * n2, vector<edge *> edgeList)
{
	edge * x = NULL;
	for (int i = 0; i < edgeList.size(); i++)
	{
		node * node1 = edgeList[i]->Node1;
		node * node2 = edgeList[i]->Node2;
		if (n1 == node1&&n2 == node2)
		{
			x = edgeList[i];
		}
	}
	return x;
}

void relax(node * u, node * v, int w)
{
	if ((v->dis)> (u->dis + w))
	{
		v->dis = u->dis + w;
		v->prevNode = u;
	}
}

node * extract_min(vector<node *> Q)  //把 Q里面的dis 最小值找到，返回 node 实例
{
	int tmp = 999999;
	node * x = NULL;
	for (int i = 0; i < Q.size(); i++)
	{
		if (Q[i]->dis < tmp)
		{
			tmp = Q[i]->dis;
			x = Q[i];
		}
	}
	
	return x;
}

void printPath(node * node1, node* node2)
{
	if (node1 == node2)
		cout << node1->id << "  ";
	else
	{
		if (node2->prevNode == NULL)
			cout << "no path from" << node1->id << "to" << node2->id << "exist" << endl;
		else
		{
			printPath(node1, node2->prevNode);
			cout << node2->id << "  ";
		}

	}
}