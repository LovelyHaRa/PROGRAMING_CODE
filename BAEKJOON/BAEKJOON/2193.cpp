#include<iostream>
#include<vector>

using namespace std;

vector<long long> cache;

// ��Ģ ��� �Ǻ���ġ �������� �˰� ��
long long f(int k)
{
	// ���� ���
	if (k < 0) return 0;
	if (k <= 1) return k;
	// �޸������̼�
	long long& ret = cache[k];
	if (ret != -1) return ret;
	// ��ȭ�� = f(n)=f(n-1)+f(n-2)
	return ret = f(k - 1) + f(k - 2);
}

int main(void)
{
	int n;
	cin >> n;
	cache.resize(n + 1, -1);
	cout << f(n);
}