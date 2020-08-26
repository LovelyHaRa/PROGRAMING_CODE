#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj; // ���� ����Ʈ
vector<int> visited; // 0: �̹湮 // 1,2 // ������ �����ϴ� ����
int n;

// DFS Ž��
void dfs(int here, int color)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int v = adj[here][i];
		if (!visited[v])
		{
			visited[v] = color;
			dfs(v, 3 - color); // �ٸ� ����� ��ĥ
		}
	}
}

// �׷����� �̺� �׷������� Ȯ��
bool isBipartite()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			int v = adj[i][j];
			// ����Ʈ�� ������ ���� ���� ������ �̺б׷����� �ƴϴ�
			if (visited[i] == visited[v])
				return false;
		}
	}
	return true;
}

int main(void)
{
	int k;
	cin >> k;
	while (k--)
	{
		int m;
		cin >> n >> m;
		adj.resize(n + 1, vector<int>());
		visited.resize(n + 1);
		// ���� ����Ʈ�� �׷��� ǥ��
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		// ��� ������ ���� DFS Ž��
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
				dfs(i, 1);
		}
		cout << (isBipartite() ? "YES\n" : "NO\n");
		adj.clear();
		visited.clear();
	}
}