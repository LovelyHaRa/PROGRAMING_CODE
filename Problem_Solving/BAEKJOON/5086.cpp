// ���� ����
#include<cstdio>

using namespace std;

int main(void)
{
	int a, b;
	while (1)
	{
		scanf("%d %d", &a, &b);
		// ū ���� �������� ������ �������� ����ų� ����̴�.
		// ��� : a < b �� ���
		// ��� : a > b �� ���
		if (!a && !b)
			break;
		if (a > b)
			a % b ? printf("neither\n") : printf("multiple\n");
		else
			b % a ? printf("neither\n") : printf("factor\n");
	}
}