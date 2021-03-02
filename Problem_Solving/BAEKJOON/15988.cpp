#include<iostream>
#include<vector>

using namespace std;
const int N = 1000000;
const int mod = 1e9 + 9;
vector<long long> cache(N + 1, -1);

// n�� 1,2,3�� ������ ��Ÿ���� ����� ��
long long sum(int n)
{
	// �������: n<=0
	if (n <= 0) return 0;
	// �޸������̼�
	long long& ret = cache[n];
	if (ret != -1) return ret;
	// ��ȭ��
	return ret = (sum(n - 1) + sum(n - 2) + sum(n - 3)) % mod;
}

int main(void)
{
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;
	// ��� ��츦 �̸� ���(��� ���� ������ �̸� ���)
	for (int i = 4; i <= N; i++)
		sum(i);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout<<sum(n)<<'\n'; // ���� ���ؼ� Ʋ��,,,
	}
}