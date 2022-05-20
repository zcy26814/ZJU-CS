#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
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
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}
struct ListNode *readlist()
{
	struct ListNode *head=NULL,*p,*last;
    int n;
	last=head;    //lastָ�������ƶ���ʾ����ĩβ 
	do{
		scanf("%d",&n);    //��������ֵ 
		if(n!=-1)
		{
			p=(struct ListNode *)malloc(sizeof(struct ListNode));    //�����½ڵ� 
			p->data=n;    //�½ڵ㸳ֵ 
			p->next=NULL;     //�½ڵ�ָ�� 
			if(last==NULL)    //��Ϊͷ���ʱ 
				head=p;
			else
				last->next=p;    //��ͷ���ʱ��β�� 
			last=p;    //��־λ�ƶ����½ڵ㴦		
		}
		else
			break;	
	}while(n!=-1);
		return head;
				
}

struct ListNode *getodd( struct ListNode **L )
{
	//�������빹������������ɾ�������������ͷ��� 
	struct ListNode *odd=NULL,*last,*p,*q,*k;
	last=odd;  //���������������� �����½ڵ�
	p=*L;    //��ʾԭ�����ƶ�ָ�� 
	q=NULL; //q��ʼ������Ϊԭ�����ƶ�ָ��ǰһ���ڵ�ı�� 
	while(p)
	{
		if((p->data)%2) //dataȡ��2Ϊ 1 ��Ϊ������ɾ���ڵ� 
		{
			if(q&&p!=*L) //��L�ո��ڵ������������� 
			{
				k=p; //���������ڵ� 
				q->next=p->next; //ɾ�������ڵ� 
				
				if(last!=NULL)    //����odd���� 
					last->next=k;
				else
					odd=k;
				last=k;		
			}	
			else //L�ĵ�һ���������������  
			{ 
				k=p;              //���������ڵ� 
				*L=p->next;       //ͷ�������ƶ���ɾ�������ڵ� 
				
				if(last!=NULL)    //����odd���� 
					last->next=k;
				else
					odd=k;
				last=k;		
			}
		}
		else
			q=p; //δ�ҵ������ڵ㣬����q������ǰλ�� 		 
		p=p->next; //pָ����������ƶ�
        if(last) //odd����ǿ���
		    last->next=NULL;  //oddĩβָ��ָ�� 
	} 
	return odd;		
}
