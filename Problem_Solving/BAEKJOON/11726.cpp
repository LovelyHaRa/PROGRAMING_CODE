#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache(1001, -1);

int tiling(int n)
{
	// ���� ��� : 1, 2�� ���� ����� ���� 1��
	if (n <= 1) return 1;
	// �޸������̼�
	int& ret = cache[n];
	if (ret != -1) return ret;
	// ���� Ÿ�� �ϳ��� ���� ���� ����Ÿ�� �ΰ��� ���� ��츦 ��� ����;
	return ret = (tiling(n - 1) + tiling(n - 2)) % 10007;
}

int main(void)
{
	cin >> n;
	cout << tiling(n);
}