#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> a, selected;

void permutation(int cnt)
{
	// �������: cnt==m
	if (cnt == m)
	{
		// ���
		for (int i = 0; i < m; i++)
			cout << selected[i] << ' ';
		cout << '\n';
		return;
	}
	// �ߺ� �����̹Ƿ� ��� ��츦 DFS
	for (int i = 0; i < n; i++)
	{
		selected[cnt] = a[i];
		permutation(cnt + 1);
	}
	return;
}

int main(void)
{
	cin >> n >> m;
	a.resize(n);
	selected.resize(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// �������� ����
	sort(a.begin(), a.end());
	permutation(0);
}