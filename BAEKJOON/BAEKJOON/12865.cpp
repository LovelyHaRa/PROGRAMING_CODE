// DP ����
// ���� ����
#include<iostream>

using namespace std;

int w[101], v[101];
int dp[101][100001];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	// dp[i][j] => i��°���� Ž������ �� �� ���� ���� ���ǵ��� ���� j��� ���� �� ����ġ ��
	// i�� ���� ������ŭ, j�� ���� ��� �ִ� �ִ� ���Ը�ŭ ����
	// �賶�� ���� �ʴ� ��� : dp[i][j] = dp[i-1][j] (���� Ž���Ѱ� �״�� ������� ��)
	// �賶�� ��� ��� : dp[i][j] = dp[i-1][j-w[i]]+v[i] (j���� i�� ° ������ ���Ը� �� ���� ����)
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = dp[i-1][j];
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	// ������ �� ���
	cout << dp[n][k] << '\n';
}