#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

struct ListNode *readlist()
{
	//---**β�巨**--- 
	//����3��ָ�����
	//head���ڷ���������׽�㣬�ȳ�ʼ��ָ��
	//p ���������½ڵ� 
	//last ��������head���½ڵ��һ��βָ�룬����ÿ�ζ�ͣ���������β 
	struct ListNode *head=NULL,*p,*last;
	int n;
	//�Ȱ�lastָ��head ����ʼʱ��β����һ�� 
	last=head; 
	do{
		//����ڵ���Ϣ 
		scanf("%d",&n);
		//����ֵ��= -1ʱ ���� 
		if(n!=-1)
		{
			//---�����½ڵ�--- 
			p=(struct ListNode *)malloc(sizeof(struct ListNode));
			p->data=n;
			p->next=NULL; //������½ڵ��ʼ������һ���ڵ�ָ�� 
			
			//---���ӽڵ�----
			//head��Ҫ���أ����������ƶ�������⵽βָ��ָ�գ���ʾ��βָ�벢δ���κ�ֵ 
			if(last==NULL)
				head=p; //ֱ�Ӱѵ�һ���ڵ㸳ֵ��head   
			else
				last->next=p;  //��last�ǿ� ���p���ӵ�last��һ���ڵ� head->last->p->null; 
			last=p; //�������last�ƶ�����p�ϣ����ƶ����µĽ�β 	head->last->p1->last(p)->null;
		}
		else  
			break;
    	}while(n!=-1);// -1����ѭ�� 
	return head;
				
}

struct ListNode *deletem( struct ListNode *L,int m )
{
    //--���ڵ���������ǲ������---
	//��������ָ��һ�������ƶ���һ���������ӣ���ֹ������
	struct ListNode *p,*q;
    p=L;  //p�����ƶ� 
    q=NULL;  //q��ʼ�� 
    //��p�ǿ�ʱ 
    while(p)
    {
		//��dataΪm 
		if(p->data==m)
    	{
    		//���1���м�ڵ����ĩβ�ڵ���m ����ʱ q!=NULL    
			if(q)
				q->next=p->next;    //q->m(p)->x    q->x			
			//���2:�׽ڵ����m ����ʱ q=NULL 
			else
				L=p->next; //��ֱ���ƶ�������׽����� 
		}
		else//data��Ϊm����q�ƶ���p��ǰλ�ã��൱�ڼ�¼pǰһ���ڵ� 
			q=p;
			
		//pָ���ƶ�����һ���ڵ�	
    	p=p->next;
	}
    return L;
}
