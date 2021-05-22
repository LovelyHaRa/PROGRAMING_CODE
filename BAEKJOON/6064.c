#include<stdio.h>

int GCD(int a, int b) // ��Ŭ���� ȣ����(���)�� �̿��� �ִ� ����� �Լ�
{
	if (a%b == 0)
		return b;
	else
		GCD(b, a%b);
}

int main(void)
{
	int T; // TestCase
	int M, N, x, y; // input data
	int i; // �ݺ��� ����
	int answer,gcd; // ���
	scanf("%d", &T);
	for (i = 0; i < T; i++) // �׽�Ʈ ���̽���ŭ �ݺ�
	{
		scanf("%d %d %d %d", &M, &N, &x, &y); // input
		answer = -1; // �ذ� ���� ��� -1 ���
		gcd = M > N ? GCD(M, N) : GCD(N, M); // �ִ����� ���ϱ�
		while (x <= (M*N) / gcd || y <= (M*N) / gcd)  // M, N�� �ּ� ������� ī�� �޷� ���� ����
		{
			if (x == y)
			{
				answer = x; // x=y�� ��, x���� ��
				break;
			}
			// x, y �� ���� ���� M, N�� ����
			if (x < y) x += M;
			else y += N;
		}
		printf("%d\n", answer); // ��� ���
	}
}