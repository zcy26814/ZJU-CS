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

Rec Selectnearest1(linklist *list, double mx, double my)
{
	linklist *list1,*p;
	double distance,mindistance,range;
	
	mindistance = 1000000000.0;
	list1 = NULL;
	p = Next(list);
	if (p == NULL) return NULL;//���Ϊ��
	distance = distRectangle(mx, my, (Rec)Node(p));//��ȡ����뵱ǰ�����εľ���
	range = RecRange((Rec)Node(p));//��ȡ��ǰ�����ε���Ӧ��Χ 
	if (distance <= range){//������С����Ӧ��Χ�򱣴���룬��ȡ�ý���ַ
		mindistance = distance;
		list1 = p;
	}
	while (Next(p) != NULL){//�ҵ�������С�Ľ�㣬������С���벢��ȡ�ý���ַ
		p = Next(p);//������һ����� 
		distance = distRectangle(mx, my, (Rec)Node(p));
		range = RecRange((Rec)Node(p));
		if (distance <= range){
			if (mindistance == 1000000000.0){
				mindistance = distance;
				list1 = p;
			}
			else {
				if (distance < mindistance){//����ǰ������С�ڱ������С���룬�򱣴�þ��벢��ȡ�ýڵ��ַ 
					mindistance = distance;
					list1 = p;
				}
			}
		}
	}
	mindist[Rectangle] = mindistance;//ȫ�ֱ�����ֵ��������ν��ľ���
	if (mindistance == 1000000000.0) return NULL;
	return ((Rec)Node(list1));
}

Rou Selectnearest2(linklist *list, double mx, double my)
{
	linklist *list1,*p;
	double distance,mindistance,range;
	
	mindistance = 1000000000.0;
	list1 = NULL;
	p = Next(list);
	if (p == NULL) return NULL;//���Ϊ��
	distance = distRoundedrectangle(mx, my, (Rou)Node(p));//��ȡ����뵱ǰ�����εľ���
	range = RouRange((Rou)Node(p));//��ȡ��ǰ�����ε���Ӧ��Χ 
	if (distance <= range){//������С����Ӧ��Χ�򱣴���룬��ȡ�ý���ַ
		mindistance = distance;
		list1 = p;
	}
	while (Next(p) != NULL){//�ҵ�������С�Ľ�㣬������С���벢��ȡ�ý���ַ
		p = Next(p);//������һ����� 
		distance = distRoundedrectangle(mx, my, (Rou)Node(p));
		range = RouRange((Rou)Node(p));
		if (distance <= range){
			if (mindistance == 1000000000.0){
				mindistance = distance;
				list1 = p;
			}
			else {
				if (distance < mindistance){//����ǰ������С�ڱ������С���룬�򱣴�þ��벢��ȡ�ýڵ��ַ 
					mindistance = distance;
					list1 = p;
				}
			}
		}
	}
	mindist[Roundedrectangle] = mindistance;//ȫ�ֱ�����ֵ��������ν��ľ���
	if (mindistance == 1000000000.0) return NULL;
	return ((Rou)Node(list1));
}

Rho Selectnearest3(linklist *list, double mx, double my)
{
	linklist *list1,*p;
	double distance,mindistance,range;
	
	mindistance = 1000000000.0;
	list1 = NULL;
	p = Next(list);
	if (p == NULL) return NULL;//���Ϊ��
	distance = distRhombus(mx, my, (Rho)Node(p));//��ȡ����뵱ǰ�����εľ���
	range = RhoRange((Rho)Node(p));//��ȡ��ǰ�����ε���Ӧ��Χ 
	if (distance <= range){//������С����Ӧ��Χ�򱣴���룬��ȡ�ý���ַ
		mindistance = distance;
		list1 = p;
	}
	while (Next(p) != NULL){//�ҵ�������С�Ľ�㣬������С���벢��ȡ�ý���ַ
		p = Next(p);//������һ����� 
		distance = distRhombus(mx, my, (Rho)Node(p));
		range = RhoRange((Rho)Node(p));
		if (distance <= range){
			if (mindistance == 1000000000.0){
				mindistance = distance;
				list1 = p;
			}
			else {
				if (distance < mindistance){//����ǰ������С�ڱ������С���룬�򱣴�þ��벢��ȡ�ýڵ��ַ 
					mindistance = distance;
					list1 = p;
				}
			}
		}
	}
	mindist[Rhombus] = mindistance;//ȫ�ֱ�����ֵ��������ν��ľ���
	if (mindistance == 1000000000.0) return NULL;
	return ((Rho)Node(list1));
}

