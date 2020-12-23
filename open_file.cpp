#include "open_file.h"
#include <math.h>


void Csv2MyClass(vector<node * > & nodeList, vector<edge * > & edgeList, char node_file_name[], char edge_file_name[])
{
	read_node_info( node_file_name , nodeList );
	read_edge_info(edge_file_name, edgeList, nodeList);

}

void read_node_info(char file_name[], vector<node * > & nodeList)
{
	ifstream fp(file_name, ios::in);
	string line_str; //���ÿһ�е�
	vector< vector<string> >str_array_hang; //����ַ������������
	vector< vector<int>  > map_matrix;  //����ڽӾ���

	while (getline(fp, line_str)) //ÿ�ζ�һ��
	{
		//cout<<line_str<<endl;  //�����һ��

		stringstream ss(line_str); //ת��Ϊ stringstream������
		string str;  //�������涺��֮����ַ���
		vector<string> str_array_lie;

		while (getline(ss, str, ','))
		{
			str_array_lie.push_back(str); //�Ѷ���֮��� �ַ� �洢��һ����������
		}
		str_array_hang.push_back(str_array_lie);

	}

	//�洢�ڵ����� x y 
	for (int i = 1; i < str_array_hang.size(); i++)
	{
		node * z = new node(str_array_hang[i][0]);

		int num;
		stringstream ss_x(str_array_hang[i][1]);
		ss_x >> num;
		z->position_x = num;

		stringstream ss_y(str_array_hang[i][2]);
		ss_y >> num;
		z->position_y = num;

		z->draw_x = z->position_x;
		z->draw_y = z->position_y;

		nodeList.push_back(z);
	}


     /* 
	//��ʾ�ڵ����� x y �Լ����ӵĽڵ�
	for (int i = 0; i < nodeList.size(); i++)
	{
		cout << nodeList[i]->node_name <<"x:"<< nodeList[i]->position_x<<"y:"<< nodeList[i]->position_y  << endl;
	}
	*/

}


void read_edge_info(char file_name[], vector<edge * > & edgeList, vector<node * > & nodeList)
{
	ifstream fp(file_name, ios::in);
	string line_str; //���ÿһ�е�
	vector< vector<string> >str_array_hang; //����ַ������������
	vector< vector<int>  > map_matrix;  //����ڽӾ���

	while (getline(fp, line_str)) //ÿ�ζ�һ��
	{
		//cout << line_str << endl;  //�����һ��

		stringstream ss(line_str); //ת��Ϊ stringstream������
		string str;  //�������涺��֮����ַ���
		vector<string> str_array_lie;

		while (getline(ss, str, ','))
		{
			str_array_lie.push_back(str); //�Ѷ���֮��� �ַ� �洢��һ����������
		}
		str_array_hang.push_back(str_array_lie);

	}
		
	for (int i = 2; i < str_array_hang.size();i++)  
	{
		string adjname1 = str_array_hang[i][0];
		string adjname2 = str_array_hang[i][1];
		node * node1;
		node * node2;
		node1 = foundNode(adjname1, nodeList);
		node2 = foundNode(adjname2, nodeList);
		if (node1 == NULL || node2 == NULL)
		{
			cout << "û���ҵ���Ӧ�Ľڵ����֣�����ڵ������Ƿ���ȷ" << endl;
			system("pause");
		}

		//�������ڵ�����
		int distance = sqrt(pow((node1->position_x - node2->position_x), 2) + pow(node1->position_y - node2->position_y, 2));
		//���� egde
		edge * edge_1 = new edge(distance, node1, node2);
		edgeList.push_back(edge_1);

		edge * edge_2 = new edge(distance, node2, node1);
		edgeList.push_back(edge_2);

	}
    
	for (int i = 0; i < nodeList.size(); i++)
	{
		for (int j = 0; j < nodeList.size(); j++)
		{
			edge * x = foundEdge(nodeList[i], nodeList[j], edgeList);
			if (x != NULL)
			{
				nodeList[i]->adjNodes.push_back(nodeList[j]);  //�������ӵĽڵ㴢�浽 �ýڵ����µ� adjNodes ������
			}
		}
	}


}

