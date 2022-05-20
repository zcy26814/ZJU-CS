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



void ChangeColor(int k){
	DefineColor("Light Brown", .70, .40, .10);
	if( k==1 ) SetPenColor("Red");
	if( k==2 ) SetPenColor("Yellow");
	if( k==3 ) SetPenColor("Blue");
	if( k==4 ) SetPenColor("Green");
	if( k==5 ) SetPenColor("Black");
	if( k==6 ) SetPenColor("Brown");
	if( k==7 ) SetPenColor("Violet");
	if( k==8 ) SetPenColor("Magenta");
	if( k==9 ) SetPenColor("Cyan");
	if( k==10 ) SetPenColor("Orange");
	if( k==11 ) SetPenColor("Light Gray");
	if( k==12 ) SetPenColor("Light Brown");
	
}

void DrawRectangle(void *p)
{
	Rec q = (Rec)p;
	double a,b;
	
    SetPenSize(q->PenSize);
    
    if (q->isSelected == TRUE)//������ѡ��״̬����ɫΪ��ɫ������Ϊԭ����ɫ
        ChangeColor(4);
    else
        ChangeColor(q->color);
    
    if( q->isfilling ){
    	if(q->fillpercent == 1) StartFilledRegion(1);
    	if(q->fillpercent == 0.5) StartFilledRegion(0.5);
    }
    
	MovePen(q->x1, q->y1);//�ƶ����ʵ������ָ���λ��
	DrawLine(q->x2-q->x1,0);
	DrawLine(0,q->y2-q->y1);
	DrawLine(q->x1-q->x2,0);
	DrawLine(0,q->y1-q->y2);
	
	if( q->isfilling ) EndFilledRegion();
	
	if(q->x1 > q->x2)
	a = q->x2;
	else
	a = q->x1;
	if(q->y1 > q->y2)
	b = q->y2;
	else
	b = q->y1;
	
	MovePen(a+0.3,b+fabs(q->y2-q->y1)/2);
	if( q->isfilling ) SetPenColor("White");
	DrawTextString(q->memo);
	
	SetPenSize(1);
}

void DrawRhombus(void *p)
{
	Rho q = (Rho)p;
	double a,b;
	
	SetPenSize(q->PenSize);
	
	if (q->isSelected == TRUE)//������ѡ��״̬����ɫΪ��ɫ������Ϊԭ����ɫ
        ChangeColor(4);
    else
        ChangeColor(q->color);
        
    if( q->isfilling ){
    	if(q->fillpercent == 1) StartFilledRegion(1);
    	if(q->fillpercent == 0.5) StartFilledRegion(0.5);
    }
    
	MovePen(q->x1,(q->y1+q->y2)/2);//�ƶ����ʵ������ָ���λ��
	DrawLine((q->x2-q->x1)/2,(q->y2-q->y1)/2);
	DrawLine((q->x2-q->x1)/2,(q->y1-q->y2)/2);
	DrawLine((q->x1-q->x2)/2,(q->y1-q->y2)/2);
	DrawLine((q->x1-q->x2)/2,(q->y2-q->y1)/2);
	
	if( q->isfilling ) EndFilledRegion();
	
	if(q->x1 > q->x2)
	a = q->x2;
	else
	a = q->x1;
	if(q->y1 > q->y2)
	b = q->y2;
	else
	b = q->y1;
	
	MovePen(a+0.3,b+fabs(q->y2-q->y1)/2);
	if( q->isfilling ) SetPenColor("White");
	DrawTextString(q->memo);
	
	SetPenSize(1);
} 

void DrawCenteredEllipse(void *p)
{
	Cen q = (Cen)p;
	double a,b;
	
	SetPenSize(q->PenSize);
	
	double rx = fabs(q->x1-q->x2)/2;//��ȡ��Բ�ĵĳ��� 
	double ry = fabs(q->y1-q->y2)/2;//��ȡ��Բ�Ķ��� 
	
	if (q->isSelected == TRUE)//������ѡ��״̬����ɫΪ��ɫ������Ϊԭ����ɫ
        ChangeColor(4);
    else
        ChangeColor(q->color);
        
    if( q->isfilling ){
    	if(q->fillpercent == 1) StartFilledRegion(1);
    	if(q->fillpercent == 0.5) StartFilledRegion(0.5);
    }
    
	MovePen(q->x2,(q->y1+q->y2)/2);//�ƶ����ʵ������ָ���λ��
	DrawEllipticalArc(rx, ry, 0.0, 360.0);
	
	if( q->isfilling ) EndFilledRegion();
	
	if(q->x1 > q->x2)
	a = q->x2;
	else
	a = q->x1;
	if(q->y1 > q->y2)
	b = q->y2;
	else
	b = q->y1;
	
	MovePen(a+0.3,b+fabs(q->y2-q->y1)/2);
	if( q->isfilling ) SetPenColor("White");
	DrawTextString(q->memo);
	
	SetPenSize(1);
}

