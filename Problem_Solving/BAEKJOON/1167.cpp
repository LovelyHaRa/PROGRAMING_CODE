#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int, int>>> adj; // ����, ����ġ�� ���� �ϴ� ���� ����Ʈ
int n; // ���� ����
int maxDist = 0; // ����� Ʈ���� ����

// start�κ��� �ִ� ������ ������ ��ȯ
int bfs(int start)
{
	queue<int> q;
	vector<bool> visited(n + 1); // ���� �湮 ����
	vector<int> dist(n + 1); // dist[v] start ���� ���� v ������ �Ÿ�
	int maxIdx = 0; // ��ȯ�� ����
	// �ʱ� ť ����
	q.push(start);
	visited[start] = 1;
	// bfs Ž��
	while (!q.empty())
	{
		// ť���� ����
		int here = q.front();
		q.pop();
		// ���� ���� ��� Ž��
		for (int i = 0; i < adj[here].size(); i++)
		{
			// ���� ����
			int v = adj[here][i].first; // ����
			int w = adj[here][i].second; // ����ġ
			// �̹湮 ��
			if (!visited[v])
			{
				visited[v] = 1; // �湮 üũ
				dist[v] = dist[here] + w; // ����ġ ����
				// ����ġ �ִ� ����
				if (maxDist < dist[v])
				{
					maxDist = dist[v];
					maxIdx = v;
				}
				// ť�� ���� �߰�
				q.push(v);
			}
		}
	}
	// �ִ� ���� ���� ��ȯ
	return maxIdx;
}

int main(void)
{
	cin >> n;
	adj.resize(n + 1);
	// �Է�
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		while (1)
		{
			int nextv, w;
			cin >> nextv;
			if (nextv < 0) break; // -1 �Է� ó��
			cin >> w;
			adj[v].push_back(make_pair(nextv, w)); // ���� ����Ʈ ����
		}
	}
	// 1���� �����ϴ� �������� bfs �� �� ��ȯ�Ǵ� ������ ����������
	// �ٽ� bfs Ž�� �� ���� �ִ� �Ÿ��� ���Ѵ�
	bfs(bfs(1));
	cout << maxDist << '\n';
}