/*  
void Csv2MyClass(vector<node * > & nodeList, vector<edge * > & edgeList,char csv_file_name[])
{
	vector< vector<int>  > map_matrix; //���ڴ洢�ڽӾ���
	vector< string > node_name;  //���ڴ�������ڵ������
	
	map_matrix = read_csv(csv_file_name, node_name);  //��ȡ�ļ������ڽӾ���Ž�map_matrix��Ѹ����ص�����ַŽ�node_name��

	//***** ��¼map��size *****
	int size[2];
	int name_size;
	size[0] = map_matrix.size();  //����
	size[1] = map_matrix[0].size();  //����
	name_size = node_name.size();   //�ж��ٸ� �ڵ�����
	//******  end  ************

	//��̬�� �ڵ����� ������ �ڵ�ʵ��
	for (int i = 0; i < name_size; i++)
	{
		node * z = new node();
		nodeList.push_back(z);
	}

	//��̬�� ��Ե����edgeList���� ���� edge ʵ��
	for (int row = 0; row < size[0]; row++)
	{
		for (int col = 0; col < size[1]; col++)
		{
			if (row != col)  //�Լ� �� �Լ� ��û�� �ߣ�edge��
			{
				if (map_matrix[row][col] < 999999) //˵����·��row->col
				{
					edge * edge_i = new edge(map_matrix[row][col], nodeList[row], nodeList[col]);
					edgeList.push_back(edge_i);

				}
			}

		}
	}

	for (int i = 0; i < nodeList.size(); i++)
	{
		for (int j = 0; j < nodeList.size(); j++)
		{
			edge * x = foundEdge(nodeList[i], nodeList[j], edgeList);
			if (x != NULL)
			{
				nodeList[i]->adjNodes.push_back(nodeList[j]);  //�������ӵĽڵ㴢�浽 �ýڵ����µ� adjNodes ������
			}
		}
	}

}



vector< vector<int> > read_csv(char file_name[], vector<string> & node_name)
{
	ifstream fp(file_name,ios::in);
	string line_str; //���ÿһ�е�
	vector< vector<string> >str_array_hang; //����ַ������������
	vector< vector<int>  > map_matrix;  //����ڽӾ���

	while( getline(fp,line_str) ) //ÿ�ζ�һ��
	{
		//cout<<line_str<<endl;  //�����һ��

		stringstream ss(line_str); //ת��Ϊ stringstream������
		string str;  //�������涺��֮����ַ���
		vector<string> str_array_lie;

		while(getline(ss,str,','))
		{
			str_array_lie.push_back(str); //�Ѷ���֮��� �ַ� �洢��һ����������
		}
		str_array_hang.push_back(str_array_lie);

	}

	//print_vector(str_array_hang);
	map_matrix=str_vector2num_vector(str_array_hang);

#if IS_PRINT_READ_RESULT
	printf("\n�ڵ������Ϊ��\n");
#endif

	for (int col = 1; col < str_array_hang[0].size(); col++)
	{
		node_name.push_back(str_array_hang[0][col]);
#if IS_PRINT_READ_RESULT
		cout << str_array_hang[0][col] << " ";
#endif
	}
  

	return map_matrix;
}

*/


vector< vector<int> > str_vector2num_vector(vector<  vector<string>  > str_array)
{
	//***** ��¼�������� ���� ��ά�� *****************
	vector< vector<int> > result;
	int size[2];
	if ( (size[0]=str_array.size()) == 0  ) //����
	{
		cout<<"this vector has no element"<<endl;
	}
	size[1]=str_array[0].size();  //����
	//***********  end  *************************

	//****************** ��ʼ�������洢��result **************
	for (int row = 1;row < size[0];row++)  //������
	{
		vector<int> row_array; //������һ�е�����
		for (int col = 1;col < size[1];col++)  //������
		{
			int num;
			stringstream ss(str_array[row][col]);
			ss>>num;
			row_array.push_back(num);  //�ƽ�ȥһ����
		}
		result.push_back(row_array);  //�洢һ������
	}
	//******************  end  ***************************

	//********** �����Ǵ�ӡresult�����Ƿ�������  ************
	int size_result[2];
	if ( (size_result[0]=result.size()) == 0  ) //����
	{
		cout<<"this vector has no element"<<endl;
	}
	size_result[1]=result[0].size();  //����
#if IS_PRINT_READ_RESULT
	printf("�ڽӾ���Ϊ��\n");
	for (int row = 1; row < size_result[0]; row++)  //������
	{
		for (int col = 1; col < size_result[1]; col++)  //������
		{
			cout << result[row][col] << " ";
		}
		cout << endl;
	}
#endif

	

	//********** end  *****************************

	return result;

}

void print_vector( vector<  vector<string>  > str_array )
{
	int size[2];
	if ( (size[0]=str_array.size()) == 0  )
	{
		cout<<"this vector has no element"<<endl;
	}
	size[1]=str_array[0].size();

	printf("this vector's size = %d,%d \n \n",size[0],size[1]);

	for (int row = 0;row < size[0];row++)  //������
	{
		for (int col = 0;col < size[1];col++)  //������
		{
			cout<<str_array[row][col]<<" ";
		}
		cout<<endl;
	}

}