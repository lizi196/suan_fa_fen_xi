#include<iostream> 
#include<algorithm>
using namespace std;
#define MAXWEIGHT 100

/*
ȫ�ֱ���
numV������
numE����
*/

int numV, numE;
//��
typedef struct edge_tag
{
	int tail;
	int head;
	int weight;
}Edge;
//����
bool checkEdge(int tail, int head, int weight)
{
	if (tail == head
		|| tail < 0 || tail >= numV
		|| head < 0 || head >= numV
		|| weight <= 0 || weight >= MAXWEIGHT)
		return false;
	return true;
}
//�����
void inputEdge(Edge *edge, int numE)
{
	int i, tail, head, weight;
	cout << "����ߵ���㡢�յ��Ȩֵ" << endl;
	i = 0;
	while (i < numE)
	{
		cin >> tail >> head >> weight;
		while (!checkEdge(tail, head, weight))
		{
			cout << "���������������" << endl;
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
	parent[child] = Find(parent[child], parent); //ѹ��·��
	return parent[child];
}

//�ϲ�
bool Union(Edge *e, int *parent, int *childs)
{
	//����ͬһ�������У����ܺϲ����������ֻ�
	int root1, root2;
	root1 = Find(e->tail, parent);
	root2 = Find(e->head, parent);
	if (root1 != root2)
	{
		//��С���ϲ�����������
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
	//�ߵļ���
	Edge *edge = new Edge[numE];
	inputEdge(edge, numE);
	int *parent = new int[numV];
	int *childs = new int[numV];
	//��ʼ��
	for (int i = 0; i < numV; i++)
	{
		parent[i] = i;
		childs[i] = 0;
	}
	//�Ա߰�Ȩֵ���д�С��������
	qsort(edge, numE, sizeof(Edge), cmp);
	int i, count;
	i = count = 0;
	cout << "��С�������ı�..." << endl;
	while (i < numE)
	{
		if (Union(&edge[i], parent, childs))
		{
			cout << edge[i].tail << "---" << edge[i].head << endl;
			count++;
		}
		if (count == numV - 1)  //�����ﵽҪ��
			break;
		i++;
	}
	if (count != numV - 1)
		cout << "��ͼΪ����ͨͼ���޷�������С��������" << endl;
	delete[]edge;
	delete[]parent;
	delete[]childs;
}
//��ⶥ�����ͱ���
bool checkVE(int numV, int numE)
{
	if (numV <= 0 || numE <= 0 || numE > numV*(numV - 1) / 2)
		return false;
	return true;
}

int main()
{
	cout << "���붥���������� ";
	cin >> numV >> numE;
	while (!checkVE(numV, numE))
	{
		cout << "�������������⣡�������� ";
		cin >> numV >> numE;
	}
	cout << endl << "Kruskal..." << endl;
	Kruskal(numV, numE);
	system("pause");
	return 0;
}
