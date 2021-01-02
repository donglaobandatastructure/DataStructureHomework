#include "head.h"

using namespace std;


int main()
{
	
	//********* ��ʼ������ �� ��ȡ�ڽӾ�����ļ��� *************//

	char node_file_name[50] = "DataStructureHomework/node_info.csv";  //���ĸ��ļ�
	char edge_file_name[50] = "DataStructureHomework/edge_info.csv";  //���ĸ��ļ�

	vector<node *> nodeList;  //���� �ڵ� ����
	vector<edge *> edgeList;  //���� egde ����

	//��ʼһ����ͼ����
	initgraph(WINDOW_WIDTH, WINDOW_HIGHT, EW_SHOWCONSOLE);
	

	//��ѭ�� ÿ��ѭ����ѯ���û� ��� �� �յ㡣 ���� -1ʱ ����
	while(1)
	{ 

		//********* ��ȡ��ͼ��Ϣ�������nodeList edgeList ���� ****************//

		Csv2MyClass(nodeList, edgeList, node_file_name, edge_file_name);

		//                    end                               //

		//����任
		PreparForDrawing(nodeList);


		//**************  ��ͼ  ************************//
		DrawMap(nodeList, edgeList);


		//***** ����nodeList edgeList �������Ϣ���õ�Դ���·�������ҳ��� 0 �ڵ㿪ʼ���������ڵ�����·�� ****//
		cout << "***********  ���ݽṹ����ҵ ���·��  ***********************" << endl << endl;
		cout << "example: \n��μ���ͼ����\n�����������ţ���������룺 South Gate  ���� 1 " << endl << endl;
		cout << "������ ������� ���� id" << endl << endl;

		int num;
		string s;
		getline(cin, s);
		num=FromNameGetId(s,nodeList);

		FindShortestPathFromSpecificPoint(nodeList, edgeList, num);

		//                    end                        //

		PrintOnePathFromSpecificPoint(nodeList, num);
		//                    end                        //

		cout << "**********************************" << endl << endl;
		cout << "��Ҫ������ ������ yes ���� no" << endl << endl;

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
				cout << "�����������������" << endl;
		}
		
	}
		
	
	return 0;
}
