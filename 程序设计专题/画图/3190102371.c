/* ��Ŀ1 */

#include "graphics.h"
#include "genlib.h"
#include "conio.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

/*
 * �����궨�� 
 * ---------- 
 *���廭���ӵĸ������ݴ�С 
 */

#define HouseHeight         2.5
#define HouseWidth          2.0
#define AtticHeight         2.0

#define DoorWidth           0.5
#define DoorHeight          1.8

#define PaneHeight          0.5
#define PaneWidth           0.4

#define WindowsWidth        0.3
#define WindowsHeight       1.25

#define Chimney1Height      0.8
#define Chimney2Height      0.1
#define Chimney2Width       0.4

#define deltax1             0.2
#define deltax2             0.1
#define deltay              0.4

/* ���廭����������ຯ�� */
 
void DrawHouse(double x, double y);/* ���廭���ӵĺ��� */
void DrawOutline(double x, double y); /* ���廭���������ĺ��� */
void DrawWindows(double x, double y);/* ���廭���ĺ��� */
void DrawDoor(double x, double y); /* ���廭�ŵĺ��� */
void DrawBox(double x, double y, double width, double height);/* ���廭����ĺ��� */
void DrawTriangle(double x, double y, double base, double height);/* ���廭�ݶ��ĺ��� */

/* ����Ϊ������ */

void Main()
{
    double cx, cy;

    InitGraphics();/*ͼ�γ�ʼ��*/
    cx = GetWindowWidth() / 2;
    cy = GetWindowHeight() / 2;
    DrawHouse(cx - HouseWidth / 2, cy - (HouseHeight + AtticHeight) / 2);
}

/* ���ã������� */ 

void DrawHouse(double x, double y)
{
    DrawOutline(x, y);
    DrawDoor(x + HouseWidth / 2, y);
    DrawWindows(x, y);
    DrawChimney1(x, y);
    DrawChimney2(x, y);
}

/* ���ã������� */

void DrawBox(double x, double y, double width, double height)
{
    MovePen(x, y);
    DrawLine(0, height);
    DrawLine(width, 0);
    DrawLine(0, -height);
    DrawLine(-width, 0);
}

/* ���ã����������� */

void DrawOutline(double x, double y)
{
    DrawBox(x, y, HouseWidth, HouseHeight);
    DrawTriangle(x, y + HouseHeight, HouseWidth, AtticHeight);
}

/* ���ã����� */

void DrawDoor(double x, double y)
{
    DrawBox(x, y, DoorWidth, DoorHeight);
}

/* ���ã����� */

void DrawWindows(double x, double y)
{
    DrawBox(x + WindowsWidth, y + WindowsHeight, PaneWidth, PaneHeight); 
}


/* ���ã��������� */

void DrawTriangle(double x, double y, double base, double height)
{
    MovePen(x, y);
    DrawLine(base, 0);
    DrawLine(-base / 2, height);
    DrawLine(-base / 2, -height);
}

/* ���ã����̴ѣ��̴�һ���������� */

DrawChimney1(double x, double y)
{
	MovePen(x + deltax1, y + HouseHeight + deltay);
	DrawLine(0, Chimney1Height);
	DrawLine(deltax1, 0);
	DrawLine(0, -Chimney1Height/2);
}

DrawChimney2(double x, double y)
{
	DrawBox(x + deltax2, y + HouseHeight + deltay + Chimney1Height, Chimney2Width, Chimney2Height);
}





/* ��Ŀ2 */

#include "graphics.h"
#include "extgraph.h" 
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include "random.h"
#include "strlib.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

/* �궨�峣���� */
 
#define  PI     3.1415926

/* �������躯�� */
 
void forward(double distance);/* ���廭�߶εĺ��� */
void turn(double angle); /* ������ת�ĺ��� */
void move(double distance);/* �����ƶ��ʶ˵ĺ��� */
void DrawHexagonal(double x, double y); /* ���廭�����εĺ��� */
 
