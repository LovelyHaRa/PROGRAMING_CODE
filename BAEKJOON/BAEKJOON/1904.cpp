// ��ȭ���� �̿��� DP����

#include<iostream>

using namespace std;

int dp[1000001]; // dp �迭

int main(void)
{
	int N;	
	cin >> N;
	// ������ ���踦 ���Ͽ� ��ȭ���� ������ ���
	// dp[N]=dp[N-1]+dp[N-2]
	// (dp[N] => N�ڸ����� ���� ������ �� �ִ� ������ ����)
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}
	cout << dp[N]<<'\n';
}