void DrawArrow(void *p)
{
	Arr q = (Arr)p;
	double x = 0.2;
	
	SetPenSize(q->PenSize);
	
	if (q->isSelected == TRUE)//������ѡ��״̬����ɫΪ��ɫ������Ϊԭ����ɫ
        ChangeColor(4);
    else
        ChangeColor(q->color);
    
	if (atan((fabs(q->x1-q->x2))/(fabs(q->y1-q->y2))) < (PI/7)){//�жϼ�ͷ�����Ƿ���5*��/14��9*��/14��19*��/14��23*��/14�ķ�Χ��
		if (q->y2-q->y1 <0);
		else x = -x;
		MovePen(q->x1,q->y1);
		DrawLine(q->x2-q->x1,q->y2-q->y1);
		DrawLine(x*sin(PI/4),x*cos(PI/4));
		MovePen(q->x2,q->y2);
		DrawLine(-x*sin(PI/4),x*cos(PI/4));
	}
	else if (atan((fabs(q->y1-q->y2))/(fabs(q->x1-q->x2))) < (PI/7)){//�жϼ�ͷ�����Ƿ���-��/7����/7��6*��/7��8*��/7�ķ�Χ��
		if (q->x2-q->x1 < 0);
		else x = -x;
		MovePen(q->x1,q->y1);
		DrawLine(q->x2-q->x1,q->y2-q->y1);
		DrawLine(x*sin(PI/4),x*cos(PI/4));
		MovePen(q->x2,q->y2);
		DrawLine(x*sin(PI/4),-x*cos(PI/4));
	}
	else {
		if (q->x2-q->x1 > 0 && q->y2-q->y1 > 0){//�жϼ�ͷ�Ƿ��ڵ�һ����
			x = -x;
			MovePen(q->x1,q->y1);
		    DrawLine(q->x2-q->x1,q->y2-q->y1);
		    DrawLine(x,0);
		    MovePen(q->x2,q->y2);
		    DrawLine(0,x);
		}
		else if (q->x2-q->x1 > 0 && q->y2-q->y1 < 0){//�жϼ�ͷ�Ƿ��ڵ������� 
			x = -x;
			MovePen(q->x1,q->y1);
		    DrawLine(q->x2-q->x1,q->y2-q->y1);
		    DrawLine(x,0);
		    MovePen(q->x2,q->y2);
		    DrawLine(0,-x);
		}
		else if (q->x2-q->x1 < 0 && q->y2-q->y1 > 0){//�жϼ�ͷ�Ƿ��ڵڶ�����
			MovePen(q->x1,q->y1);
		    DrawLine(q->x2-q->x1,q->y2-q->y1);
		    DrawLine(x,0);
		    MovePen(q->x2,q->y2);
		    DrawLine(0,-x);
		}
		else if (q->x2-q->x1 < 0 && q->y2-q->y1 < 0){//�жϼ�ͷ�Ƿ��ڵ������� 
			MovePen(q->x1,q->y1);
		    DrawLine(q->x2-q->x1,q->y2-q->y1);
		    DrawLine(x,0);
		    MovePen(q->x2,q->y2);
		    DrawLine(0,x);
		}
	}
	SetPenSize(1);
}

void DrawLine1(void *p)
{
	Lin q = (Lin)p;
	
	SetPenSize(q->PenSize);
	
	if (q->isSelected == TRUE)//������ѡ��״̬����ɫΪ��ɫ������Ϊԭ����ɫ
        ChangeColor(4);
    else
        ChangeColor(q->color);
    
    if( q->isfilling == TRUE ) StartFilledRegion(0.5);
    
	MovePen(q->x1,q->y1);//�ƶ����ʵ������ָ���λ��
	DrawLine(q->x2-q->x1,q->y2-q->y1);
	
	if( q->isfilling == TRUE ) EndFilledRegion();
	
	SetPenSize(1);
}

