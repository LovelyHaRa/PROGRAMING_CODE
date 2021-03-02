// DP ����
// LIS ���� ����
#include<iostream>
#define N 1001

using namespace std;

int main(void)
{
	int a[N];
	int dp[2][N] = { 0 };
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int count, max = 0;
	// ���� ���� �߿��� ���� ��ġ���� ���� ���� üũ
	// üũ�� ���� �� DP ���� ���� ū �� + 1�� ���� ��ġ DP���� ����
	for (int i = 1; i <= n; i++)
	{
		count = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				if (count < dp[0][j])
					count = dp[0][j];
			}
		}
		dp[0][i] = count + 1;
	}
	// �������� �� �۾� �ݺ�
	dp[1][n - 1] = 1;
	for (int i = n; i >= 1; i--)
	{
		count = 0;
		for (int j = n; j > i; j--)
		{
			if (a[i] > a[j])
			{
				if (count < dp[1][j])
					count = dp[1][j];
			}
		}
		dp[1][i] = count + 1;
	}
	// �ΰ��� dp�迭�� ���� ���� �ִ밪 -1 �� ����
	for (int i = 1; i <= n; i++)
	{
		int sum = dp[0][i] + dp[1][i];
		max = max < sum ? sum : max;
	}
	cout << max - 1 << '\n';
}