#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int abs(int a) { return a < 0 ? -a : a; }

int main(void)
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// �������� ����
	sort(a.begin(), a.end());
	int res = 0;
	// ���� ����Ž���� �̿��ؼ� ��� ����� ���� �����Ѵ�
	do
	{
		int sum = 0;
		for (int i = 1; i < n; i++)
			sum += abs(a[i - 1] - a[i]); // ������ ������ ����
		res = res < sum ? sum : res; // �ִ밪 ����
	} while (next_permutation(a.begin(), a.end()));
	cout << res << '\n';
}