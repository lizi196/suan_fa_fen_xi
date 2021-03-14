#include<iostream> 
#include<algorithm>
using namespace std;
#define MAXWEIGHT 100

/*
全局变量
numV顶点数
numE边数
*/

int numV, numE;
//边
typedef struct edge_tag
{
	int tail;
	int head;
	int weight;
}Edge;
//检测边
bool checkEdge(int tail, int head, int weight)
{
	if (tail == head
		|| tail < 0 || tail >= numV
		|| head < 0 || head >= numV
		|| weight <= 0 || weight >= MAXWEIGHT)
		return false;
	return true;
}
//输入边
void inputEdge(Edge *edge, int numE)
{
	int i, tail, head, weight;
	cout << "输入边的起点、终点和权值" << endl;
	i = 0;
	while (i < numE)
	{
		cin >> tail >> head >> weight;
		while (!checkEdge(tail, head, weight))
		{
			cout << "输入错误！重新输入" << endl;
			cin >> tail >> head >> weight;
		}
		edge[i].tail = tail;
		edge[i].head = head;
		edge[i].weight = weight;
		i++;
	}
}
int cmp(const void *edge1, const void *edge2)
{
	return ((Edge*)edge1)->weight - ((Edge*)edge2)->weight;
}
 


int Find(int child, int *parent)
{
	if (parent[child] == child)
		return child;
	parent[child] = Find(parent[child], parent); //压缩路径
	return parent[child];
}

//合并
bool Union(Edge *e, int *parent, int *childs)
{
	//处于同一个棵树中，则不能合并，否则会出现环
	int root1, root2;
	root1 = Find(e->tail, parent);
	root2 = Find(e->head, parent);
	if (root1 != root2)
	{
		//把小树合并到大树根下
		if (childs[root1] > childs[root2])
		{
			parent[root2] = root1;
			childs[root1] += childs[root2] + 1;
		}
		else
		{
			parent[root1] = root2;
			childs[root2] += childs[root2] + 1;
		}
		return true;
	}
	return false;
}

void Kruskal(int numV, int numE)
{
	//边的集合
	Edge *edge = new Edge[numE];
	inputEdge(edge, numE);
	int *parent = new int[numV];
	int *childs = new int[numV];
	//初始化
	for (int i = 0; i < numV; i++)
	{
		parent[i] = i;
		childs[i] = 0;
	}
	//对边按权值进行从小到大排序
	qsort(edge, numE, sizeof(Edge), cmp);
	int i, count;
	i = count = 0;
	cout << "最小生成树的边..." << endl;
	while (i < numE)
	{
		if (Union(&edge[i], parent, childs))
		{
			cout << edge[i].tail << "---" << edge[i].head << endl;
			count++;
		}
		if (count == numV - 1)  //边数达到要求
			break;
		i++;
	}
	if (count != numV - 1)
		cout << "此图为非连通图！无法构成最小生成树。" << endl;
	delete[]edge;
	delete[]parent;
	delete[]childs;
}
//检测顶点数和边数
bool checkVE(int numV, int numE)
{
	if (numV <= 0 || numE <= 0 || numE > numV*(numV - 1) / 2)
		return false;
	return true;
}

int main()
{
	cout << "输入顶点数、边数 ";
	cin >> numV >> numE;
	while (!checkVE(numV, numE))
	{
		cout << "输入数据有问题！重新输入 ";
		cin >> numV >> numE;
	}
	cout << endl << "Kruskal..." << endl;
	Kruskal(numV, numE);
	system("pause");
	return 0;
}
