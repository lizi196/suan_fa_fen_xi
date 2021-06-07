
#include <iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

/*
* ������Բ����峤�ȣ�������ַ�����string�洢��Ȼ������string.c_str()�����ַ�����������ת���� ������Ϊ�˷���û����������
*/
#ifndef MAX_LENGTH
#define MAX_LENGTH 15 //�����ַ�����󳤶�
#endif

int MaxNum(int firstNum, int secondNum){
    return firstNum > secondNum ? firstNum : secondNum;
}

//��������ṹ��
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
            resultMatrix[i][j].num = 0; //��������Ĭ�ϵ��Ϊ0
            resultMatrix[i][j].direct = 1; //����Ĭ�Ϸ������� 0б�ϣ�1�ϣ�-1��
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

