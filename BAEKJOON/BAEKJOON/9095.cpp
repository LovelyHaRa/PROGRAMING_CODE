#include<iostream>

using namespace std;

int cnt;

// ��� ����Ž��
void func(int x, int n)
{
	// n�� ������ ī��Ʈ ���� �� ����
	if (x == n)
	{
		cnt++;
		return;
	}
	// n�� �ʰ��ϸ� ���̻� �ǹ� �����Ƿ� ����
	else if (x > n)
		return;
	func(x + 1, n); // 1�� ���غ���
	func(x + 2, n); // 2�� ���غ���
	func(x + 3, n); // 3�� ���غ���
	return;
}

int main(void)
{
	int t;
	cin >> t; // �׽�Ʈ ���̽�
	while (t--)
	{
		int n;
		cin >> n; // �Է�
		cnt = 0; // ī��Ʈ �ʱ�ȭ
		func(0, n); // ���� Ž��
		cout << cnt << '\n';
	}
}