#include<iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include<string>

using namespace std;

int Merge(int a[],int low, int mid, int high)// �ϲ�����
{
	int j, k, h;
	j = low;
	h = mid + 1;
	k = low;
	int b[999];
	while (j<=mid&&h<=high)
	{
		if (a[j] < a[h])
			b[k++] = a[j++];
		else
			b[k++] = a[h++];
	} 
	while (j <= mid)
	{
		b[k++] = a[j++];
	}
	while (h<=high)
	{
		b[k++] = a[h++];
	}
	for (k = low; k <= high; k++)
	{
		a[k] = b[k];
	}
}

int MergeSort(int a[],int low,int high)	// �ݹ���麯��
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a,low, mid);
		MergeSort(a,mid + 1, high);
		Merge(a,low, mid, high); //�ϲ� 
	}
}

int main(){
	int i,u,n;
	cout << "�������鳤��(ż��)��";
	bool f=1;
	while(f){
		cin >> n;
		if(n%2!=0){
			cout << "���ȴ����ٴ����룺" ;
		}
		else{
			cout<< "������ȷ"<<endl;
			f=0; 
		} 
	}
	int a[999];
	for(i=0;i<n;i++){
		cout << "����a["<<i<<"]=";
		cin >> a[i];
	}
	MergeSort(a,0,n-1);
	cout << "���������(����)��";
	for(i=0;i<n;i++){
		cout <<a[i]<<" ";
	}
}
