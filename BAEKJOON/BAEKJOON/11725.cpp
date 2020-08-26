#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1); // Ʈ���� ���� ����Ʈ�� ǥ��
	vector<int> parent(n + 1); // parent[x]: x�� �θ� ���
	vector<bool> check(n + 1); // ��� �ߺ� Ž�� ���� �迭
	// ���� ����Ʈ ����
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// �ʱ� ť ����
	queue<int> q;
	q.push(1);
	// BFS Ž��
	while (!q.empty())
	{
		// ��� ����
		int here = q.front();
		q.pop();
		// ����� ��� Ž��
		for (int there : adj[here])
		{
			// �̹湮 ��
			if (!check[there])
			{
				check[there] = true; // �湮 üũ
				parent[there] = here; // here���� there ����� �θ�
				q.push(there); // ť�� ��� ����
			}
		}
	}
	// ���
	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}