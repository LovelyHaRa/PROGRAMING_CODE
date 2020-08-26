#include<iostream>
#include<vector>

using namespace std;

const int N = 100000, mod = 9901;
vector<vector<int>> cache(N + 1, vector<int>(3, -1));

// n��° �ٿ� k��Ȳ�� ���� ����Ǽ�
int zoo(int n, int k)
{
	// �������: n==1
	if (n == 1) return 1;
	// �޸������̼�
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	// 0: ���� �ٿ� ��ġ ���� ��, 1: ���ʿ� ��ġ�� ��, 2: �����ʿ� ��ġ�� ��
	switch (k)
	{
	case 0: return ret = (zoo(n - 1, 0) + zoo(n - 1, 1) + zoo(n - 1, 2)) % mod; // ���� ���� ����+������+��ġ���ϴ°��
	case 1: return ret = (zoo(n - 1, 0) + zoo(n - 1, 2)) % mod; // ���� ���� ������+��ġ���ϴ°��
	case 2: return ret = (zoo(n - 1, 0) + zoo(n - 1, 1)) % mod; // ���� ���� ����+��ġ���ϴ°��
	}
}

int main(void)
{
	int n;
	cin >> n;
	cout << (zoo(n, 0) + zoo(n, 1) + zoo(n, 2)) % mod << '\n';
}