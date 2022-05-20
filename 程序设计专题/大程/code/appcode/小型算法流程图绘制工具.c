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

#include "imgui.h"
#include "x.h" 

// ����������provided in libgraphics
void DisplayClear(void); 

// �˵���ʾ����
void drawMenu(void);

void drawEditText(void);

// �û�����ʾ����
void display(void);

// �û����ַ��¼���Ӧ����
void CharEventProcess(char c);

void TimerEventProcess(int timerID);

// �û��ļ����¼���Ӧ����
void KeyboardEventProcess(int key, int event);

// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event);

// �û����������
// ����ʼ��ִ��һ��
void Main() 
{
	// ��ʼ�����ں�ͼ��ϵͳ
	SetWindowTitle("");
	
    InitGraphics();
    
    int i;
    
    SetPenColor("Red"); 
    SetPenSize(1);
    
	// ��ô��ڳߴ�
    winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	// ע��ʱ����Ӧ����
	registerCharEvent(CharEventProcess);        // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
	registerTimerEvent(TimerEventProcess);
	// �򿪿���̨��������printf/scanf���/�������Ϣ���������
	// InitConsole(); 
	for (i = 0; i < NLIST; i++) list[i] = Newlink();
}
