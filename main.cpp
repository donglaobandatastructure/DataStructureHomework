#include "head.h"

using namespace std;


int main()
{
	//********* ��ʼ������ �� ��ȡ�ڽӾ�����ļ��� *************//

	//github try


	//char csv_file_name[27] = "source code/map_matrix.csv";  //���ĸ��ļ�
	//char csv_file_name[27] = "code/map_matrix.csv";  //���ĸ��ļ�
	char csv_file_name[27] = "map_matrix_test.csv";  //���ĸ��ļ�
	vector<node *> nodeList;  //���� �ڵ� ����
	vector<edge *> edgeList;  //���� egde ����

	//                    end                               //


	//********* ��ȡ�ڽӾ�����Ϣ�������nodeList edgeList ���� ****************//

	Csv2MyClass(nodeList, edgeList, csv_file_name); 

	//                    end                               //


	//***** ����nodeList edgeList �������Ϣ���õ�Դ���·�������ҳ��� 0 �ڵ㿪ʼ���������ڵ�����·�� ****//
	// cout<<"���������"<<endl;
	// ��Ҫ��ԭ����0 �ڵ� ���û���Ҫ�Ľڵ� �Ի��� Ȼ����ִ�е�Դ���·����
	
	FindShortestPath(nodeList, edgeList); 
    
	//                    end                        //


	//********** ��ӡ������û��� ********************//
	PrintOnePath(nodeList);
	//              end                     //

	int num;
	cout << "����������" << endl;
	cin >> num;
	//ѡ�����

	FindShortestPathFromSpecificPoint(nodeList, edgeList, num);

	//                    end                        //

	PrintOnePathFromSpecificPoint(nodeList, num);
    //                    end                        //

	getchar();
	return 0;
}

/*
initgraph(640, 480);	// Create a graphics window with a size of 640x480 pixels
circle(200, 200, 100);	// Draw a circle with center (200, 200) and radius 100
_getch();				// Press any key to continue
closegraph();

*/
