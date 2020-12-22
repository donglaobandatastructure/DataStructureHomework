#include "head.h"

using namespace std;


int main()
{
	
	//********* ��ʼ������ �� ��ȡ�ڽӾ�����ļ��� *************//
	char csv_file_name[27] = "source code/map_matrix.csv";  //���ĸ��ļ�
	vector<node *> nodeList;  //���� �ڵ� ����
	vector<edge *> edgeList;  //���� egde ����

	//                    end                               //


	//********* ��ȡ�ڽӾ�����Ϣ�������nodeList edgeList ���� ****************//

	Csv2MyClass(nodeList, edgeList, csv_file_name);

	//                    end                               //


	//**************  ��ͼ  ************************//
	int node_position_x[6] = { 0, 3, 6, 12, 23, 9 };
	int node_position_y[6] = { 1,3,9,34,23,5 };
	int radius = 20;

	//init
	initgraph(640, 480);

	//���ñ�����ɫ  ������ɫ
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);

	//��ʼ����
	for (int i = 0; i < nodeList.size(); i++)
	{
		
		if ( i < nodeList.size()-1 )
		{
			line(10 * node_position_x[i], 10 * node_position_y[i], 10 * node_position_x[i + 1], 10 * node_position_y[i + 1]);
		}
		fillcircle(10 * node_position_x[i], 10 * node_position_y[i], radius);
		
	}

	_getch();
	


	//***** ����nodeList edgeList �������Ϣ���õ�Դ���·�������ҳ��� 0 �ڵ㿪ʼ���������ڵ�����·�� ****//
	// cout<<"���������"<<endl;
	// ��Ҫ��ԭ����0 �ڵ� ���û���Ҫ�Ľڵ� �Ի��� Ȼ����ִ�е�Դ���·����
	
	FindShortestPath(nodeList, edgeList); 
    
	//                    end                        //


	//********** ��ӡ������û��� ********************//
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
