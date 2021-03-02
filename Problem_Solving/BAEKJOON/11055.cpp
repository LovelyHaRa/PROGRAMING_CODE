#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n), cache(n); // ����, �հ��� �ִ밪�� �����ϴ� DP �迭
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cache[i] = a[i]; // �ʱⰪ: a[i]�� ���� ��
	}
	int res = 0; // �ִ밪 ����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			// ���� 1: LIS�� �����ϴ���?(a[j]<a[i])
			// ���� 2: ���� �� ū��?
			if (a[j] < a[i] && cache[i] < cache[j] + a[i])
				cache[i] = cache[j] + a[i]; // �ִ밪 ����
		res = res < cache[i] ? cache[i] : res; // ���� �� �ִ� ��� ������ �� �ִ밪 ����
	}
	cout << res << '\n';
}