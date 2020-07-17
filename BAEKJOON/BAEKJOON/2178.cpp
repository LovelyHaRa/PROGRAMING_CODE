#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> adj(n); // ���� ��� �׷���
	vector<vector<int>> visited(n, vector<int>(m)); // �湮 ����
	vector<vector<int>> move(n, vector<int>(m)); // �ش� ��ǥ������ �̵� ��� ������
	for (int i = 0; i < n; i++)
		cin >> adj[i];
	int dx[] = { -1,0,0,1 };
	int dy[] = { 0,-1,1,0 };
	queue<pair<int,int>> q; // bfs Ž�� ť
	// ���� ���� ť�� ����
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		pair<int, int> cur=q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		visited[x][y] = 1; // �湮 üũ
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			// ���� ������, 1����, �̹湮�Ǿ����� üũ
			// ť�� ������� �� �ٸ� ������ ���� �湮�� ���� �����Ƿ�, move���� ���� ���ε� ���ǿ� �߰�
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && adj[nx][ny] == '1' && !move[nx][ny])
			{
				move[nx][ny] = move[x][y] + 1; // ��� ����
				q.push(make_pair(nx, ny)); // ť�� ���� �߰�
			}
		}
	}
	cout << move[n - 1][m - 1] + 1 << '\n';
}