#include<stdio.h>
struct condition{
	int obj1;	//���ڴ洢����ĵ�һ����ĸ- 'A'��ֵ 
	int obj2;	//�洢�ڶ�����ĸ�� 
	int num;	//�洢���� 
	int ret;	//�Ƿ��� =  
}condition[20];

int judge(int *a,int n);	//�жϺ��� 

int main(void)
{
	int n;
	scanf("%d\n",&n);
	int i;
	char s[5];
	
	//¼������ 
	for(i=0; i<n; i++){
		gets(s);
		condition[i].obj1 = s[0] - 'A';
		if(s[1] != '='){
			condition[i].obj2 = s[2] - 'A';
			condition[i].num = s[3] - '0';
			condition[i].ret = 0;		//�������Ĳ��� = ��ret¼Ϊ1��		
		}
		else{
			condition[i].num = s[2] - '0';	
			condition[i].ret = 1;
		}
		if(s[1] == '<'){
			condition[i].num *= -1;		//����� < �洢�����ֱ�Ϊ���� 
		}
		
	}

	//ѭ�������鸳ֵ 0~6����������ڸ��жϺ����ж��Ƿ��������������� 
	int day[7] ;	//ֵ��˳�� ���±��ʾ ABCDEFG����Ӧֵ��ʾʱ�䡣 
	int a,b,c,d,e,f,g;
	for(a=0; a<7; a++){
		for(b=0; b<7 ; b++){
			for(c=0; c<7 ; c++){
				for(d=0; d<7 ; d++){
					for(e=0; e<7 ; e++){
						for(f=0; f<7 ; f++){
							for(g=0; g<7 ; g++){
								day[0] = a;
								day[1] = b;
								day[2] = c;
								day[3] = d;
								day[4] = e;
								day[5] = f;
								day[6] = g;
								if(judge(day,n))	//�ж��Ƿ��������������� 
									goto E;
							}
						}
					}
				}
			}
		}
	}
E:	
	if(judge(day,n)){
		char Day[8];
		for(i=0; i<7; i++){
			Day[day[i]] = i + 'A';	//��ֵ��ʱ�䰴˳��д���Ӧ��� 
		}
		Day[8] = '\0';
		puts(Day);
	}
	
	return 0;
}

int judge(int *a,int n){
	int i = 0;
	int ret = 1;
	
	//�жϴ����ֵ������������������Ƿ���ϡ� 
	for(i=0; i<n; i++)
	{
		//����� = �����ж�ֵ�����ں���������-1�Ƿ���� .��ֵ�������Ǵ�0��ʼ��ģ� 
		if(condition[i].ret){
			if(a[condition[i].obj1] != condition[i].num - 1)
				ret = 0;
				break;
		} 
		else if(a[condition[i].obj1] + condition[i].num != a[condition[i].obj2]){
			ret = 0;
			break;
		}
	}
	return ret;
}
