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
