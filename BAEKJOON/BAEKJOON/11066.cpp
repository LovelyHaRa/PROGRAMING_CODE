#include<iostream>
#include<algorithm>

using namespace std;

int novel[501]; // ������ ũ��
int sum[501]; // 1~k������ ��
int dp[501][501]; // ���� ��ȹ �迭

int main(void)
{
	int t, k;
	cin >> t;
	while (t--)
	{
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> novel[i];
			sum[i] = sum[i - 1] + novel[i]; // �� ����
		}

		/*
		  - ��ȭ��
		  dp[i][i]=novel[i], dp[i][i+1]=novel[i]+novel[i+1]
		  dp[i][j]=min(i<=mid<j){dp[i][j], dp[i][mid] + dp[mid+1][j] + sum[j] - sum[i-1](i���� j������ �κ���)}
		  - ���� for�� ����
		*/
		for (int r = 1; r < k; r++)
		{
			for (int i = 1; i + r <= k; i++)
			{
				int j = i + r;
				dp[i][j] = 987654321;
				
				for (int mid = i; mid < j; mid++)
					dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
			}
		}
		// ��� �������� ���ľ� �ϹǷ� dp[1][k]�� ���� ���
		cout << dp[1][k] << endl;
	}
}