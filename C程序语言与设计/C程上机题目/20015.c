#include <stdio.h>
int main(void)
{
	int n, digit1, digit2, digit3;

		/*---------*/
	n = 152;
	digit1 = n % 10;
	digit2 = (n - digit1) / 10 % 10;
	digit3 = (n - digit1 - 10 * digit2) / 100 % 10;
	printf("����%d�ĸ�λ������%d, ʮλ������%d, ��λ������%d\n", n, digit1, digit2, digit3);
	return 0;
}

