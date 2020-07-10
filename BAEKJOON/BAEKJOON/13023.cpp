#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
bool answer = false;

void dfs(int here, int cnt)
{
	// ģ�� ���谡 4���� �Ǹ� ����ó��
	if (cnt == 4)
	{
		answer = true;
		return;
	}
	visited[here] = true; // ���� �湮 ó��
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (!visited[there])
			dfs(there, cnt + 1);
		if (answer) return; // ������ ã�� ��� ����
	}
	visited[here] = false; // ���� ����
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	adj.resize(n, vector<int>());
	// �׷��� ����
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// ��� ������ ���������� DFS Ž��
	for (int i = 0; i < n; i++)
	{
		// �湮���� �迭 �ʱ�ȭ
		visited.clear();
		visited.resize(n);
		dfs(i, 0);
		if (answer) break; // ������ ã�� ��� ���̻� Ž������ ����
	}
	cout << answer << '\n';
}