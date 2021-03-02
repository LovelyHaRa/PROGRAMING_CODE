#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj; // �׷��� ���� ����Ʈ ǥ��
vector<int> check; //  0: �̹湮, 1: �湮, 2: ����Ŭ�� ���Ե�
vector<int> dist; // ����Ŭ���� �Ÿ�

// ���� ������ ���� ������ ������� dfs Ž���� �Ͽ� ����Ŭ�� ã�´�.
// -2: ����Ŭ�� ���Ե� ��尡 �ƴ�, -1: ���� ���, 0�̻�: ����Ŭ ������ ���
int dfs(int here, int prev)
{
	if (check[here]) return here; // �θ� ���� ��ȯ
	check[here] = 1; // �湮 üũ
	// ����� ���� ��� �湮
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i]; // ���� ���� ����
		if (there == prev) continue; // �ٷ� ���� Ž���� ���(prev)�� �ǳʶٱ�
		int ret = dfs(there, here); // dfs Ž��
		if (ret == -2) return -2; // ����Ŭ�� �ƴ� ����� ��
		// ����Ŭ�� ���Ե� ��
		if (ret >= 0)
		{
			check[here] = 2; // ����Ŭ ǥ��
			if (ret == here) return -2; // �������� ��� ����Ŭ�� �ƴ�
			return ret; // ���� ��ȣ ��ȯ
		}
	}
	return -1;
}

int main(void)
{
	int n;
	cin >> n;
	adj.resize(n + 1);
	check.resize(n + 1);
	dist.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		// ������ �׷��� ǥ��
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// dfs Ž��
	dfs(1, -1);
	// bfs Ž������ ����Ŭ���� �Ÿ� ���
	queue<int> q;
	// �ʱ� ť ����
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 2)
			q.push(i);
	}
	// bfs Ž��
	while (!q.empty())
	{
		// ���� ����
		int here = q.front();
		q.pop();
		// ����� ���� ��� Ž��
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (check[there] == 2) continue; // ����Ŭ�̸� �ǳʶ�
			check[there] = 2; // �湮 üũ
			dist[there] = dist[here] + 1; // �Ÿ� ���
			q.push(there); // ť�� ����
		}
	}
	// ���
	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
	cout << '\n';
}