double theta = 0;/* ��ʼ���Ƕ�Ϊ0 */

/* ����Ϊ������ */
 
void Main()
{ 
    InitGraphics(); /*ͼ�γ�ʼ��*/

    DefineColor("DeepGreen", 0, 0.49, 0);/* �Զ�������ɫ */
    SetPenColor("DeepGreen");/* ���ã��ѻ�����ɫ��������ɫ */
   
    double cx, cy;
    int i=0;

    cx = GetWindowWidth()/2;
    cy = GetWindowHeight()/2;

   
/* ��ͼ˼·��ͼ��Ϊһ������������һ���˵���ת20��,����ת18�ζ��� */

    for(i=0;i<18;i++){ 
        DrawHexagonal(cx, cy);
        theta += 20;
    } 
}

/* ���ã���ֱ�� */ 
void forward(double distance)
{
	DrawLine(distance*cos(theta/ 180 * PI), distance*sin(theta/ 180 * PI));
}

/* 
 *angleΪ��ֵ����ʾ�ǵ��ձ���ʱ����ת 
 *----------------------------------- 
 * ���ã�������ת 
 */
 
void turn(double angle)
{
	theta += angle;
}

/* ���ã��ƶ����ʵıʶ�*/
 
void move(double distance)
{
	MovePen(distance*cos(theta/ 180 * PI), distance*sin(theta/ 180 * PI));
}

/* ���ã��������� */

void DrawHexagonal(double x, double y)
{
	double line = 1.5;
	MovePen(x,y);
	turn(60);
	forward(line);
	turn(-60);
	forward(line);
	turn(-60);
	forward(line);
	turn(-60);
	forward(line);
	turn(-60);
	forward(line);
	turn(-60);
	forward(line);
}





/* ��Ŀ3 */

#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

int cx,cy;

bool inBox(double x0, double y0)
{
	return(x0 > 0 && x0 < cx && y0 > 0 && y0 < cy);
}

void MouseEventProcess(int x, int y, int button, int event)/*�����Ϣ�ص�����*/
{
	static double lx=0.0, ly=0.0;
	double mx,my;
	
	/* ���ã�������ת��ΪӢ�� */
	
	mx = ScaleXInches(x);
	my = ScaleYInches(y) ;
	
	static bool isDraw = FALSE;
	
	switch(event){
		case BUTTON_DOWN:/* ����������� */
		    if (button == LEFT_BUTTON){
		    	isDraw = TRUE;/* ��ס���������� */ 
			} 
			break;
		case BUTTON_DOUBLECLICK:/* ˫��������� */ 
			break;
		case BUTTON_UP:/* �ɿ�������� */
			if (button == LEFT_BUTTON){
				isDraw = FALSE;/* �ɿ�������ֹͣ���� */
			}
		case MOUSEMOVE:/* �ƶ����������ǻ��� */ 
		    if(isDraw){
		    	DrawLine(mx-lx,my-ly);
		    	MovePen(mx,my);
			} 
			break;
	}
	lx = mx;
	ly = my;
}

void Main()
{
	InitGraphics();
	
	cx = GetWindowWidth();
	cy = GetWindowHeight();
	registerMouseEvent(MouseEventProcess);/* ע�����ص����� */ 
	SetPenSize(1);/* ���û��ʴ�ϸΪ1 */ 
}





/* ��Ŀ4 */

#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#define TIMER_BLINK200  1/* �궨���ʱ������ */ 

const int mseconds200 = 200;
double cx, cy;

static char* p1, * p2;
static char text[100] = { '\0', '\0' };
static int ptr = 0, textlen = 0;/* ������ַ������� */
static double textx, texty; /* �ַ������ʼλ�� */
static bool IsBlink = TRUE; /* �Ƿ���˸��־ */

/* �������躯�� */

