#include <stdio.h>
#include <math.h>
#define MAXH 505
#define MAXN 505

/*
ע���ص�h�Ǻڸߣ�n���ڵ���� 
BlackRoot[h][n] ��ʾrootΪ��ɫ�ĺ�������ڸ�Ϊh,�ڽڵ�Ϊn����ɵĲ�ͬ���������
RedRoot[h][n] ��ʾrootΪ��ɫ�ĺ����������rootΪ��ɫ����������������ͨ�����һ�������Ͽ�Ϊ�����������ڸ�Ϊh,�ڽڵ�Ϊn����ɵĲ�ͬ��������� 
*/ 
int BlackRoot[MAXH][MAXN]={0};
int RedRoot[MAXH][MAXN]={0}; 
int mod = 1000000007;

int main(){
	int answer=0;//�������𰸸��� 
	int n, low, high;
    scanf("%d", &n);
    //��֪�����������������׼������֪���е��ƹ�ʽ�����Ƶ������ 
    //nΪ1��2���Ժ����ڸ����Ե������� 
    //ע��˴�̸�۵ĺڸ߾�����Ҷ�ӽڵ������պ��ӵĺڸߣ�*�ص㣩 
    BlackRoot[2][1] = 1;//��Ϊ��ɫ�����������ڸ߶���ڸ���СҲΪ2 
	BlackRoot[2][2] = 2;
    RedRoot[1][1] = 1;
    
	//��n(�ڽڵ�)Ϊ3��ʼ����
	for(int i=3;i<=n;i++){
		//����������Χ�Խ��͸��Ӷȣ��ڵ���Ϊn���ڸ���СΪlog2(n+1)/2,���Ϊlog2(n+1)*2
		int low=log2(i+1)/2;
		int high=log2(i+1)*2;
		for(int j=low;j<high;j++){//�����߶� 
			for(int k=1;k<i-1;k++){//�����������ڵ��� 
				BlackRoot[j][i]+= ((BlackRoot[j-1][k]+RedRoot[j-1][k])*(BlackRoot[j-1][i-k-1]+RedRoot[j-1][i-k-1]))%mod;
				RedRoot[j][i]+=BlackRoot[j][k]*BlackRoot[j][i-k-1]%mod;
				BlackRoot[j][i]%=mod;
				RedRoot[j][i]%=mod;
			} 
		}
	} 
    
    for(int i = 2; i < 30; ++ i)//��ɫ���ڸ�����Ϊ2 
        answer = (answer + BlackRoot[i][n])%mod;
    printf("%d", answer);
} 

