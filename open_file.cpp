#include "open_file.h"
#define IS_PRINT_READ_RESULT 0

void Csv2MyClass(vector<node * > & nodeList, vector<edge * > & edgeList,char csv_file_name[])
{
	vector< vector<int>  > map_matrix; //用于存储邻接矩阵
	vector< string > node_name;  //用于储存各个节点的名称
	
	map_matrix = read_csv(csv_file_name, node_name);  //读取文件，把邻接矩阵放进map_matrix里，把各个地点的名字放进node_name里

	//***** 记录map的size *****
	int size[2];
	int name_size;
	size[0] = map_matrix.size();  //行数
	size[1] = map_matrix[0].size();  //列数
	name_size = node_name.size();   //有多少个 节点名字
	//******  end  ************

	//动态向 节点向量 里增加 节点实例
	for (int i = 0; i < name_size; i++)
	{
		node * z = new node();
		nodeList.push_back(z);
	}

	//动态向 边缘向量edgeList里面 增加 edge 实例
	for (int row = 0; row < size[0]; row++)
	{
		for (int col = 0; col < size[1]; col++)
		{
			if (row != col)  //自己 到 自己 就没有 边（edge）
			{
				if (map_matrix[row][col] < 999999) //说明有路，row->col
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
				nodeList[i]->adjNodes.push_back(nodeList[j]);  //把有连接的节点储存到 该节点旗下的 adjNodes 向量里
			}
		}
	}

}

vector< vector<int> > read_csv(char file_name[], vector<string> & node_name)
{
	ifstream fp(file_name,ios::in);
	string line_str; //存放每一行的
	vector< vector<string> >str_array_hang; //存放字符串数组的数组
	vector< vector<int>  > map_matrix;  //存放邻接矩阵

	while( getline(fp,line_str) ) //每次读一行
	{
		//cout<<line_str<<endl;  //输出这一行

		stringstream ss(line_str); //转化为 stringstream，类型
		string str;  //用来储存逗号之间的字符串
		vector<string> str_array_lie;

		while(getline(ss,str,','))
		{
			str_array_lie.push_back(str); //把逗号之间的 字符 存储在一个行向量里
		}
		str_array_hang.push_back(str_array_lie);

	}

	//print_vector(str_array_hang);
	map_matrix=str_vector2num_vector(str_array_hang);

#if IS_PRINT_READ_RESULT
	printf("\n节点的名字为：\n");
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

vector< vector<int> > str_vector2num_vector(vector<  vector<string>  > str_array)
{
	//***** 记录传进来的 数组 的维数 *****************
	vector< vector<int> > result;
	int size[2];
	if ( (size[0]=str_array.size()) == 0  ) //行数
	{
		cout<<"this vector has no element"<<endl;
	}
	size[1]=str_array[0].size();  //列数
	//***********  end  *************************

	//****************** 开始遍历，存储进result **************
	for (int row = 1;row < size[0];row++)  //遍历行
	{
		vector<int> row_array; //储存这一行的数字
		for (int col = 1;col < size[1];col++)  //遍历列
		{
			int num;
			stringstream ss(str_array[row][col]);
			ss>>num;
			row_array.push_back(num);  //推进去一个数
		}
		result.push_back(row_array);  //存储一行数据
	}
	//******************  end  ***************************

	//********** 下面是打印result，看是否有问题  ************
	int size_result[2];
	if ( (size_result[0]=result.size()) == 0  ) //行数
	{
		cout<<"this vector has no element"<<endl;
	}
	size_result[1]=result[0].size();  //列数
#if IS_PRINT_READ_RESULT
	printf("邻接矩阵为：\n");
	for (int row = 1; row < size_result[0]; row++)  //遍历行
	{
		for (int col = 1; col < size_result[1]; col++)  //遍历列
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

	for (int row = 0;row < size[0];row++)  //遍历行
	{
		for (int col = 0;col < size[1];col++)  //遍历列
		{
			cout<<str_array[row][col]<<" ";
		}
		cout<<endl;
	}

}