void DrawParallelogram(void *p)
{
	Par q =(Par)p;
	double a,b;
	
	SetPenSize(q->PenSize);
	
	if (q->isSelected == TRUE)//������ѡ��״̬����ɫΪ��ɫ������Ϊԭ����ɫ
        ChangeColor(4);
    else
        ChangeColor(q->color);
        
    if( q->isfilling ){
    	if(q->fillpercent == 1) StartFilledRegion(1);
    	if(q->fillpercent == 0.5) StartFilledRegion(0.5);
    }
    
	MovePen(q->x1,q->y1);//�ƶ����ʵ������ָ���λ��
	DrawLine((q->x2-q->x1)/5*4,0);
	DrawLine((q->x2-q->x1)/5,q->y2-q->y1);
	DrawLine(-(q->x2-q->x1)/5*4,0);
	DrawLine(-(q->x2-q->x1)/5,-(q->y2-q->y1));
	
	if( q->isfilling ) EndFilledRegion();
	
	if(q->x1 > q->x2)
	a = q->x2;
	else
	a = q->x1;
	if(q->y1 > q->y2)
	b = q->y2;
	else
	b = q->y1;
	
	MovePen(a+0.3,b+fabs(q->y2-q->y1)/2);
	if( q->isfilling ) SetPenColor("White");
	DrawTextString(q->memo);
	
	SetPenSize(1);
}

void DrawRoundedrectangle(void *p)
{
	Rou q = (Rou)p;
	double r = 0.2;
	double a,b; 
    
    SetPenSize(q->PenSize);
    
    if (q->isSelected == TRUE)//������ѡ��״̬����ɫΪ��ɫ������Ϊԭ����ɫ
        ChangeColor(4);
    else
        ChangeColor(q->color);
    
	if ((q->x2-q->x1) > 0 && (q->y2-q->y1) > 0){//�ж�Բ�Ǿ����Ƿ��ڵ�һ���� 
		MovePen(q->x1,q->y1+r);
	    DrawArc(r,180,90);
	    MovePen(q->x1+r,q->y1);
	    DrawLine(q->x2-2*r-q->x1,0);
	    MovePen(q->x2-r,q->y1);
	    DrawArc(r,270,90);
	    MovePen(q->x2,q->y1+r);
	    DrawLine(0,q->y2-2*r-q->y1);
	    MovePen(q->x2,q->y2-r);
	    DrawArc(r,0,90);
	    MovePen(q->x2-r,q->y2);
	    DrawLine(q->x1+2*r-q->x2,0);
	    MovePen(q->x1+r,q->y2);
	    DrawArc(r,90,90);
	    MovePen(q->x1,q->y2-r);
	    DrawLine(0,q->y1-q->y2+2*r);
	}
	if ((q->x2-q->x1) > 0 && (q->y2-q->y1) < 0){//�ж�Բ�Ǿ����Ƿ��ڵ�������
		MovePen(q->x1+r,q->y1);
	    DrawArc(r,90,90);
	    MovePen(q->x1+r,q->y1);
	    DrawLine(q->x2-2*r-q->x1,0);
	    MovePen(q->x2,q->y1-r);
	    DrawArc(r,0,90);
	    MovePen(q->x2,q->y1-r);
	    DrawLine(0,q->y2+2*r-q->y1);
	    MovePen(q->x2-r,q->y2);
	    DrawArc(r,270,90);
	    MovePen(q->x2-r,q->y2);
	    DrawLine(q->x1+2*r-q->x2,0);
	    MovePen(q->x1,q->y2+r);
	    DrawArc(r,180,90);
	    MovePen(q->x1,q->y2+r);
	    DrawLine(0,q->y1-q->y2-2*r);
	}
	if ((q->x2-q->x1) < 0 && (q->y2-q->y1) > 0){//�ж�Բ�Ǿ����Ƿ��ڵڶ����� 
		MovePen(q->x1-r,q->y1);
	    DrawArc(r,270,90);
	    MovePen(q->x1-r,q->y1);
	    DrawLine(q->x2+2*r-q->x1,0);
	    MovePen(q->x2,q->y1+r);
	    DrawArc(r,180,90);
	    MovePen(q->x2,q->y1+r);
	    DrawLine(0,q->y2-2*r-q->y1);
	    MovePen(q->x2+r,q->y2);
	    DrawArc(r,90,90);
	    MovePen(q->x2+r,q->y2);
	    DrawLine(q->x1-2*r-q->x2,0);
	    MovePen(q->x1,q->y2-r);
	    DrawArc(r,0,90);
	    MovePen(q->x1,q->y2-r);
	    DrawLine(0,q->y1-q->y2+2*r);
	}
	if ((q->x2-q->x1) < 0 && (q->y2-q->y1) < 0){//�ж�Բ�Ǿ����Ƿ��ڵ������� 
		MovePen(q->x1,q->y1-r);
	    DrawArc(r,0,90);
	    MovePen(q->x1-r,q->y1);
	    DrawLine(q->x2+2*r-q->x1,0);
	    MovePen(q->x2+r,q->y1);
	    DrawArc(r,90,90);
	    MovePen(q->x2,q->y1-r);
	    DrawLine(0,q->y2+2*r-q->y1);
	    MovePen(q->x2,q->y2+r);
	    DrawArc(r,180,90);
	    MovePen(q->x2+r,q->y2);
	    DrawLine(q->x1-2*r-q->x2,0);
	    MovePen(q->x1-r,q->y2);
	    DrawArc(r,270,90);
	    MovePen(q->x1,q->y2+r);
	    DrawLine(0,q->y1-q->y2-2*r);
	}
	
	if(q->x1 > q->x2)
	a = q->x2;
	else
	a = q->x1;
	if(q->y1 > q->y2)
	b = q->y2;
	else
	b = q->y1;
	
	MovePen(a+0.3,b+fabs(q->y2-q->y1)/2);
	DrawTextString(q->memo);
	
	SetPenSize(1);
}

