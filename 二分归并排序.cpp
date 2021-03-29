#include<iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include<string>

using namespace std;

int Merge(int a[],int low, int mid, int high)// 合并函数
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

int MergeSort(int a[],int low,int high)	// 递归分组函数
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a,low, mid);
		MergeSort(a,mid + 1, high);
		Merge(a,low, mid, high); //合并 
	}
}

int main(){
	int i,u,n;
	cout << "输入数组长度(偶数)：";
	bool f=1;
	while(f){
		cin >> n;
		if(n%2!=0){
			cout << "长度错误，再次输入：" ;
		}
		else{
			cout<< "长度正确"<<endl;
			f=0; 
		} 
	}
	int a[999];
	for(i=0;i<n;i++){
		cout << "数组a["<<i<<"]=";
		cin >> a[i];
	}
	MergeSort(a,0,n-1);
	cout << "排序后数组(升序)：";
	for(i=0;i<n;i++){
		cout <<a[i]<<" ";
	}
}
