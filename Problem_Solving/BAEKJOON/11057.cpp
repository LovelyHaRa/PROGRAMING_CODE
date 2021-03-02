#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> cache;

const int mod = 10007;

// n��° ��ġ�� k�� �� �� �ִ� ����� �� ��ȯ
int solve(int n, int k)
{
	// ���� ���: n�� 1�ڸ��� �� ����� ���� 1��
	if (n == 1) return 1;
	// �޸������̼�
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	ret = 0; // �ʱ⼼��
	// n-1 ��ġ�� �� �� �ִ� ���� ���� ������ ���ų� �۾ƾ� �Ѵ�.
	// ���� solve(n-1, k~9)������ ����� ���� ��� ���Ѵ�
	for (int i = k; i <= 9; i++)
		ret = (ret + solve(n - 1, i)) % mod; // �������� �������� ����
	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	cache.resize(n + 1, vector<int>(10, -1));
	int res = 0;
	for (int i = 0; i <= 9; i++)
		res = (res + solve(n, i)) % mod; // �������� �������� ����
	cout << res << '\n';
}