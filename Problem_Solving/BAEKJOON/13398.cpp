#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<int>> cache(2, vector<int>(n, 0));
	int res;
	res = cache[0][0] = cache[1][0] = a[0];
	for (int i = 1; i < n; i++)
	{
		// 0���� a[i]�� �������� ���� �������� �ִ��� ����
		cache[0][i] = max(cache[0][i - 1] + a[i], a[i]);
		// 1���� a[i]�� �������� �ʾ��� �� �������� �ִ밪�� ����
		// cache[1][i-1]�� 0~i-1 �� �ϳ��� ���� ���Ե��� �ʾұ� ������ a[i]�� �ݵ�� �����ؾ���
		cache[1][i] = max(cache[0][i - 1], cache[1][i - 1] + a[i]);
		res = max(res, max(cache[0][i], cache[1][i]));
	}
	cout << res << '\n';
}