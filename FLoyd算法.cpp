#include<iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include<string>
#define MAX 99999

using namespace std;
int map[101][101];
int n,m;
int i,j,k,t;
int num[4][4]={
	{0,2,6,4},
	{MAX,0,3,MAX},
	{7,MAX,0,1},
	{5,MAX,12,0}
	};

int main(){
	memset(map,MAX,sizeof(map));
//	cout<<"输入有多少个顶点："<<endl;
//	cin>> n;
    n=4;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			map[i][j]=num[i][j];
		}
	}
//	for(i=0;i<n;i++){
//		for(j=0;j<n;j++){
//			cout<<map[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	

    for(k=0; k<n; k++)//求最短路
        for(i=0; i<n; i++)
            for( j=0; j<n; j++)
            {
                if(map[i][k]+map[k][j]<map[i][j])
                	map[i][j]=map[i][k]+map[k][j];
            }
    
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<i+1<<"->"<<j+1<<" min_path=";
			cout<<map[i][j]<<endl;
		}
		cout<<endl;
	}
	

	return 0;
}

