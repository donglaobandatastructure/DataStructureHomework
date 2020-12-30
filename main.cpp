#include "head.h"

using namespace std;


int main()
{
	
	//********* 初始化变量 和 读取邻接矩阵的文件名 *************//

	char node_file_name[27] = "source code/node_info.csv";  //读哪个文件
	char edge_file_name[27] = "source code/edge_info.csv";  //读哪个文件

	vector<node *> nodeList;  //建立 节点 向量
	vector<edge *> edgeList;  //建立 egde 向量

	//                    end                               //


	//********* 读取地图信息，储存进nodeList edgeList 里面 ****************//

	Csv2MyClass(nodeList, edgeList, node_file_name, edge_file_name);

	//                    end                               //

	
	//**************  画图  ************************//
	DrawMap(nodeList, edgeList);


	//***** 根据nodeList edgeList 里面的信息，用单源最短路径法，找出从 0 节点开始，到其他节点的最短路径 ****//

	int num;
	
	cout << "example: \n 如果起点是南门，则可以输入： South Gate  或者 0 " << endl << endl;;
	cout << "**********************************" << endl << endl;;
	cout << "请输入 起点名称 或者 id" << endl;
	string s;
	getline(cin, s);
	num=FromNameGetId(s,nodeList);

	FindShortestPathFromSpecificPoint(nodeList, edgeList, num);

	//                    end                        //

	PrintOnePathFromSpecificPoint(nodeList, num);
	//                    end                        //

	while(1)
	{ }
	
	return 0;
}
