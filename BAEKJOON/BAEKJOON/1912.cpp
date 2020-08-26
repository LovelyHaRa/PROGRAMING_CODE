#include<iostream>
#include<algorithm>

using namespace std;

int num[100000];
int dp[100000];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int res;
	res = dp[0] = num[0];
	/*
	  - ��ȭ��
	  dp[i]=max(dp[i-1]+num[i] ,num[i])
	  ���������� ���õ� ���� ���� ���� ���� �Ͱ� ���� ���� ū ���� ����
	*/
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		res = res < dp[i] ? dp[i] : res;
	}
	cout << res << endl;
}