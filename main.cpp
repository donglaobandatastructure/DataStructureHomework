#include "head.h"

using namespace std;


int main()
{
	
	//********* ��ʼ������ �� ��ȡ�ڽӾ�����ļ��� *************//

	char node_file_name[27] = "source code/node_info.csv";  //���ĸ��ļ�
	char edge_file_name[27] = "source code/edge_info.csv";  //���ĸ��ļ�

	vector<node *> nodeList;  //���� �ڵ� ����
	vector<edge *> edgeList;  //���� egde ����

	//                    end                               //


	//********* ��ȡ��ͼ��Ϣ�������nodeList edgeList ���� ****************//

	Csv2MyClass(nodeList, edgeList, node_file_name, edge_file_name);

	//                    end                               //

	
	//**************  ��ͼ  ************************//
	DrawMap(nodeList, edgeList);


	//***** ����nodeList edgeList �������Ϣ���õ�Դ���·�������ҳ��� 0 �ڵ㿪ʼ���������ڵ�����·�� ****//

	int num;
	cout << "����������" << endl;
	cin >> num;
	//ѡ�����

	FindShortestPathFromSpecificPoint(nodeList, edgeList, num);

	//                    end                        //

	PrintOnePathFromSpecificPoint(nodeList, num);
    //                    end                        //

	system("pause");
	return 0;
}
