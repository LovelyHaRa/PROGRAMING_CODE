#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int a, b, m;
	cin >> a >> b >> m;
	vector<int> k(m);
	for (int i = 0; i < m; i++)
		cin >> k[i];
	int res = 0;
	int t = 1;
	// 1. �־��� ���� 10������ ��ȯ
	for (int i = k.size() - 1; i >= 0; i--)
	{
		res += t * k[i];
		t *= a;
	}
	// 2. 10������ ��ȯ�� ���� B������ ��ȯ
	vector<int> kk;
	while (res > 0)
	{
		kk.push_back(res%b);
		res /= b;
	}
	// 3. ���
	for (auto it = kk.rbegin(); it != kk.rend(); it++)
		cout << *it << ' ';
}