#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache;

int tiling(int n)
{
	// ���� ���: 1, 2�� ����� ���� 1�����̴�.
	if (n <= 1) return 1;
	// �޸������̼�
	int& ret = cache[n];
	if (ret != -1) return ret;
	// ����Ÿ�� 1���� ���� ���� ����Ÿ�� 2���� ���� ��츦 ����
	return ret = (tiling(n - 1) + tiling(n - 2)) % 1000000007;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		cache.resize(n + 1, -1);
		cout << tiling(n) << '\n';
		cache.clear();
	}
}