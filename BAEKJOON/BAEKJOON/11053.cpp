// DP ����
// LIS ����
#include<iostream>
#define N 1001

using namespace std;

int main(void)
{
	int a[N];
	int dp[N] = { 0 };
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int count, max = 0;
	// ���� ���� �߿��� ���� ��ġ���� ���� ���� üũ
	// üũ�� ���� �� DP ���� ���� ū �� + 1�� ���� ��ġ DP���� ����
	// DP�� �ִ밪 ���
	for (int i = 1; i <= n; i++)
	{
		count = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				if (count < dp[j])
					count = dp[j];
			}
		}
		dp[i] = count + 1;
		max = max < dp[i] ? dp[i] : max;
	}
	cout << max << '\n';
}