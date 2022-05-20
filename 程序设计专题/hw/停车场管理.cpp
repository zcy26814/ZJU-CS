#include<stdio.h>
#include<stdlib.h>
struct Space{
	int car;		//������� 
	int into_time;	// ͣ��ʱ�� 
	char empty;		// �ж��ܷ�ͣ�� ��Y�����ԣ���N�����С� 
}space[10];
typedef struct infor{
	char state;		//״̬ ��A D E�� 
	int car;		//��� 
	int time;		//ʱ�� 
	struct infor *next;
}Infor;
Infor *creat_infor();
int main(void)
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++){
		space[i].empty = 'Y';
	} 
	
	// �������� 
	Infor *head = creat_infor();
	int cnt = 0; 		//��¼ͣ�복������ 
	int rret = 0;		//�����ж��Ƿ� waiting
	int out_time = 0;	//��a��Ҫͣ��ʱû��λ��b��������ͣ��� a����ʱ��ĳ�b��������ʱ�� 
	
	Infor *p = head;
	while(p){
		if(p->state == 'A'){
			//Ѱ���Ƿ��пճ�λ 
			for(i=0; i<n; i++){ 
				if(space[i].empty == 'Y'){
					//����пճ�λ���ж�out��time��û�б����ģ���������˵��������� 
					if(out_time){
						p->time = out_time;
						out_time = 0;	//ʹ�����Ļ�0 
					}
					// ����λ��Ϣ�ĳɸó�����Ϣ 
					space[i].car = p->car;
					space[i].into_time = p->time;
					space[i].empty = 'N';		//��λ��Ϊ����ͣ��״̬ 
					p->state = '0'; 			// �ı����Ϣ״̬�����ٴ��� 
					printf("car#%d in parking space #%d\n",space[i].car,i+1);
					cnt++;						// ����ͣ�룬cnt��һ 
					break;
				}
			}
			// i����n˵��ѭ������û���ҵ��ճ�λ 
			if(i == n){
				printf("car#%d waiting\n",p->car);
				rret++;		//��¼�г��ڵȴ��� 
			}
		}else if(p->state == 'D'){
			int ret = 1;		//�����ж���ͣ��λ����û�иó���1Ϊû�� 
			for(i=0; i<n; i++){
				if(space[i].car == p->car){
					printf("car#%d out,parking time %d\n",space[i].car,p->time-space[i].into_time);
					//���cnt����n�ͱ���ͣ����ͣ���� ��rret ���� 1�����г��ڵȴ���⣬��Ҫ��¼�˳���ȥʱ�䡣 
					if(rret){
						out_time = p->time;
						p->state = '0'; // �ı����Ϣ״̬�����ٴ���
						rret--;
						p = head;
					}
					cnt--;
					for(i; i<n-1; i++){
						space[i].car = space[i+1].car;
						space[i].empty = space[i+1].empty;
						space[i].into_time = space[i+1].into_time;
					}
					space[i].empty = 'Y';
					p->state = '0'; // �ı����Ϣ״̬�����ٴ��� 
					ret = 0;
					break;
				}
			}
			if(ret){
				printf("the car not in park\n");
			}
		}
		p = p->next;
	}
	return 0;
} 
//��������洢�������Ϣ 
Infor *creat_infor(){
	Infor *head = NULL;
	char state;
	int car;
	int time;
	do{
		fflush(stdin);//������뻺��������ֹs���տո�س� 
		scanf("%c",&state);
		scanf("%d%d",&car,&time);
		if(state != 'E'){
			Infor *p = (Infor*)malloc(sizeof(Infor));
			p->state = state;
			p->car = car;
			p->time = time;
			p->next = NULL;
			Infor *last = head;
			// ���last���ǿ������head�Ѿ��������ݡ� 
			if(last != NULL){
				while(last->next){
					last = last->next;
				}
				last->next = p;
			}else{
				head = p;
			}			
		}		
	}while( state != 'E');
	return head;
} 
