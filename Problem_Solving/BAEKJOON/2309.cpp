#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int a[9];
	int sum = 0;
	// 1. �Է°� ���ÿ� �� �հ� ���ϱ�
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		sum += a[i];
	}	
	int flag = 0; // Ż�� �÷���
	// 2. ����-������ �μ��� ��==100 �̸� ���� ����
	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1;j < 9; j++)
		{
			if (sum - a[i] - a[j] == 100)
			{
				flag = 1; // Ż�� �÷���
				a[i] = a[j] = -1; // ���Ľ� �� �տ� �α� ����
				break;
			}
		}
		// �÷��� �˻�
		if (flag)
			break;
	}
	// 3. ����
	sort(a, a + 9);
	// 4. ���� �� ���� ���ܽ�Ų ä�� ���(-1�� ����)
	for (int i = 2; i < 9; i++)
		cout << a[i] << '\n';
	
}