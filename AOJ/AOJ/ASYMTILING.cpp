#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache;
const int MOD = 1000000007;

// Ÿ�ϸ� ����� ��
int tiling(int width)
{
	if (width <= 1) return 1;
	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}

// ��ü ����Ǽ� - ��Ī ����� �� �� ���ϱ�
int asymmetric(int width)
{
	// �� ����� ���� �� �� �ֱ� ������ �������� ���� �� �� MOD ����
	// 1. �ʺ� Ȧ���� ���: ���� Ÿ�ϸ��� ���� ����(�ڿ������� ������ ������ ��Ī)
	if (width % 2 == 1)
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	// 2. ¦���� ���� �ΰ��� ��찡 �����Ƿ� ��� �� �ش�
	int ret = tiling(width);
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD; // ���� Ÿ���� �ΰ� �ִ� ���
	ret = (ret - tiling(width / 2) + MOD) % MOD; // Ÿ���� ���� ���
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		cache.resize(n + 1, -1);
		cout << asymmetric(n) << '\n';
		cache.clear();
	}
}