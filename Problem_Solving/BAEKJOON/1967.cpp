#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int, int>>> adj; // ����� ����, ����ġ�� ���� �ϴ� ���� ����Ʈ
int n; // ��� ����
int maxDist; // ����� �ִ� ����

// start ��带 �������� BFS ���� �� ���������� ���� �ִ� ������ ��带 ��ȯ
int bfs(int start)
{
	queue<int> q;
	vector<bool> visited(n + 1); // �湮 ����
	vector<int> dist(n + 1); // dist[n]: ���� ��� ���� n������ �Ÿ�
	int maxIdx = 0; // ��ȯ�� �ִ� ������ ���
	// �ʱ� ť ����
	q.push(start);
	visited[start] = 1;
	// BFS ����
	while (!q.empty())
	{
		// ť���� ����
		int here = q.front();
		q.pop();
		// ����� ���� ��� Ž��
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first; // ���
			int weight = adj[here][i].second; // ����ġ
			// �̹湮 ��
			if (!visited[there])
			{
				visited[there] = 1; // �湮 üũ
				dist[there] = dist[here] + weight; // �Ÿ� ����
				// �Ÿ��� �ִ� ����
				if (maxDist < dist[there])
				{
					maxDist = dist[there];
					maxIdx = there; // ��� ����
				}
				// ť�� �߰�
				q.push(there);
			}
		}
	}
	return maxIdx; // �ִ� �Ÿ� ��� ��ȯ
}

int main(void)
{
	cin >> n;
	adj.resize(n + 1);
	// ���� ����Ʈ ����
	for (int i = 0; i < n-1; i++)
	{
		int r, c, w;
		cin >> r >> c >> w;
		adj[r].push_back(make_pair(c, w));
		adj[c].push_back(make_pair(r, w));
	}
	// 1���� �����ؼ� BFS ���� �� ���� �� ����� ��ȣ�� �ٽ� BFS ����
	bfs(bfs(1));
	cout << maxDist << '\n';
}