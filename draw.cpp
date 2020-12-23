#include "draw.h"


void DrawMap(vector<node *> nodeList, vector<edge *> edgeList)
{
	//坐标变换
	PreparForDrawing( nodeList);

	//init
	initgraph(WINDOW_HIGHT, WINDOW_WIDTH, EW_SHOWCONSOLE);
	//设置背景颜色  线条颜色
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	settextcolor(BLACK);

	//画所有edge
	DrawEdgeList(edgeList);

	//画所有节点
	DrawNodeList(nodeList);
}

void PreparForDrawing(vector<node *> & nodeList)
{
	int up=nodeList[0]->position_y, bottom= nodeList[0]->position_y, left= nodeList[0]->position_x, right= nodeList[0]->position_x;

	for (auto node_iter : nodeList)
	{
		if (node_iter->position_x < left)  //如果比左边界小
			left = node_iter->position_x;
		if (node_iter->position_x > right)  //如果比右边界大
			right = node_iter->position_x;
		if (node_iter->position_y < bottom) //如果比下界还小
			bottom = node_iter->position_y;
		if (node_iter->position_y > up ) //如果比下界还小
			up = node_iter->position_y;
	}

	for (auto node_iter : nodeList)
	{
		node_iter->draw_x = node_iter->draw_x - left+RADIU;
		node_iter->draw_y = node_iter->draw_y - bottom+RADIU;
	}

	up = up - bottom + 2*RADIU;
	right = right - left + 2*RADIU;
	float hight_rate, width_rate;
	hight_rate = WINDOW_HIGHT / float( up);
	width_rate = WINDOW_WIDTH / float(right);

	for (auto node_iter : nodeList)
	{
		node_iter->draw_x = int( node_iter->draw_x * width_rate );
		node_iter->draw_y = int( node_iter->draw_y * hight_rate );

		//node_iter->draw_x = WINDOW_WIDTH- node_iter->draw_x + RADIU;
		node_iter->draw_y = WINDOW_HIGHT- node_iter->draw_y ;

	}


}

void DrawEdgeList(vector <edge *> edgeList)
{
	for (auto edge_iter : edgeList)
	{
		DrawOneEdge(edge_iter);
	}

}

void DrawOneEdge(edge * edge_input)
{
	line(edge_input->Node1->draw_x, edge_input->Node1->draw_y, edge_input->Node2->draw_x, edge_input->Node2->draw_y);

	
	CString str;
	str.Format(_T("%d"), edge_input->weight);
	outtextxy((edge_input->Node1->draw_x + edge_input->Node2->draw_x) / 2, (edge_input->Node1->draw_y + edge_input->Node2->draw_y) / 2, str);

}

void DrawOneNode(node * node_input)
{
	fillcircle(node_input->draw_x, node_input->draw_y, RADIU);
	RECT r = { node_input->draw_x - TEXT_WIDTH,node_input->draw_y - TEXT_HIGHT, node_input->draw_x + TEXT_WIDTH ,node_input->draw_y + TEXT_HIGHT };
	
	LPCTSTR str_x = stringToLPCWSTR(node_input->node_name);
	drawtext(str_x, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
}

void DrawNodeList(vector<node * > nodeList)
{
	for (auto node_iter : nodeList)
	{
		DrawOneNode(node_iter);
	}
}

LPCTSTR stringToLPCWSTR(std::string orig)
{
	 size_t origsize = orig.length() + 1;
	     const size_t newsize = 100;
	     size_t convertedChars = 0;
	 wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
	
		return wcstring;
}