void startTimer(int id, int timeinterval);
void cancelTimer(int id);
void deleteit(int a);
void add(int a, char c);
void CleanBlink();
void Blinkit();
void KeyboardEventProcess(int key, int event);/* ������Ϣ�ص����� */
void CharEventProcess(char c); /* �ַ���Ϣ�ص����� */
void TimerEventProcess(int timerID);/* ��ʱ����Ϣ�ص����� */

/* ����Ϊ������  */

void Main()/* ����ʼ��ִ��һ�� */
{
    InitGraphics();/* ͼ�γ�ʼ�� */

    registerKeyboardEvent(KeyboardEventProcess);/* ע�������Ϣ�ص����� */
    registerCharEvent(CharEventProcess);/* ע���ַ���Ϣ�ص����� */
    registerTimerEvent(TimerEventProcess); /* ע�ᶨʱ����Ϣ�ص����� */

    startTimer(TIMER_BLINK200, mseconds200);
    SetPenColor("Black"); /* ���û�����ɫΪ�� */
    SetPenSize(1);/* ���û��ʴ�ϸΪ/ */

    cx = 0;
    cy = GetWindowHeight() - 0.1;
    textx = cx;
    texty = cy;
}

void CharEventProcess(char c)/* �ַ���Ϣ�ص����� */
{
    switch (c) {
    case '\b':/* �����˸������� */
        CleanBlink();

        MovePen(cx, cy);
        SetEraseMode(TRUE);
        DrawTextString(text);
        if (ptr) {
            deleteit(ptr--);
            textlen--;
        }
        p1 = &text[0];
        p2 = &text[ptr];

        MovePen(cx, cy);
        SetEraseMode(FALSE);
        DrawTextString(text);/* �����ǰ�ַ��������λ����Ӧ���� */
        Blinkit();
        break;
    default:
        CleanBlink();

        MovePen(cx, cy);
        SetEraseMode(TRUE);
        DrawTextString(text);
        add(ptr, c);
        ptr++;
        text[++textlen] = '\0';

        p1 = &text[0];
        p2 = &text[ptr];

        MovePen(cx, cy);
        SetEraseMode(FALSE);
        DrawTextString(text);

        Blinkit();
        break;
    }
}

void KeyboardEventProcess(int key, int event)/* ÿ������������Ϣ����Ҫִ�� */
{
    switch (event) {
    case KEY_DOWN:/* ���¼��̵���� */
        switch (key) {
        case VK_LEFT:/* ������������ */
            if (ptr) {
                ptr--;
                CleanBlink();
                p1 = &text[0];
                p2 = &text[ptr];
                Blinkit();
            }
            break;
        case VK_RIGHT:/* ���¼��Ҽ������ */
            if (ptr < textlen) {
                ptr++;
                CleanBlink();
                p1 = &text[0];
                p2 = &text[ptr];
                Blinkit();
            }
            break;
        case VK_DELETE:/* ����ɾ��������� */
            CleanBlink();

            MovePen(cx, cy);
            SetEraseMode(TRUE);
            DrawTextString(text);
            if (ptr + 1 != '\0') {
                deleteit(ptr + 1);
                textlen--;
            }
            p1 = &text[0];
            p2 = &text[ptr];
            MovePen(cx, cy);
            SetEraseMode(FALSE);
            DrawTextString(text);
            Blinkit();
            break;
        default:
            break;
        }
    }
}

/* ���ã��hȥ�ַ����е�a���ַ� */

void deleteit(int a)
{
    while (text[a - 1] != '\0') {
        text[a - 1] = text[a];
        a++;
    }
}

/* ���ã��Ѷ�����ַ������ַ��� */

void add(int a, char c)
{
    char temp = c;
    while (text[a] != '\0') {
        temp = text[a];
        text[a] = c;
        a++;
        c = temp;
    }
    text[a++] = c;
    text[a] = '\0';
}

/* ���ã������� */

void CleanBlink()
{
    cancelTimer(TIMER_BLINK200);
    SetEraseMode(TRUE);
    MovePen(textx, texty - 0.04);
    DrawLine(0.05, 8);
    SetEraseMode(FALSE);
}

