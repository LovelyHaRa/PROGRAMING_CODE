#include<iostream>

using namespace std;

void f(int n)
{
	// 1. 0�̸� ����
	if (!n) return;
	// 2. n�� ¦���̸�
	if (-(n % 2) == 0)
	{
		// -(n/2) ���� ��� ȣ��
		f(-(n / 2));
		cout << '0'; // �������� ����ϱ� ����
	}
	// 3. n�� Ȧ���̸�
	else
	{
		// ����̸� -(n/2) ���� ��� ȣ��
		if (n > 0)
			f(-(n / 2));
		// �����̸� (-n+1) /2 ���� ��� ȣ��
		else
			f((-n + 1) / 2);
		cout << '1'; // �������� ����ϱ� ����
	}
}

int main(void)
{
	int n;
	cin >> n;
	if (!n) cout << 0;
	else f(n);
}