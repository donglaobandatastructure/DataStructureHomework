#include"my_function.h"



void PrintAllPath(vector<node *> nodeList)
{
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (nodeList[i]->dis != 999999)
		{
			cout << "����㵽�ڵ�" << nodeList[i]->id << "����̾�����" << nodeList[i]->dis << endl;
			cout << "���·��Ϊ��" << endl;
			printPath(nodeList[0], nodeList[i]);
			cout << endl;
		}
		else
		{
			//cout << "����㵽�ڵ�" << nodeList[i]->id << "����̾�����" << nodeList[i]->dis << endl;
			cout << "û��·" << endl;
		}
	}

}


void PrintOnePath( vector<node *> nodeList)
{
	int i;
	cout << "��Ҫ֪�����ĸ�������·����" << endl;
	cin >> i;
	if (nodeList[i]->dis != 999999)
	{
		cout << "����㵽�ڵ�" << nodeList[i]->id << "����̾�����" << nodeList[i]->dis << endl;
		cout << "���·��Ϊ��" << endl;
		printPath(nodeList[0], nodeList[i]);
		cout << endl;
	}
	else
	{
		cout << "����㵽�ڵ�" << nodeList[i]->id << "����̾�����" << nodeList[i]->dis << endl;
		cout << "û��·" << endl;
	}
}

void PrintOnePathFromSpecificPoint(vector<node *> nodeList,int num)
{
	int i;
	cout << "��Ҫ֪�����ĸ�������·����������Ŀ�ĵ�����" << endl;
	string s;
	getline(cin, s);
	i = FromNameGetId(s, nodeList);
	
	if (nodeList[i]->dis != 999999)
	{
		cout << "��"<<nodeList[num]->node_name<<"��" << nodeList[i]->node_name << "����̾�����" << nodeList[i]->dis << endl;
		cout << "���·��Ϊ��" << endl;
		printPath(nodeList[num], nodeList[i]);
		cout << endl;
	}
	else
	{
		cout << "����㵽�ڵ�" << nodeList[i]->id << "����̾�����" << nodeList[i]->dis << endl;
		cout << "û��·" << endl;
	}
}


void FindShortestPath(vector<node * > & nodeList, vector<edge * > & edgeList)
{
	vector<node *> S;  //�ڵ�S ����
	nodeList[0]->dis = 0;  //����һ���ڵ�� dis ��ֵ
	S.push_back(nodeList[0]);  //��� S ����
	vector<node *> Q;  // �ڵ�Q ����

	for (int i = 0; i < nodeList.size(); i++)
		Q.push_back(nodeList[i]);   // �൱�ڸ���  Q=nodeList

	while (!Q.empty())  //ֻҪQ������Ԫ�أ���һֱִ��
	{
		auto u = extract_min(Q);
		if (u != NULL)
		{
			for (vector<node *>::iterator it = Q.begin(); it != Q.end(); it++) {
				//��������� ��С��dis ??
				if (*it == u) {
					Q.erase(it); //
					break;
				}
			}
			S.push_back(u);
			for (auto v : u->adjNodes)
			{
				auto e = foundEdge(u, v, edgeList);  // ����һ�������ҵ��������ڵ��һ��·��
				relax(u, v, e->weight);			//������һ�ڵ�
			}
		}
		else
			break;

	}

}


void FindShortestPathFromSpecificPoint(vector<node * > & nodeList, vector<edge * > & edgeList,int num)
{
	vector<node *> S;  //�ڵ�S ����
	nodeList[num]->dis = 0;  //�������ڵ�� dis ��ֵ
	S.push_back(nodeList[num]);  //��� S ����
	vector<node *> Q;  // �ڵ�Q ����

	for (int i = 0; i < nodeList.size(); i++)
		Q.push_back(nodeList[i]);   // �൱�ڸ���  Q=nodeList

	while (!Q.empty())  //ֻҪQ������Ԫ�أ���һֱִ��
	{
		auto u = extract_min(Q);
		if (u != NULL)
		{
			for (vector<node *>::iterator it = Q.begin(); it != Q.end(); it++) {
				//��������� ��С��dis ??
				if (*it == u) {
					Q.erase(it); //
					break;
				}
			}
			S.push_back(u);
			for (auto v : u->adjNodes)
			{
				auto e = foundEdge(u, v, edgeList);  // ����һ�������ҵ��������ڵ��һ��·��
				relax(u, v, e->weight);			//������һ�ڵ�
			}
		}
		else
			break;

	}

}




node * foundNode(string node_name, vector<node * > nodeList)
{
	node * x = NULL;
	for (int i = 0; i < nodeList.size(); i++)
	{
		if (node_name == nodeList[i]->node_name)
		{
			x = nodeList[i]; break;
		}
	}

	return x;
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

node * extract_min(vector<node *> Q)  //�� Q�����dis ��Сֵ�ҵ������� node ʵ��
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
		cout << node1->node_name;
	else
	{
		if (node2->prevNode == NULL)
			cout << "no path from" << node1->node_name << "to" << node2->node_name << "exist" << endl;
		else
		{
			printPath(node1, node2->prevNode);
			cout << "->"<<node2->node_name;
			setlinecolor(BLUE);
			setlinestyle(PS_SOLID, 3);
			line(node2->draw_x, node2->draw_y, node2->prevNode->draw_x, node2->prevNode->draw_y);
			DrawOneNode(node2);
			DrawOneNode(node2->prevNode);
			Sleep(2000);
			
		}

	}
}

int FromNameGetId(string name,vector <node *> nodeList)
{
	node * x;
	x = foundNode(name, nodeList);

	while (x == NULL)
	{
		cout << "����Ľڵ����Ʋ���ȷ" << endl;
		cout << "����������" << endl;
		getline(cin, name);
		x = foundNode(name, nodeList);
	}

	int num;
	num = x->id;

	return num;
}