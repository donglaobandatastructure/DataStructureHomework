#include "head.h"

using namespace std;


int main()
{
	
	//********* 初始化变量 和 读取邻接矩阵的文件名 *************//
	char csv_file_name[27] = "source code/map_matrix.csv";  //读哪个文件
	vector<node *> nodeList;  //建立 节点 向量
	vector<edge *> edgeList;  //建立 egde 向量

	//                    end                               //


	//********* 读取邻接矩阵信息，储存进nodeList edgeList 里面 ****************//

	Csv2MyClass(nodeList, edgeList, csv_file_name);

	//                    end                               //


	//**************  画图  ************************//
	int node_position_x[6] = { 0, 3, 6, 12, 23, 9 };
	int node_position_y[6] = { 1,3,9,34,23,5 };
	int radius = 20;

	//init
	initgraph(640, 480);

	//设置背景颜色  线条颜色
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);

	//开始画线
	for (int i = 0; i < nodeList.size(); i++)
	{
		
		if ( i < nodeList.size()-1 )
		{
			line(10 * node_position_x[i], 10 * node_position_y[i], 10 * node_position_x[i + 1], 10 * node_position_y[i + 1]);
		}
		fillcircle(10 * node_position_x[i], 10 * node_position_y[i], radius);
		
	}

	_getch();
	


	//***** 根据nodeList edgeList 里面的信息，用单源最短路径法，找出从 0 节点开始，到其他节点的最短路径 ****//
	// cout<<"请输入起点"<<endl;
	// 需要把原来的0 节点 和用户想要的节点 对换。 然后再执行单源最短路径法
	
	FindShortestPath(nodeList, edgeList); 
    
	//                    end                        //


	//********** 打印结果给用户看 ********************//
	PrintOnePath(nodeList);
	//              end                     //


	system("pause");
	return 0;
}

/*
initgraph(640, 480);	// Create a graphics window with a size of 640x480 pixels
circle(200, 200, 100);	// Draw a circle with center (200, 200) and radius 100
_getch();				// Press any key to continue
closegraph();

*/
