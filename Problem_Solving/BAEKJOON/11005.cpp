#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int n, b;
	cin >> n >> b;
	string res;
	while (n)
	{
		// 1. ������ ���� ������ ����
		int k = n % b;
		// 2. �������� 10�̻��̸� ���ĺ� ����
		if (k >= 10)
			res += k - 10 + 'A';
		// 3. �׷��� ������ ���� ����
		else
			res += k + '0';
		// 4. ������ ������
		n /= b;
	}
	// ���� ���
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];
}