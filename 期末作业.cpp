#include<iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include<string>

using namespace std;

struct data{
	int minTime;  //一台机器最短时间 
	int start; //从第start个任务开始
	int end;//从第end个任务结束 
};

data getMinTime(int arr[],int num){ //平分数组，将数组分为两组，使这两组子数组之和的差的绝对值最小 
    int n = num;
    int sum = 0;
    data ans; 
    for(int i=0;i<n;i++){
        sum += arr[i];  //把数组a的所有元素求和sum 
    }
    int tmp = 0,x=sum/2;//取和的一半设为x
    ans.minTime = sum;
    for(int i=0;i<n;i++){
        tmp = 0;
        for(int j=i;j<n;j++){
           tmp += arr[j];//遍历数组a的所有子集并且分别求出所有子集的元素之和sum(i)
           
           if((tmp>=(x))&&(tmp<ans.minTime)){ //比较abs(x-sum(i)),取小
            ans.minTime = tmp;
            ans.start=i+1;
            ans.end=j+1;
           }
        }
    }
    return ans;
}

int main(){
	int i,n=5,best_work_time,sum_time=0,T[5]={1,5,2,10,3};//1 2 3 4 12

	data max; //用于记录查找最大时间的任务，记录时间与任务编号 
	int num_machine =2;//机器数量 
	
	for(i=0;i<n;i++){
		cout<<"T"<<i+1<<"="<<T[i]<<endl;
		sum_time+=T[i]; //计算总时间 		
	}
	data ans;
	ans=getMinTime(T,5); //查找最小组合 
	
	cout<<"工作分配如下:"<<endl;
	cout<<"machine1:";
	for(i=ans.start;i<=ans.end;i++){ //输出最小组合的任务分配 
		cout<<i<<" "; 
	} 
	cout<<endl;
	
	cout<<"machine2:";
	for(i=0;i<n;i++){
		if(i<ans.start || i>ans.end){ //输出剩下组合的任务分配 
			cout<<i<<" ";
		}
	} 
	cout<<endl;
	
	cout<<"work_time="<<sum_time-ans.minTime<<endl; //工作时间是取平分后工作时间更大的机器时间 
	return 0;
}

