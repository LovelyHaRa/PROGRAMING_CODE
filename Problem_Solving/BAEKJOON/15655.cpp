#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	do
	{
		vector<int> t; // �ӽ� ����
		t.push_back(a[0]);
		int i;
		// m����ŭ �߰�
		for (i = 1; i < m; i++)
		{
			// ���������� �����ϸ� ����
			if (t.back() < a[i])
				t.push_back(a[i]);
			else
				break;
		}
		// �ݺ����� ������ ����Ǹ� ������ ������ ����
		if (i == m)
		{
			for (int i = 0; i < t.size(); i++)
				cout << t[i] << ' ';
			cout << '\n';
		}
		reverse(a.begin() + m, a.end()); // ������ m�� �ǳʶٱ�
	} while (next_permutation(a.begin(), a.end()));
}