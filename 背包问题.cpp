//0-1背包问题c++语言实现
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
    cout<<"输入容量和物品个数：\n";
    cin>>C>>num;
    cout<<"输入重量和价值：\n";
    for(i=0;i<num;i++)
        cin>>w[i]>>v[i];
    for(i=0;i<pow(2,num);i++){          //遍历所有子集
        sumWeight=0;
        sumValue=0;
        itoa(i,a,2);                //将每一趟可能值用二进制匹配
        len=strlen(a);
        memset(temp,0,sizeof(int)*num);         //将辅助数组置为0
        for(j=len-1,k=0;j>=0;j--){              //k为辅助数组的下标，每一外层循环时置为0
            if(a[j]=='1'){
                sumWeight+=w[num-len+j];
                sumValue+=v[num-len+j];
                temp[k++]=w[num-len+j];
            }
        }
        if(sumWeight<=C&&sumValue>maxValue){
            maxValue=sumValue;
            memset(res,0,sizeof(int)*num);      //更新结果集
            memcpy(res,temp,sizeof(int)*num);
        }
    }
    cout<<"\n取重量为下列的子集:\n";             //输出结果
    for(i=0;i<k;i++)
        if(res[i])cout<<res[i]<<"  ";
    cout<<"\n最大价值为："<<maxValue;
    return 0;
}


