#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int n, m;

// ���� ����Ʈ�� ���� dfs Ž��
void dfs(int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int k = adj[here][i];
		if (!visited[k])
		{
			visited[k] = 1;
			dfs(k);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	adj.resize(n + 1, vector<int>());
	visited.resize(n + 1);
	// ���� ����Ʈ ǥ��
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	// ��� ������ ���� dfs�� ȣ���� Ƚ���� ������Ʈ ������
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << '\n';
}