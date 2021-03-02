#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> cache;
const int MOD = 10000000;

int poly(int n, int first)
{
	// ���� ���; n�� ù���� �簢�� ���� ���� ��
	if (n == first) return 1;
	// �޸������̼�
	int& ret = cache[n][first];
	if (ret != -1) return ret;
	// �ʱ�ȭ
	ret = 0;
	// ��ȭ�� ����
	for (int second = 1; second <= n - first; second++)
	{
		int add = first + second - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		cache.resize(n + 1, vector<int>(n + 1, -1));
		int sum = 0;
		// ù �ٿ� �� �� �ִ� �簢���� ������ ��� Ž��
		for (int i = 1; i <= n; i++) {
			sum += poly(n, i);
			sum %= MOD;
		}
		cout << sum << '\n';
		cache.clear();
	}
}