void Blinkit()
{
    textx = TextStringWidth(p1) - TextStringWidth(p2);
    MovePen(textx, texty);
    startTimer(TIMER_BLINK200, mseconds200);
}

/* ���ã���ʱ����Ϣ�ص����� */

void TimerEventProcess(int timerID)
{
    bool erasemode;

    switch (timerID) {
    case TIMER_BLINK200:
        erasemode = GetEraseMode();
        MovePen(textx, texty - 0.04);/* ��ʼλ�� */
        SetEraseMode(IsBlink);
        DrawLine(0.05, 0);
        SetEraseMode(erasemode);
        IsBlink = !IsBlink;/*������ʾ/�����ַ������*/
        break;
    default:
        break;
    }
}





/* ��Ŀ5 */

#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include "linkedlist.h"
#include <math.h>

#define PI 3.1415926

linkedlistADT SnowList; /* �����������δ�Ÿ��߶εĽǶ� */
double length;          /* ��ʼ�߳���inch�� */

static void DwawPolarLine(double r, double theta); /* ���Ƽ������߶� */
static void DrawKochSnowLine(void *obj); /* ���Ƹ��߶β�Ϊ��������������ö��� */
static void SplitEdges(linkedlistADT linkedlist);/* ÿ�����ηֽ�Ϊ������ */
static void KochSnow(linkedlistADT linkedlist, int n);/* �ݹ���n��Kochѩ�����߽Ƕ� */
static void KochSnow1(linkedlistADT linkedlist, int n);/* �ǵݹ鷽����n��Kochѩ�����߽Ƕ� */

void Main() 
{
	int n;

    InitGraphics();/* ͼ�γ�ʼ�� */

	SetPenColor("Red"); /* ���û�����ɫΪ��ɫ */
    SetPenSize(1);      /* ���û��ʴ�ϸΪ1 */

	InitConsole();
	printf("Enter n: "); /* ������� */
	n = GetInteger();
	printf("Enter length: ");/* �����ʼ�߳���Ӣ�磩 */
	length = GetReal();
	FreeConsole();

    /* ���ã���ʼ�����η���ͼ�δ�������λ�ò��һ����ƶ������½Ƕ���λ�� */
	MovePen(GetWindowWidth()/2.0 - length/2.0,
            GetWindowHeight()/2 - length/2.0*tan(30.0/180.0*PI));

	length = length / pow(3.0, (float)n); /* n��ѩ�����յ��߶δ�С */

	SnowList = NewLinkedList(); /* ��ʼ������ */
	KochSnow(SnowList, n);      /* �ݹ���������n��ѩ�����߶νǶȣ������������ */
	KochSnow1(SnowList, n);      /* �ǵݹ���������n��ѩ�����߶νǶȣ������������ */
	
    TraverseLinkedList(SnowList, DrawKochSnowLine);/* �������������߶� */
    FreeLinkedList(SnowList);/* ɾ�������ͷſռ� */

}

/* ���ã����Ƽ�����ֱ�ߣ����г���r���Ƕ�theta */
static void DrawPolarLine(double r, double theta)
{
	double radians;

	radians = theta / 180 * PI;
	DrawLine(r * cos(radians), r * sin(radians));
}

/*
 * ���ã�ΪTraverseLinkedList���ú����������ƵĻ���ֱ�ߺ���
 * ------------------------------------------------------- 
 * obj�ǽǶ�ָ�룬length��ֱ�߳��ȣ�ȫ�ֱ�����
 */
static void DrawKochSnowLine(void *obj)
{
	DrawPolarLine(length, *((double *)obj));
}

/*
 * ���ã����������η���Ϊ�ı�
 * --------------------------
 * ÿ�߽Ƕ�����Ϊ��theta, theta-60, theta+60, theta
 * ���У�thetaΪԭ�ߵĽǶȣ�Ҳ����n-1�״����������ڵ��еĸ��߽Ƕ�
 */
