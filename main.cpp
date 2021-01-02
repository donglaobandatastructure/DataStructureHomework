#include "head.h"

using namespace std;


int main()
{
	
	//********* 初始化变量 和 读取邻接矩阵的文件名 *************//

	char node_file_name[50] = "DataStructureHomework/node_info.csv";  //读哪个文件
	char edge_file_name[50] = "DataStructureHomework/edge_info.csv";  //读哪个文件

	vector<node *> nodeList;  //建立 节点 向量
	vector<edge *> edgeList;  //建立 egde 向量

	//初始一个绘图窗口
	initgraph(WINDOW_WIDTH, WINDOW_HIGHT, EW_SHOWCONSOLE);
	

	//大循环 每次循环都询问用户 起点 和 终点。 遇到 -1时 跳出
	while(1)
	{ 

		//********* 读取地图信息，储存进nodeList edgeList 里面 ****************//

		Csv2MyClass(nodeList, edgeList, node_file_name, edge_file_name);

		//                    end                               //

		//坐标变换
		PreparForDrawing(nodeList);


		//**************  画图  ************************//
		DrawMap(nodeList, edgeList);


		//***** 根据nodeList edgeList 里面的信息，用单源最短路径法，找出从 0 节点开始，到其他节点的最短路径 ****//
		cout << "***********  数据结构大作业 最短路径  ***********************" << endl << endl;
		cout << "example: \n请参见绘图窗口\n如果起点是南门，则可以输入： South Gate  或者 1 " << endl << endl;
		cout << "请输入 起点名称 或者 id" << endl << endl;

		int num;
		string s;
		getline(cin, s);
		num=FromNameGetId(s,nodeList);

		FindShortestPathFromSpecificPoint(nodeList, edgeList, num);

		//                    end                        //

		PrintOnePathFromSpecificPoint(nodeList, num);
		//                    end                        //

		cout << "**********************************" << endl << endl;
		cout << "想要继续吗？ 请输入 yes 或者 no" << endl << endl;

		while(1)
		{
			
			getline(cin, s);
			string yes = "yes";
			string no = "no";

			if (s == no)
				return 0;
			else if (s == yes)
			{
				Reinitialize(nodeList, edgeList);
				clearcliprgn();
				break;
			}
			else
				cout << "输入错误，请重新输入" << endl;
		}
		
	}
		
	
	return 0;
}
