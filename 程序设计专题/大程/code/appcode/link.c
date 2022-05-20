#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include "strlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>


#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "imgui.h"
#include "x.h"

linklist *Newlink(void)
{
	linklist *head;
	
	head = (linklist *)malloc(sizeof(linklist));//����ͷ��� 
	head->dataptr = NULL;
	head->next = NULL;
	return head;
}

void Insert(linklist *head, linklist *p, void *q)
{
	linklist *ptr;
	
	if (q == NULL);//�����ݲ����ڣ��򲻲���
	else{
		if (p == NULL){//������½��Ϊ��
		    p = head;
		    while (p->next != NULL) p = p->next;//�ҵ������β�ڵ�
	    }
	    ptr = (linklist *)malloc(sizeof(linklist));//�����½���Ϊβ�ڵ� 
	    ptr->dataptr = q;
	    ptr->next = p->next;
	    p->next = ptr;
	}
}

void travel(void)
{
	travellink(list[Rectangle], DrawRectangle);
	travellink(list[Roundedrectangle], DrawRoundedrectangle);
	travellink(list[Rhombus], DrawRhombus);
	travellink(list[CenteredEllipse], DrawCenteredEllipse);
	travellink(list[Arrow], DrawArrow);
	travellink(list[Line], DrawLine1);
	travellink(list[Parallelogram], DrawParallelogram);
	travellink(list[Text], DrawText1);
}

void travellink(linklist *head, void (*traveler)(void *p))
{
	linklist* q;
	
	if (traveler == NULL);//���ƺ���Ϊ�� 
	if (head->next == NULL);//��������ͼ������ 
	else{
		q=head->next;
	    while (q != NULL)//ѭ����������ͼ�� 
	    {
		   (*traveler)(q->dataptr);
		   q = q->next;
	    }
	}
}

linklist *Next(linklist *p)
{
	if (p != NULL) return p->next;//������һ����� 
	return NULL;
} 

void *Node(linklist *p)
{
	if (p != NULL) return p->dataptr;//���ص�ǰ�������� 
	return NULL;
}

void Deletelink(void)
{
	int i;
	for (i=0;i<NLIST;i++){
		if (list[i]->next!=NULL)
		   list[i]->next=NULL;
	}
}
