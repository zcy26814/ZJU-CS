#ifndef _chart_h
#define _chart_h

#define NLIST                 8
#define Rectangle             0
#define Roundedrectangle      1
#define Rhombus               2
#define CenteredEllipse       3
#define Arrow                 4
#define Line                  5
#define Parallelogram         6
#define Text                  7
#define PI                    3.1415926
#define TIMER_BLINK500        1     //500ms��ʱ���¼���־��

typedef struct {//��������
	double x1, y1;//���½�����
    double x2, y2;//���Ͻ�����
    int PenSize; //��ϸ
    int color; //��ɫ
    bool isSelected; //ѡ��
    bool isfilling; //���
    char memo[80];
	int num1;
	int num2; 
	double fillpercent;
}Rect,*Rec;

typedef struct {//Բ�Ǿ�������
	double x1,y1;//���½�����
	double x2,y2;//���Ͻ�����
	int PenSize;//��ϸ
	int color;//��ɫ
	bool isSelected;//ѡ��
	bool isfilling;//���
	char memo[80];
	int num1;
	int num2; 
	double fillpercent;
}Roun,*Rou;

typedef struct {//�������� 
	double x1,y1;//���½�����
	double x2,y2;//���Ͻ�����
	int PenSize;//��ϸ
	int color;//��ɫ
	bool isSelected;//ѡ��
	bool isfilling;//���
	char memo[80];
	int num1;
	int num2; 
	double fillpercent;
}Rhom,*Rho;

typedef struct {//��Բ���� 
	double x1,y1;//���½�����
	double x2,y2;//���Ͻ�����
	int PenSize;//��ϸ
	int color;//��ɫ
	bool isSelected;//ѡ��
	bool isfilling;//���
	char memo[80];
	int num1;
	int num2; 
	double fillpercent;
}Cent,*Cen;

typedef struct {//��ͷ���� 
	double x1,y1;//���½�����
	double x2,y2;//���Ͻ�����
	int PenSize;//��ϸ
	int color;//��ɫ
	bool isSelected;//ѡ��
	bool isfilling;//���
}Arro,*Arr;

typedef struct {//ֱ������ 
	double x1,y1;//���½�����
	double x2,y2;//���Ͻ�����
	int PenSize;//��ϸ
	int color;//��ɫ
	bool isSelected;//ѡ��
	bool isfilling;//���
}Line1,*Lin;

typedef struct {//ƽ���ı������� 
	double x1,y1;//���½�����
	double x2,y2;//���Ͻ�����
	int PenSize;//��ϸ
	int color;//��ɫ
	bool isSelected;//ѡ��
	bool isfilling;//���
	char memo[80];
	int num1;
	int num2; 
	double fillpercent;
}Para,*Par;

typedef struct {//�ı������� 
	double x1,y1;//���½�����
	double x2,y2;//���Ͻ�����
	int PenSize;//��ϸ
	int color;//��ɫ
	bool isSelected;//ѡ��
	bool isfilling;//���
	char memo[80];//�ı� 
	int num1;//�ı���ǰ����λ�� 
	int num2;//�ı�����
}Text1,*Tex;

typedef struct linklist//���� 
{
	void *dataptr;//ͼ������ 
	struct linklist *next;//��һ��ָ�� 
}linklist;

