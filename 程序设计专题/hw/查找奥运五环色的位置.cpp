#include<stdio.h>
#include<string.h>
int main(void)
{   char *color[5] = {"red", "blue", "yellow", "green", "black"}; 
    char **pc;  /* �������ָ����� */
    char str[20];  int i;
    pc = color;   /* ����ָ�븳ֵ */
    scanf("%s", str);
    for(i = 0; i < 5; i++)  
       if(strcmp(str, *(pc+i)) == 0)  /* �Ƚ���ɫ�Ƿ���ͬ */
            break;
    if(i < 5)
        printf("%d\n", i+1);
    else
        printf("Not Found\n");    
    return 0;
}
