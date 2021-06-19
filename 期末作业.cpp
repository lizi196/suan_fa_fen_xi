#include<iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include<string>

using namespace std;

struct data{
	int minTime;  //һ̨�������ʱ�� 
	int start; //�ӵ�start������ʼ
	int end;//�ӵ�end��������� 
};

data getMinTime(int arr[],int num){ //ƽ�����飬�������Ϊ���飬ʹ������������֮�͵Ĳ�ľ���ֵ��С 
    int n = num;
    int sum = 0;
    data ans; 
    for(int i=0;i<n;i++){
        sum += arr[i];  //������a������Ԫ�����sum 
    }
    int tmp = 0,x=sum/2;//ȡ�͵�һ����Ϊx
    ans.minTime = sum;
    for(int i=0;i<n;i++){
        tmp = 0;
        for(int j=i;j<n;j++){
           tmp += arr[j];//��������a�������Ӽ����ҷֱ���������Ӽ���Ԫ��֮��sum(i)
           
           if((tmp>=(x))&&(tmp<ans.minTime)){ //�Ƚ�abs(x-sum(i)),ȡС
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

	data max; //���ڼ�¼�������ʱ������񣬼�¼ʱ���������� 
	int num_machine =2;//�������� 
	
	for(i=0;i<n;i++){
		cout<<"T"<<i+1<<"="<<T[i]<<endl;
		sum_time+=T[i]; //������ʱ�� 		
	}
	data ans;
	ans=getMinTime(T,5); //������С��� 
	
	cout<<"������������:"<<endl;
	cout<<"machine1:";
	for(i=ans.start;i<=ans.end;i++){ //�����С��ϵ�������� 
		cout<<i<<" "; 
	} 
	cout<<endl;
	
	cout<<"machine2:";
	for(i=0;i<n;i++){
		if(i<ans.start || i>ans.end){ //���ʣ����ϵ�������� 
			cout<<i<<" ";
		}
	} 
	cout<<endl;
	
	cout<<"work_time="<<sum_time-ans.minTime<<endl; //����ʱ����ȡƽ�ֺ���ʱ�����Ļ���ʱ�� 
	return 0;
}

