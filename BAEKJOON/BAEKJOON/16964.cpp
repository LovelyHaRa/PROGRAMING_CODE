#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<int>> adj; // ���� ����Ʈ ����
vector<bool> check; // �湮 ����
vector<int> ans; // ���� ��ǲ
vector<int> order; // �湮 ���� �ε���
vector<int> res; // dfs ���� ���

// dfs Ž��
void dfs(int x)
{
	// Ž�� üũ
	check[x] = 1;
	res.push_back(x); // Ž�� ��� �迭�� �ֱ�
	// ���� ��� Ž��
	for (int y = 0; y < adj[x].size(); y++)
	{
		int next = adj[x][y];
		if (!check[next]) dfs(next);
	}
}

bool compare(int a, int b)
{
	return order[a] < order[b];
}

int main(void)
{
	// �Է�
	cin >> n;
	adj.resize(n + 1);
	check.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--; // ������ 0���� ����
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans.resize(n);
	order.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> ans[i];
		ans[i]--; // ������ 0���� ����
		order[ans[i]] = i; // ��ϵ� ������ ������ ����
	}
	// ���� ����Ʈ�� ������ ��ϵ� ������ ������ ����
	for (int i = 0; i < n; i++)
		sort(adj[i].begin(), adj[i].end(), compare);
	// 1���� dfs Ž��
	dfs(0);
	// ����迭�� ��� Ž���Ǿ����� 1 �ƴϸ� 0
	cout << (res == ans) << '\n';
}