Rec a1 = NULL;
Rou b1 = NULL;
Rho c1 = NULL;
Cen d1 = NULL;
Arr e1 = NULL;
Lin f1 = NULL;
Par g1 = NULL;
Tex h2 = NULL;
bool usage = FALSE;//�������� 
int isColor=3;//��ͼ��ɫ 
int IsPenSize;//�ʻ���ϸ 
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8;//�ļ�ָ�� 
FILE *fo1,*fo2,*fo3,*fo4,*fo5,*fo6,*fo7,*fo8;//�ļ�ָ�� 
int curList1 = NLIST;//��ǰѡ�е�ͼ������ 
bool isFill = FALSE; //�Ƿ���� 
double fillpercent = 1; //���̶� 
FILE *fp;//�ļ�ָ�� 
char text1[80];//���λ��
char rect1[80];
char rhom1[80];
char cent1[80];
char para1[80];
char roun1[80];
const int mseconds500 = 250;//��ʱ����ʱʱ�� 
bool isDisplayChar = TRUE;//�������� 
bool ismove = FALSE;//�ƶ����� 
bool ischange = FALSE;//���ſ��� 
bool isSelected = FALSE;//ѡ�й��ܿ��� 
bool isSelected1 = FALSE;//ѡ�п��� 
int curList = NLIST;//��ǰѡ�е�ͼ������ 
bool isRectangle = FALSE;//���ƾ��ο��� 
bool isRoundedrectangle = FALSE;//����Բ�Ǿ��ο��� 
bool isRhombus = FALSE;//�������ο��� 
bool isCenteredEllipse = FALSE;//������Բ���� 
bool isArrow = FALSE;//���Ƽ�ͷ���� 
bool isLine = FALSE;//����ֱ�߿��� 
bool isParallelogram = FALSE;//����ƽ���ı��ο��� 
bool isText = FALSE;//�����ı����� 
bool isclick = FALSE;//��ͼ���� 
bool isclick1 = FALSE;//��ͼ���ܿ��� 
bool isclick2 = FALSE;//�˵�ѡ�п��� 
linklist *list[NLIST]={NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};//ͼ������ͷָ������ 
double mindist[NLIST]={1000000000.0, 1000000000.0, 1000000000.0, 1000000000.0, 1000000000.0, 1000000000.0, 1000000000.0, 1000000000.0};//�����ͼ��������� 
Rec curRectangle = NULL;//ѡ�о���ָ�� 
Rou curRoundedrectangle = NULL;//ѡ��Բ�Ǿ���ָ�� 
Rho curRhombus = NULL;//ѡ��ƽ���ı���ָ�� 
Cen curCenteredEllipse = NULL;//ѡ����Բָ�� 
Arr curArrow = NULL;//ѡ�м�ͷָ�� 
Lin curLine = NULL;//ѡ��ֱ��ָ�� 
Par curParallelogram = NULL;//ѡ��ƽ���ı���ָ�� 
Tex curText = NULL;//ѡ���ı�ָ�� 

void DefineColor(string name,double red, double green, double blue);

//�½����� 
linklist *Newlink(void);

//ɾ������ 
void Deletelink(void);

//������ 
void Insert(linklist* head, linklist* p, void *q);

//������������ͼ�� 
void travellink(linklist* head, void (*traveler)(void *p));

//����������������ͼ�� 
void travel(void);

//���ƾ��� 
void DrawRectangle(void *p);

//����Բ�Ǿ��� 
void DrawRoundedrectangle(void *p);

//�������� 
void DrawRhombus(void *p);

//������Բ 
void DrawCenteredEllipse(void *p);

//���Ƽ�ͷ 
void DrawArrow(void *p);

//����ֱ�� 
void DrawLine1(void *p);

//����ƽ���ı��� 
void DrawParallelogram(void *p);

//�����ı� 
void DrawText1(void *p);

//������һ����� 
linklist *Next(linklist *p);

//��ȡ��ǰ�������� 
void *Node(linklist *p);

//������������֮��ľ��� 
double distRectangle(double x, double y, Rec a);

//������Ӧ��Χ 
double RecRage(Rec a);

//���������Բ�Ǿ���֮��ľ��� 
double distRoundedrectangle(double x, double y, Rou a);

//Բ�Ǿ�����Ӧ��Χ 
double RouRange(Rou a);

//�������������֮��ľ��� 
double distRhombus(double x, double y, Rho a);

//������Ӧ��Χ 
double RhoRange(Rho a);

//�����������Բ֮��ľ��� 
double distCenteredEllipse(double x, double y, Cen a);

//��Բ��Ӧ��Χ 
double CenRange(Cen a);

//����������ͷ֮��ľ��� 
double distArrow(double x, double y, Arr a);

//��ͷ��Ӧ��Χ 
double ArrRange(Arr a);

//���������ֱ��֮��ľ��� 
double distLine(double x, double y, Lin a);

//ֱ����Ӧ��Χ 
double LinRange(Lin a);

//���������ƽ���ı���֮��ľ��� 
double distParallelogram(double x, double y, Par a);

//ƽ���ı�����Ӧ��Χ 
double ParRange(Par a);

//����������ı���֮��ľ��� 
double distText(double x, double y, Tex a);

//�ı�����Ӧ��Χ 
double TexRange(Tex a);

//��������ľ��� 
Rec Selectnearest1(linklist *list, double mx, double my);

//���������Բ�Ǿ��� 
Rou Selectnearest2(linklist *list, double mx, double my);

//������������� 
Rho Selectnearest3(linklist *list, double mx, double my);

//�����������Բ 
Cen Selectnearest4(linklist *list, double mx, double my);

//��������ļ�ͷ 
Arr Selectnearest5(linklist *list, double mx, double my);

//���������ֱ�� 
Lin Selectnearest6(linklist *list, double mx, double my);

//���������ƽ���ı��� 
Par Selectnearest7(linklist *list, double mx, double my);

//���������ͼ�� 
void Picknearest(linklist *list[], double omx, double omy);

//ʹ��˵����ʾ 
void Help();

#endif
