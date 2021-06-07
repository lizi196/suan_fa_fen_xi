
#include <iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

/*
* 这里可以不定义长度，输入的字符串用string存储，然后利用string.c_str()来对字符串进行数组转化。 我这里为了方便没有这样做。
*/
#ifndef MAX_LENGTH
#define MAX_LENGTH 15 //定义字符串最大长度
#endif

int MaxNum(int firstNum, int secondNum){
    return firstNum > secondNum ? firstNum : secondNum;
}

//定义数组结构体
struct matrix{
    int num;
    int direct;
};

typedef matrix Matrix;

int LCS(char *strA, char *strB, int lengthA, int lengthB, Matrix *resultMatrix[]){
    if (lengthA == 0 || lengthB == 0) {
        return 0;
    }
    for (int i = 0; i < lengthA; i++) {
        for (int j = 0; j < lengthB; j++) {
            resultMatrix[i][j].num = 0; //设置所有默认的最长为0
            resultMatrix[i][j].direct = 1; //所有默认方向变成上 0斜上，1上，-1左
        }
    }

    for (int i = 0; i < lengthA; i++) {
        for (int j = 0; j < lengthB; j++) {
            if (strA[i] == strB[j]) {
                resultMatrix[i+1][j+1].num = resultMatrix[i][j].num + 1;
                resultMatrix[i+1][j+1].direct = 0;
            }else{
                resultMatrix[i+1][j+1].num = MaxNum(resultMatrix[i+1][j].num, resultMatrix[i][j+1].num);
                resultMatrix[i+1][j+1].direct = resultMatrix[i+1][j].num > resultMatrix[i][j+1].num ? 1 : -1;
            }
        }
    }
    return resultMatrix[lengthA][lengthB].num;
}

int main(int argc, const char * argv[]) {
    char *strA = (char*)malloc(sizeof(char) * MAX_LENGTH);
    char *strB = (char*)malloc(sizeof(char) * MAX_LENGTH);
    scanf("%s",strA);
    scanf("%s",strB);
    int lengthA = (int)strlen(strA);
    int lengthB = (int)strlen(strB);
    Matrix *resultMatrix[lengthA+1];
    for (int i = 0; i <= lengthA; i++) {
        resultMatrix[i] = (Matrix*)malloc(sizeof(struct matrix)* (lengthB+1));
    }

    int max = LCS(strA, strB, lengthA, lengthB, resultMatrix);
    printf("%d\n",max);
    for(int i=max;i>0;i--){
    	cout<<resultMatrix[i];
	} 
	cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}

