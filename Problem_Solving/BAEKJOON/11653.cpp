// ���� ����
#include<iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int i = 2;
	// ���μ�����
	// i=2���� ����, n�� ������ �������� i ��� �� i�� ����
	// �׷��� ������ i 1�� ����
	// n�� ���̻� ���� �� ������(1�̵Ǹ�) ����
	while(n>1)
	{
		if (n%i == 0)
		{
			cout << i << '\n';
			n /= i;
			continue;
		}
		i++;
	}
}