Cen Selectnearest4(linklist *list, double mx, double my)
{
	linklist *list1,*p;
	double distance,mindistance,range;
	
	mindistance = 1000000000.0;
	list1 = NULL;
	p = Next(list);
	if (p == NULL) return NULL;//���Ϊ��
	distance = distCenteredEllipse(mx, my, (Cen)Node(p));//��ȡ����뵱ǰ�����εľ���
	range = CenRange((Cen)Node(p));//��ȡ��ǰ�����ε���Ӧ��Χ 
	if (distance <= range){//������С����Ӧ��Χ�򱣴���룬��ȡ�ý���ַ
		mindistance = distance;
		list1 = p;
	}
	while (Next(p) != NULL){//�ҵ�������С�Ľ�㣬������С���벢��ȡ�ý���ַ
		p = Next(p);//������һ����� 
		distance = distCenteredEllipse(mx, my, (Cen)Node(p));
		range = CenRange((Cen)Node(p));
		if (distance <= range){
			if (mindistance == 1000000000.0){
				mindistance = distance;
				list1 = p;
			}
			else {
				if (distance < mindistance){//����ǰ������С�ڱ������С���룬�򱣴�þ��벢��ȡ�ýڵ��ַ 
					mindistance = distance;
					list1 = p;
				}
			}
		}
	}
	mindist[CenteredEllipse] = mindistance;//ȫ�ֱ�����ֵ��������ν��ľ���
	if (mindistance == 1000000000.0) return NULL;
	return ((Cen)Node(list1));
}

Arr Selectnearest5(linklist *list, double mx, double my)
{
	linklist *list1,*p;
	double distance,mindistance,range;
	
	mindistance = 1000000000.0;
	list1 = NULL;
	p = Next(list);
	if (p == NULL) return NULL;//���Ϊ��
	distance = distArrow(mx, my, (Arr)Node(p));//��ȡ����뵱ǰ�����εľ���
	range = ArrRange((Arr)Node(p));//��ȡ��ǰ�����ε���Ӧ��Χ 
	if (distance <= range){//������С����Ӧ��Χ�򱣴���룬��ȡ�ý���ַ
		mindistance = distance;
		list1 = p;
	}
	while (Next(p) != NULL){//�ҵ�������С�Ľ�㣬������С���벢��ȡ�ý���ַ
		p = Next(p);//������һ����� 
		distance = distArrow(mx, my, (Arr)Node(p));
		range = ArrRange((Arr)Node(p));
		if (distance <= range){
			if (mindistance == 1000000000.0){
				mindistance = distance;
				list1 = p;
			}
			else {
				if (distance < mindistance){//����ǰ������С�ڱ������С���룬�򱣴�þ��벢��ȡ�ýڵ��ַ 
					mindistance = distance;
					list1 = p;
				}
			}
		}
	}
	mindist[Arrow] = mindistance;//ȫ�ֱ�����ֵ��������ν��ľ���
	if (mindistance == 1000000000.0) return NULL;
	return ((Arr)Node(list1));
}

Lin Selectnearest6(linklist *list, double mx, double my)
{
	linklist *list1,*p;
	double distance,mindistance,range;
	
	mindistance = 1000000000.0;
	list1 = NULL;
	p = Next(list);
	if (p == NULL) return NULL;//���Ϊ��
	distance = distLine(mx, my, (Lin)Node(p));//��ȡ����뵱ǰ�����εľ���
	range = LinRange((Lin)Node(p));//��ȡ��ǰ�����ε���Ӧ��Χ 
	if (distance <= range){//������С����Ӧ��Χ�򱣴���룬��ȡ�ý���ַ
		mindistance = distance;
		list1 = p;
	}
	while (Next(p) != NULL){//�ҵ�������С�Ľ�㣬������С���벢��ȡ�ý���ַ
		p = Next(p);//������һ����� 
		distance = distLine(mx, my, (Lin)Node(p));
		range = LinRange((Lin)Node(p));
		if (distance <= range){
			if (mindistance == 1000000000.0){
				mindistance = distance;
				list1 = p;
			}
			else {
				if (distance < mindistance){//����ǰ������С�ڱ������С���룬�򱣴�þ��벢��ȡ�ýڵ��ַ 
					mindistance = distance;
					list1 = p;
				}
			}
		}
	}
	mindist[Line] = mindistance;//ȫ�ֱ�����ֵ��������ν��ľ���
	if (mindistance == 1000000000.0) return NULL;
	return ((Lin)Node(list1));
}

