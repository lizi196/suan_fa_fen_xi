#include<iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include<string>

using namespace std;

int ff1(int x){
	if(x!=0){
		return 10+x;
	}
	return 0; 
} 
int ff2(int x){
	if(x!=0){
		return (x-1)*5;
	}
	return 0; 
} 
int ff3(int x){
	if(x!=0){
		if(x==1) return 2;
		if(x==2) return 10;
		if(x==3) return 30;
		if(x==4) return 32;
		if(x==5) return 40;
	}
	return 0; 
} 
int ff4(int x){
	if(x!=0){
		return 19+x;
	}
	return 0; 
} 

int ff(int a,int x){
	if(a==1) return ff1(x);
	if(a==2) return ff2(x);
	if(a==3) return ff3(x);
	if(a==4) return ff4(x);
}

int main(){
	int i,j,k,x,y;
	int sum,max;
	int f[100][100],F[100][100];
	cout<<"4��Ͷ�ʣ���5��Ԫ��"<<endl;
	int n=4,m=5;


	for(i=0;i<=5;i++){
		for(j=1;i<=4;i++){
			f[j][i]=ff(j,i);//j��1��ʼ��Ҳ���Ǵ�f[0][1]��ʼ
		}
	}
	
	for (i = 0; i < n; ++i) {
		f[i][0] = 0;//�ڵ�(i+1)����Ŀ��Ͷ��0Ԫ������Ϊ0��ע��i��0��ʼ
	}
	
	for (j = 0; j < m + 1; ++j) {
		F[0][j] = f[0][j];//��һ����Ŀ��Ͷ��0-mԪǮ������������f[0][0-m]
	}
	
	int tmp_m, tmp_F = 0;//tmp_m�������i����ĿͶ���Ǯ��  0<=tmp<=j;tmp_F����һ��ѭ���е�Ǯ��
	
	for (i = 1; i < n; ++i) {//��Ŀѭ������1��ʼ,Ҳ���Ǵ�ǰ2����Ŀ��ʼ�㣬��Ϊ��һ����Ŀ�Ѿ���ֵ
		for (j = 0; j < m + 1; ++j) {//Ǯ��ѭ�� ��0��ʼ
			for (tmp_m = 0; tmp_m <= j; ++tmp_m) {
				tmp_F = F[i - 1][j - tmp_m] + f[i][tmp_m];
				if (tmp_F > F[i][j])
					F[i][j] = tmp_F;
			}
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			cout <<"F["<<i<<"]["<<j<<"]="<< F[i][j] <<"   ";	
		}
		cout<<endl;
	}
	
	
	return 0;
}

