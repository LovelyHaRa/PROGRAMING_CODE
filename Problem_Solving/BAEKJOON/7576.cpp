#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> adj(n, vector<int>(m));
	vector<vector<int>> visited(n, vector<int>(m));
	queue<pair<int, int>> q;
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	int seq = 0, curSeq, day = 0; // ������ ť�� �߰��� Ƚ��, ���� ť�� �߰��� Ƚ��, �ϼ�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> adj[i][j];
			// 1�̸� ť�� �߰�
			if (adj[i][j] == 1)
			{
				q.push(make_pair(i, j));
				seq++; // ť�� �߰��� Ƚ�� ����
			}
		}
	// bfs Ž��
	while (!q.empty())
	{
		curSeq = 0;
		int flag = 0; // ������ �丶�䰡 �̹� �;��ų� ���ٴ� ���� �ľ��ϱ� ���� �÷���
		// ���� ť�� �߰��� Ƚ����ŭ ť���� ������
		for (int i = 0; i < seq; i++)
		{
			int x = q.front().first, y = q.front().second;
			visited[x][y] = 1;
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j], ny = y + dy[j];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && !adj[nx][ny])
				{
					curSeq++; // ���� ť�� �߰��� Ƚ�� �߰�
					flag = 1; // ������ �丶�並 �߰�(�ϼ��� ����)
					adj[nx][ny] = 1;
					q.push(make_pair(nx, ny)); // ť�� ����
				}
			}
		}
		seq = curSeq; // ť�� �߰��� Ƚ�� ����
		if (flag) day++; // ������ �丶�䰡 �߰ߵǸ� �ϼ��� ����
	}
	// ������ �丶�䰡 �ִ��� Ȯ��
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && !adj[i][j])
			{
				cout << "-1\n";
				return 0;
			}
		}
	// ������ �丶�䰡 ������ �ϼ� ���
	cout << day << '\n';
}