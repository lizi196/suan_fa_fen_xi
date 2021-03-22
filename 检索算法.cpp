#include<iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include<string>

using namespace std;
int T[]={0,1,2,3,4,5,6,7,8,9} ;

void way1(int t[],int x,int n){//顺序遍历 
	bool f=0;
	for(int i=0;i<n;i++){
		if(t[i]==x){
			cout<<i<<" ";
			f=1;
		} 
	}
	if(f==0){
		cout<<"j=0";
	}
}

void way2(int t[],int x,int n){//二分遍历 
	int t1=0;
	int t2=n;
	int i=(t1+t2)/2;
	while(t[i]!=x && t1!=t2 && t2>0){
		if(t[i]>x){
			t2=x;
			i=(t1+t2)/2;
		}
		else{
			t1=x;
			i=(t1+t2)/2;
		}
	}
	if(t[i]==x){
		cout<<i<<" ";
	}
	else{
		cout<<"j=0";
	}
}
int main(){
	int a,i,x;
	cin >> x;
	way1(T,x,10);
	way2(T,x,10);
	

	return 0;
}

