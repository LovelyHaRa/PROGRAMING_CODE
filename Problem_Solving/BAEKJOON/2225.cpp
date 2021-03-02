#include<iostream>
#include<vector>

using namespace std;

int n, k;
vector<vector<long long>> cache(201, vector<long long>(201,-1));

// �־��� �� k���� n�� ǥ���� �� �ִ� ����� ���� ��ȯ
int decomposition(int k, int n)
{
	// ���� ���: k==1 �̸� 1���� ���̴�
	if (k == 1) return 1;
	// �޸������̼�
	long long& ret = cache[k][n];
	if (ret != -1) return ret;
	ret = 0; // �ʱⰪ
	// ��ȭ��: decomposition(k,n) = sigma(i:0~n)[decomposition(k-1,i)]
	for (int i = 0; i <= n; i++)
		ret = (ret + decomposition(k - 1, i)) % 1000000000;
	return ret;
}

int main(void)
{
	cin >> n >> k;
	cout << decomposition(k, n);
}