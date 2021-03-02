#include<iostream>
#include<vector>

using namespace std;

int V;
vector<vector<int>> adj; // ���� ����Ʈ ǥ��
vector<bool> visited; // �湮 ����
const int UNWATCHED = 0; // �ٸ� ��忡 ������� ����
const int WATCHED = 1; // �ٸ� ��忡 �����
const int INSTALLED = 2; // ī�޶� ��ġ��
int installed; // ī�޶� ��ġ ���

// here�κ��� ���� �켱 Ž���� �ϰ�, here�� ������ ��ȯ�Ѵ�
int dfs(int here)
{
	visited[here] = true; // �湮 üũ
	int children[3] = { 0,0,0 }; // ���� ���� �ʱ�ȭ
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (!visited[there])
			++children[dfs(there)]; // ���� ���� ����
	}
	// �ڼ� ��� �� ���õ��� �ʴ� ��尡 ���� ��� ī�޶� ��ġ
	if (children[UNWATCHED]) {
		++installed;
		return INSTALLED; // ī�޶� ��ġ������ ��ȯ
	}
	// �ڼ� ��� �� ī�޶� ��ġ�� ��尡 ���� ��� ��ġ�� �ʿ䰡 ����
	if (children[INSTALLED]) {
		return WATCHED; // ��������� ��ȯ
	}
	// �� �̿��� ��� ��������� ������ ��ȯ
	return UNWATCHED;
}

// �׷����� �����ϴ� �� �ʿ��� ī�޶��� �ּ� ���� ��ȯ�Ѵ�
int installCamera()
{
	// �ʱ�ȭ
	installed = 0;
	visited = vector<bool>(V, false);
	// ��� ������ ���� dfs Ž��
	for (int u = 0; u < V; u++)
		if (!visited[u] && dfs(u) == UNWATCHED)
			installed++;
	return installed;
}

int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> V >> n;
		adj = vector<vector<int>>(V, vector<int>());
		// ���� ����Ʈ ����
		for (int i = 0; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << installCamera() << '\n';
	}
}