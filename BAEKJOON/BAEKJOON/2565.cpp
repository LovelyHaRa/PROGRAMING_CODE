// DP ����
// LIS ���빮��
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	vector<vector<int>>a;
	int dp[101] = { 0 };
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		a[i].resize(2);
		cin >> a[i][0] >> a[i][1];
	}
	// 1. ù��° �� �������� ����
	sort(a.begin(), a.end());
	int max = 0;
	// 2. ���ĵ� ������ �ι�°���� LIS ����
	// �������� ��ġ�� �������� ������ ���������� �����ؾ��Ѵ�
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[i][1] > a[j][1])
			{
				if (count < dp[j + 1])
					count = dp[j + 1];
			}
		}
		dp[i+1] = count + 1;
		max = max < dp[i + 1] ? dp[i + 1] : max;
	}
	cout << n - max << '\n';
}