Par Selectnearest7(linklist *list, double mx, double my)
{
	linklist *list1,*p;
	double distance,mindistance,range;
	
	mindistance = 1000000000.0;
	list1 = NULL;
	p = Next(list);
	if (p == NULL) return NULL;//���Ϊ��
	distance = distParallelogram(mx, my, (Par)Node(p));//��ȡ����뵱ǰ�����εľ���
	range = ParRange((Par)Node(p));//��ȡ��ǰ�����ε���Ӧ��Χ 
	if (distance <= range){//������С����Ӧ��Χ�򱣴���룬��ȡ�ý���ַ
		mindistance = distance;
		list1 = p;
	}
	while (Next(p) != NULL){//�ҵ�������С�Ľ�㣬������С���벢��ȡ�ý���ַ
		p = Next(p);//������һ����� 
		distance = distParallelogram(mx, my, (Par)Node(p));
		range = ParRange((Par)Node(p));
		if (distance <= range){
			if (mindistance == 1000000000.0){
				mindistance = distance;
				list1 = p;
			}
			else {
				if (distance < mindistance){//����ǰ������С�ڱ������С���룬�򱣴�þ��벢��ȡ�ýڵ��ַ 
					mindistance = distance;
					list1 = p;
				}
			}
		}
	}
	mindist[Parallelogram] = mindistance;//ȫ�ֱ�����ֵ��������ν��ľ���
	if (mindistance == 1000000000.0) return NULL;
	return ((Par)Node(list1));
}

Tex Selectnearest8(linklist *list, double mx, double my)
{
	linklist *list1,*p;
	double distance,mindistance,range;
	
	mindistance = 1000000000.0;
	list1 = NULL;
	p = Next(list);
	if (p == NULL) return NULL;//���Ϊ��
	distance = distText(mx, my, (Tex)Node(p));//��ȡ����뵱ǰ�����εľ���
	range = TexRange((Par)Node(p));//��ȡ��ǰ�����ε���Ӧ��Χ 
	if (distance <= range){//������С����Ӧ��Χ�򱣴���룬��ȡ�ý���ַ
		mindistance = distance;
		list1 = p;
	}
	while (Next(p) != NULL){//�ҵ�������С�Ľ�㣬������С���벢��ȡ�ý���ַ
		p = Next(p);//������һ����� 
		distance = distText(mx, my, (Tex)Node(p));
		range = TexRange((Par)Node(p));
		if (distance <= range){
			if (mindistance == 1000000000.0){
				mindistance = distance;
				list1 = p;
			}
			else {
				if (distance < mindistance){//����ǰ������С�ڱ������С���룬�򱣴�þ��벢��ȡ�ýڵ��ַ 
					mindistance = distance;
					list1 = p;
				}
			}
		}
	}
	mindist[Text] = mindistance;//ȫ�ֱ�����ֵ��������ν��ľ���
	if (mindistance == 1000000000.0) return NULL;
	return ((Tex)Node(list1));
}

void Picknearest(linklist *list[], double omx, double omy)
{
	int i, min;
	
	curRectangle = Selectnearest1(list[Rectangle], omx, omy);
	curRoundedrectangle = Selectnearest2(list[Roundedrectangle], omx, omy);
	curRhombus = Selectnearest3(list[Rhombus], omx, omy);
	curCenteredEllipse = Selectnearest4(list[CenteredEllipse], omx, omy);
	curArrow = Selectnearest5(list[Arrow], omx, omy);
	curLine = Selectnearest6(list[Line], omx, omy);
	curParallelogram = Selectnearest7(list[Parallelogram], omx, omy);
	curText = Selectnearest8(list[Text], omx, omy);
	
	min = 0;
	for (i = 1; i < NLIST; i++) {//ѭ���ҵ��������������ͼ��
		if (mindist[i] < mindist[min]) min = i;
	}
	curList = min;
	
}

