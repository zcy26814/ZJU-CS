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

void Help(bool k){
	if(k==1){
    MovePen(0.2,6);
	DrawTextString("HELLO_������С���㷨����ͼ���ƹ��ߵ�ʹ��˵��^ ^");
	MovePen(0.2,5.5);
	DrawTextString("�ٻ�ͼ״̬�µ�������Ҽ��˳���ɸı�ͼ������/�˳���ͼ״̬");
	MovePen(0.2,5);
	DrawTextString("���ڻ�ͼǰѡ����ɫ/���״������ʹ�û�ͼ���߿ɸı�ͼ�ε�����");
	MovePen(0.2,4.5);
	DrawTextString("�ۻ�ͼ״̬�¿ɰ���Ctrl+Y�����ߴ�/Ctrl+Z��С�ߴ�");
	MovePen(0.2,4);
	DrawTextString("��ѡ��״̬�¿����϶�����ƶ�ͼ�Σ�ѡ��״̬ͬ����Ҫ��������Ҽ��˳�");
	MovePen(0.2,3.5);
	DrawTextString("�ݻ���ͼ�κ�ѡ�и�ͼ�ο�ֱ����������");
	MovePen(0.2,3);
	DrawTextString("�ޱ���/�򿪵���File->Save/File->Open��Ctrl+S/Ctrl+O,����File->New��Ctrl+N�������Ļ");
	MovePen(0.2,2.5);
	DrawTextString("���˳�ѡ��״̬�󵥻�Edit->Copy/Ctrl+C�ɶ��˳�ѡ��״̬ǰ�����һ��ͼ�ν��и���");
	MovePen(0.2,2);
	DrawTextString("����и��ƺ�Ctrl+V/����Edit->Paste�ɽ���ճ��");
	MovePen(0.2,1.5);
	DrawTextString("��ѡ�к���̰���Delete/Ctrl+D��ɾ��ͼ��");
	MovePen(0.2,1);
	DrawTextString("���ٴε���Help - usage method�˳�ʹ��˵��");
}
}