void DrawText1(void *p)
{
	Tex q = (Tex)p;
	double a,b;
	
	if (q->isSelected == TRUE)//������ѡ��״̬����ɫΪ��ɫ������Ϊԭ����ɫ
        ChangeColor(4);
    else
        ChangeColor(q->color);
    
	MovePen(q->x1,q->y1);//�ƶ����ʵ������ָ���λ��
	SetPenColor("White");
	DrawLine(q->x2-q->x1,0);
	DrawLine(0,q->y2-q->y1);
	DrawLine(q->x1-q->x2,0);
    DrawLine(0,q->y1-q->y2); 
    ChangeColor(q->color);
    if (q->x1 > q->x2)//��ȡ�ı������½ǵ�x���� 
	   a = q->x2;
	else 
	   a = q->x1;
	if (q->y1 > q->y2)//��ȡ�ı������½ǵ�y���� 
	   b = q->y2;
	else
	   b = q->y1; 
	   
    MovePen(a,b+fabs(q->y2-q->y1)/3);//�ƶ����ʵ��ı���ָ���λ��
    DrawTextString(q->memo);//����ַ��� 
}

double distRectangle(double x, double y, Rec a)
{
	double x0,y0,s;
	x0 = (a->x1+a->x2)/2;
	y0 = (a->y1+a->y2)/2;
	s = sqrt(pow(fabs(x-x0),2)+pow(fabs(y-y0),2));//����������������֮��ľ��� 
	return s;
}

double RecRange(Rec a)
{
	double x0,y0,s;
	x0 = fabs(a->x1-a->x2);
	y0 = fabs(a->y1-a->y2);
	s = sqrt(pow(x0,2)+pow(y0,2))/2;//������ε���Ӧ��Χ���ԶԽ���Ϊ�뾶��Բ�Σ�
	return s;
}

double distRoundedrectangle(double x, double y, Rou a)
{
	double x0,y0,s;
	x0 = (a->x1+a->x2)/2;
	y0 = (a->y1+a->y2)/2;
	s = sqrt(pow(fabs(x-x0),2)+pow(fabs(y-y0),2));//���������Բ�Ǿ�������֮��ľ���
	return s;
}

double RouRange(Rou a)
{
	double x0,y0,s;
	x0 = fabs(a->x1-a->x2);
	y0 = fabs(a->y1-a->y2);
	s = sqrt(pow(x0,2)+pow(y0,2))/2;//����Բ�Ǿ��ε���Ӧ��Χ���ԶԽ���Ϊ�뾶��Բ�Σ�
	return s;
}

