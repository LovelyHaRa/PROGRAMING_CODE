#include <stdio.h>

int main(void)
{
	/* ����� */
	int max=0,i;
	char N[8];
	int num[10] = { 0 };
	/* �Էº� */
	scanf("%s", N);
	/* ���μ��̺� */
	i = 0;
	/* ���� ���� ī��Ʈ */
	while (N[i] != '\0')
		num[N[i++] - '0']++; 
	num[6] = (num[6] + num[9]) / 2 + (num[6] + num[9]) % 2; // 9�� ī��Ʈ�� ��� 6���� ��ȯ, �� �� ������ ������ �������� ���Ѵ�
	/* �ִ� ���� */
	for (i = 0; i < 9; i++)
		if (max < num[i]) max = num[i];
	/* ��º� */
	printf("%d\n", max);
}