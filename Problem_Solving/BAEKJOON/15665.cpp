#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> a, selected;

// ������ Ž���Ѵ�
void permutation(int cnt)
{
	// ���� ���: cnt==m
	if (cnt == m)
	{
		// ���
		for (int i = 0; i < m; i++)
			cout << selected[i] << ' ';
		cout << '\n';
		return;
	}
	// �ּ��� �ߺ��� ���, ���� �ߺ��� �����
	vector<int> visited(10001); // ���� �ߺ� üũ
	for (int i = 0; i < n; i++)
	{
		if (visited[a[i]]) continue;
		selected[cnt] = a[i];
		visited[a[i]] = 1; // �湮 üũ
		permutation(cnt + 1);
	}
}

int main(void)
{
	cin >> n >> m;
	a.resize(n);
	selected.resize(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	permutation(0);
}