double distRhombus(double x, double y, Rho a)
{
	double x0,y0,s;
	x0 = (a->x1+a->x2)/2;
	y0 = (a->y1+a->y2)/2;
	s = sqrt(pow(fabs(x-x0),2)+pow(fabs(y-y0),2));//�����������������֮��ľ���
	return s;
}

double RhoRange(Rho a)
{
	double x0,y0,s;
	x0 = fabs(a->x1-a->x2);
	y0 = fabs(a->y1-a->y2);
	s = sqrt(pow(x0,2)+pow(y0,2))/2;//�������ε���Ӧ��Χ���ԶԽ���Ϊ�뾶��Բ�Σ�
	return s;
}

double distCenteredEllipse(double x, double y, Cen a)
{
	double x0,y0,s;
	x0 = (a->x1+a->x2)/2;
	y0 = (a->y1+a->y2)/2;
	s = sqrt(pow(fabs(x-x0),2)+pow(fabs(y-y0),2));//�����������Բ����֮��ľ���
	return s;
}

double CenRange(Cen a)
{
	double x0,y0,s;
	x0 = fabs(a->x1-a->x2);
	y0 = fabs(a->y1-a->y2);
	s = sqrt(pow(x0,2)+pow(y0,2))/2;//������Բ����Ӧ��Χ���ԶԽ���Ϊ�뾶��Բ�Σ�
	return s;
}

double distArrow(double x, double y, Arr a)
{
	double x0,y0,s;
	x0 = (a->x1+a->x2)/2;
	y0 = (a->y1+a->y2)/2;
	s = sqrt(pow(fabs(x-x0),2)+pow(fabs(y-y0),2));//����������ͷ����֮��ľ���
	return s;
}

double ArrRange(Arr a)
{
	double x0,y0,s;
	x0 = fabs(a->x1-a->x2);
	y0 = fabs(a->y1-a->y2);
	s = sqrt(pow(x0,2)+pow(y0,2))/2;//�����ͷ����Ӧ��Χ���ԶԽ���Ϊ�뾶��Բ�Σ�
	return s;
}

double distLine(double x, double y, Lin a)
{
	double x0,y0,s;
	x0 = (a->x1+a->x2)/2;
	y0 = (a->y1+a->y2)/2;
	s = sqrt(pow(fabs(x-x0),2)+pow(fabs(y-y0),2));//���������ֱ������֮��ľ���
	return s;
}

double LinRange(Lin a)
{
	double x0,y0,s;
	x0 = fabs(a->x1-a->x2);
	y0 = fabs(a->y1-a->y2);
	s = sqrt(pow(x0,2)+pow(y0,2))/2;//����ֱ�ߵ���Ӧ��Χ���ԶԽ���Ϊ�뾶��Բ�Σ�
	return s;
}

double distParallelogram(double x, double y, Par a)
{
	double x0,y0,s;
	x0 = (a->x1+a->x2)/2;
	y0 = (a->y1+a->y2)/2;
	s = sqrt(pow(fabs(x-x0),2)+pow(fabs(y-y0),2));//���������ƽ���ı�������֮��ľ���
	return s;
}

double ParRange(Par a)
{
	double x0,y0,s;
	x0 = fabs(a->x1-a->x2);
	y0 = fabs(a->y1-a->y2);
	s = sqrt(pow(x0,2)+pow(y0,2))/2;//����ƽ���ı��ε���Ӧ��Χ���ԶԽ���Ϊ�뾶��Բ�Σ�
	return s;
}

double distText(double x, double y, Tex a)
{
	double x0,y0,s;
	x0 = (a->x1+a->x2)/2;
	y0 = (a->y1+a->y2)/2;
	s = sqrt(pow(fabs(x-x0),2)+pow(fabs(y-y0),2));//����������ı�������֮��ľ���
	return s;
}

double TexRange(Tex a)
{
	double x0,y0,s;
	x0 = fabs(a->x1-a->x2);
	y0 = fabs(a->y1-a->y2);
	s = sqrt(pow(x0,2)+pow(y0,2))/2;//�����ı������Ӧ��Χ���ԶԽ���Ϊ�뾶��Բ�Σ�
	return s;
}

void display()
{
	// ����
	DisplayClear();
	
	// ���ƺʹ���˵�
	drawMenu();
	
	drawEditText();
	
	travel();
}
