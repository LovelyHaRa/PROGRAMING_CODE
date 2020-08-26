#include<iostream>

using namespace std;

const long long DIV = 1000000000; // ������ ��

int main(void)
{
	int n; // �ڸ���
	long long dp[100][10] = { 0 }, sum = 0; // ���� ��ȹ �迭, �����
	cin >> n;
	/*
	���̰� N�� ��� ���� 0~9�߿� �� �� �ִ� �ڸ����� ����
	�ڸ����� n, ���ڸ��� d��� �ϸ�
	��ȭ���� ������ ����
	f(n,d)={
			f(n-1,1) (n=0)
			f(n-1,d-1)+f(n-1,d+1) (n>=1 && n<=8)
			f(n-1,8) (n=9)
			}
	*/
	// �ʱ� dp ����
	for (int i = 1; i < 10; i++)
		dp[0][i] = 1;
	// ���̰� n�϶����� ��ȭ���� ���� ���
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][1] % DIV; // d=0
		for (int j = 1; j < 9; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % DIV; // d>=1 && d<=8
		dp[i][9] = dp[i - 1][8] % DIV; // d=9
	}
	// ����� n��° �ڸ��� 0~9��° ��� ���� ��� ���� ��
	for (int i = 0; i < 10; i++)
		sum += dp[n - 1][i];
	cout << sum % DIV << endl;
}