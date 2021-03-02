#include<iostream>
#include<vector>

using namespace std;

const int N = 100000;
const int MOD = 1000000009;

int main(void)
{	
	// �̸� ���� ���� ���´�(ĳ��)
	// cache[n][k] => n�� ���� ǥ������ �� ������ ���� k�� ����� ��
	vector<vector<long long>> cache(N + 1, vector<long long>(4));
	// 1�� ���: 1 , 2�� ���: 2, 3�� ���: 1+2, 2+1, 3
	cache[1][1] = cache[2][2] = cache[3][1] = cache[3][2] = cache[3][3] = 1;
	for (int i = 4; i <= N; i++)
	{
		// ��ȭ��
		if (i - 1 >= 0)
			cache[i][1] = (cache[i - 1][2] + cache[i - 1][3]) % MOD;
		if (i - 2 >= 0)
			cache[i][2] = (cache[i - 2][1] + cache[i - 2][3]) % MOD;
		if (i - 3 >= 0)
			cache[i][3] = (cache[i - 3][1] + cache[i - 3][2]) % MOD;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << (cache[n][1] + cache[n][2] + cache[n][3]) % MOD << '\n';
	}
}