static void SplitEdges(linkedlistADT SnowList)
{
	linkedlistADT ptr1;
	double *ptheta, theta;

	ptr1 = SnowList;   /* ����ָ�룬����ͷָ�� */
    ptr1 = NextNode(SnowList, ptr1);/* ��ͷָ�����һ����㣬����һ�����ݽ�� */
	while (ptr1 != NULL) {
		theta = *((double *)NodeObj(SnowList, ptr1)); /* �����ԭ����ŵĽǶ� */
		ptheta = GetBlock(sizeof(double));
		*ptheta = theta - 60;
        InsertNode(SnowList, ptr1, (void *)ptheta); /* ����ڶ����ǶȽ�� */
		ptr1 = NextNode(SnowList, ptr1);            /* �Ƶ��ղ���Ľ�� */
		ptheta = GetBlock(sizeof(double));
		*ptheta = theta + 60;                       
        InsertNode(SnowList, ptr1, (void *)ptheta);  /* ����������ǶȽ�� */
		ptr1 = NextNode(SnowList, ptr1);             /* �Ƶ��ղ���Ľ�� */
		ptheta = GetBlock(sizeof(double));
		*ptheta = theta;
        InsertNode(SnowList, ptr1, (void *)ptheta);  /* ������ĸ��ǶȽ�� */
		ptr1 = NextNode(SnowList, ptr1);             /* �Ƶ��ղ���Ľ�� */
		ptr1 = NextNode(SnowList, ptr1);             /* �Ƶ�ԭ���ĵڶ������ */
	}
}

/* ���ã��ݹ�����n��Kochѩ�����߽Ƕȵĺ��� */
static void KochSnow(linkedlistADT SnowList, int n)
{
	double *ptheta;

	if (n == 0) { /* 0��ѩ������ʼ�����Σ������¶˿�ʼ���߽Ƕ�����Ϊ0��120�㣬240�� */
		ptheta = GetBlock(sizeof(double));
		*ptheta = 0;
        InsertNode(SnowList, NULL, (void *)ptheta);
		ptheta = GetBlock(sizeof(double));
		*ptheta = 120;
        InsertNode(SnowList, NULL, (void *)ptheta);
		ptheta = GetBlock(sizeof(double));
		*ptheta = 240;
        InsertNode(SnowList, NULL, (void *)ptheta);
	} else {
		KochSnow(SnowList, n-1);/* ���ɵ�n-1��Kochѩ������ */
        SplitEdges(SnowList);/* ����n��ͬʱ�����߷��ѳ��ı� */
	}
}

static void KochSnow1(linkedlistADT SnowList, int n)
{
	int i;
	double *ptheta;

	if (n < 0) return; /* ������0��ѩ������ʼ�����Σ������¶˿�ʼ���߽Ƕ�����Ϊ0��120�㣬240�� */
	ptheta = GetBlock(sizeof(double));
	*ptheta = 0;
    InsertNode(SnowList, NULL, (void *)ptheta);
	ptheta = GetBlock(sizeof(double));
	*ptheta = 120;
    InsertNode(SnowList, NULL, (void *)ptheta);
	ptheta = GetBlock(sizeof(double));
	*ptheta = 240;
    InsertNode(SnowList, NULL, (void *)ptheta);/* ���ηֽ���ߣ�������ɸ߽�ѩ������ */
	for (i = 1; i <= n; i++) 
	SplitEdges(SnowList);
}

/*
 * �ļ�: linkedlist.c
 * -------------
 * ����ļ�ʵ�� the linkedlist.h .
 */

#include <stdio.h>

#include "genlib.h"
#include "linkedlist.h"

/* ������ */


/* ���ã����䲢����һ���յ����� (ֻ����һ��ͷ�ڵ�). */

linkedlistADT NewLinkedList(void)
{
    linkedlistADT head;

    head = New(linkedlistADT);
    head->dataptr = NULL;
	head->next = NULL;
    return (head);
}

