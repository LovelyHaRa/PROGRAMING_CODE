// �׸��� �˰���
#include<iostream>

using namespace std;

int main(void)
{
	int n, k;
	int coin[10];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	int res = 0, index = n;
	// 1. ū ������ �������� ���������� Ž��
	// 2. �������� k���� ũ�� ���� ���� Ž��
	// 3. ������ k�� ���������� ���� ���� �����̹Ƿ� ������Ŵ
	// 4. 3���� ����� �������� k�� �ٽ� ����
	// 5. k�� 0�̵ǰų� Ž���� ������ ��� ���
	while (index--)
	{
		if (k == 0)
			break;
		else if (coin[index] > k)
			continue;
		res += k / coin[index];
		k %= coin[index];
	}
	cout << res << '\n';
}