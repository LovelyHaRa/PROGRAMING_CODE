#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> dp(n + 1); // dp[n]: n�� �� �ּ� ���� �� ����
	// ������ ����, dp[0]=0
	dp[1] = 1;
	// 2���� n���� ���� ���ؼ� �ּ� ���� �� ������ ����Ѵ�
	for (int i = 2; i <= n; i++)
	{
		int min_cnt = 5; // �ִ밪: 4
		// j�� ���� ���� i ������ �� ���� �ݺ�
		for (int j = 1; j * j <= i; j++)
		{
			int k = i - j * j; // i���� ���� �� ��ŭ ����
			min_cnt = min(min_cnt, dp[k]); // �޸������̼ǵ� ���� ���ؼ� �ּҰ��� �����Ѵ�
		}
		dp[i] = min_cnt + 1; // ���� �� �ϳ��� �߰��Ǿ����Ƿ� 1�� �����ش�
	}
	cout << dp[n] << '\n'; // dp[n]�� ����Ѵ�
}