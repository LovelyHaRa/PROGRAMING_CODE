#include<iostream>
#include<vector>

using namespace std;

vector<int> cache;

// 3*n ���簢���� Ÿ���� ä�� �� �ִ� ����� ��
int tiling(int n)
{
	// �������: Ȧ���� Ÿ���� ä�� �� ����
	if (n % 2) return 0;
	// �������: n==0 -> 1
	if (n == 0) return 1;
	// ������� : n==2�� �� ����� ���� 3
	if (n == 2) return 3;
	// �޸������̼�
	int& ret = cache[n];
	if (ret != -1) return ret;
	// tiling(n-2)*3�� ����Ǽ�
	ret = 3 * tiling(n - 2);
	// Ư���� ����� �߰�(n==4���� 2���� ����)
	for (int i = 0; i <= n - 4; i += 2)
		ret += 2 * tiling(i);
	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	cache.resize(n + 1, -1);
	cout << tiling(n) << '\n';
}