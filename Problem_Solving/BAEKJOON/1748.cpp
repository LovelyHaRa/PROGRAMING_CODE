#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int res = 0; // ���
	int cnt = 1, div = 10; // �ڸ� ����, ���� ��
	// 1. 1���� n���� Ž��
	for (int i=1;i<=n;i++)
	{
		// 2. ���� ���� 0���� ���������� �ڸ����� �������� �ǹ�
		if (i%div == 0)
		{
			div *= 10; // �ڸ��� ���� ����
			cnt++; // �ڸ��� ����
		}
		// 3. �ڸ��� ����
		res += cnt;
	}
	cout << res; // ��� ���
}