#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache(1001, -1);

int tiling(int n)
{
	if (n <= 1) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	// Ÿ�ϸ��̶� ��������� 2*2 Ÿ���� �߰��Ǿ��� ������ *2 ����� �Ѵ�.
	return ret = (tiling(n - 1) + tiling(n - 2) * 2) % 10007;
}

int main(void)
{
	cin >> n;
	cout << tiling(n);
}