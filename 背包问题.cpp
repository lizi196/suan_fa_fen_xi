//0-1��������c++����ʵ��
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(){
    int num,C,i,j,k,len;
    int maxValue=0,sumWeight,sumValue;
    int w[10],v[10],temp[10],res[10];
    char a[10];
    cout<<"������������Ʒ������\n";
    cin>>C>>num;
    cout<<"���������ͼ�ֵ��\n";
    for(i=0;i<num;i++)
        cin>>w[i]>>v[i];
    for(i=0;i<pow(2,num);i++){          //���������Ӽ�
        sumWeight=0;
        sumValue=0;
        itoa(i,a,2);                //��ÿһ�˿���ֵ�ö�����ƥ��
        len=strlen(a);
        memset(temp,0,sizeof(int)*num);         //������������Ϊ0
        for(j=len-1,k=0;j>=0;j--){              //kΪ����������±꣬ÿһ���ѭ��ʱ��Ϊ0
            if(a[j]=='1'){
                sumWeight+=w[num-len+j];
                sumValue+=v[num-len+j];
                temp[k++]=w[num-len+j];
            }
        }
        if(sumWeight<=C&&sumValue>maxValue){
            maxValue=sumValue;
            memset(res,0,sizeof(int)*num);      //���½����
            memcpy(res,temp,sizeof(int)*num);
        }
    }
    cout<<"\nȡ����Ϊ���е��Ӽ�:\n";             //������
    for(i=0;i<k;i++)
        if(res[i])cout<<res[i]<<"  ";
    cout<<"\n����ֵΪ��"<<maxValue;
    return 0;
}