/* ���ã��ͷ�����������Ĵ��� */

void FreeLinkedList(linkedlistADT head)
{
	linkedlistADT nodeptr, nextnodeptr;

	nodeptr = head;
	while (nodeptr != NULL) {
	    nextnodeptr = nodeptr->next;
		if (nodeptr != head) FreeBlock(nodeptr->dataptr);
		FreeBlock(nodeptr);
		nodeptr = nextnodeptr;
	}
}

/* ���ã������ڵ㣻�ҵ��Ļ����ؽڵ�ָ�룬���򷵻�NULL */

linkedlistADT SearchNode(linkedlistADT head, void *obj, bool (*equalfunptr)(void *obj1, void *obj2))
{
	linkedlistADT nodeptr;
	
	if (obj == NULL) return NULL;
	nodeptr = head->next;
	while (nodeptr != NULL) {
		if ((*equalfunptr)(nodeptr->dataptr, obj)) return nodeptr;
	}
	return NULL;
}

/* ���ã��ڱ����ӵ�nodeptr�ڵ�֮����������ֵ�����nodeptrΪ�գ���obj���ӵ������β�� */

void InsertNode(linkedlistADT head, linkedlistADT nodeptr, void *obj)
{
	linkedlistADT ptr;

	if (obj == NULL) return;
	if (nodeptr == NULL) { /* ��obj���ӵ�β�� */
		nodeptr = head;
		while (nodeptr->next != NULL) nodeptr = nodeptr->next;
	}
	ptr = New(linkedlistADT); /* �½ڵ����� */
	ptr->dataptr = obj;  /* ���ýڵ������ptr */
	ptr->next = nodeptr->next;
	nodeptr->next = ptr;
}

/* ���ã������obj����ɾ���ڵ㣻����ҵ��ڵ㣬�򷵻ؽڵ�ָ�룬���򷵻�NULL */

linkedlistADT DeleteNode(linkedlistADT head, void *obj, bool (*equalfunptr)(void *obj1, void *obj2))
{
	linkedlistADT nodeptr, prenodeptr;

	if (obj == NULL) return NULL;
	prenodeptr = head;
    nodeptr = head->next;
	while (nodeptr != NULL) {
		if ((*equalfunptr)(nodeptr->dataptr, obj)) break;
	    prenodeptr = nodeptr;
        nodeptr = nodeptr->next;
	}
	if (nodeptr != NULL) /* �ҵ������ */
	    prenodeptr->next = nodeptr->next;
	return nodeptr;
}

/* ���ã�����������ʹ��funptrָ��ĺ�������ڵ�ֵobj */

void TraverseLinkedList(linkedlistADT head, void (*traversefunptr)(void *obj))
{
	linkedlistADT nodeptr;

	if (traversefunptr == NULL) return;
	nodeptr = head->next;
	while (nodeptr != NULL) {
		(*traversefunptr)(nodeptr->dataptr);
		nodeptr = nodeptr->next;
	}
}

/* ���ã����������index-th�ڵ��ָ�� */

void *ithNodeobj(linkedlistADT head, int index)
{
	linkedlistADT nodeptr;
	int count = 0;

	nodeptr = head->next;
	while (nodeptr != NULL) {
		if (++count == index) break;
		nodeptr = nodeptr->next;
	}
	if (nodeptr != NULL)
        return nodeptr->dataptr;
	return NULL;
}

/* ���ã�����nodeptr����һ���ڵ��ָ�� */

linkedlistADT NextNode(linkedlistADT head, linkedlistADT nodeptr)
{
	if (nodeptr != NULL) return nodeptr->next;
	return NULL;
}

/* ���ã�����nodeptr��ָ��Ľڵ��dataptr*/

void *NodeObj(linkedlistADT head, linkedlistADT nodeptr)
{
	if (nodeptr != NULL) return nodeptr->dataptr;
	return NULL;
}
