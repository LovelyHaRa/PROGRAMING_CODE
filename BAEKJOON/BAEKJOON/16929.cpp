#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<string> adj; // ������
pair<int, int> start; // ��������
int res = 0; // ����Ŭ ���� ����
// ��ȭ�¿� �̵� ������
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

// dfs Ž�� (��ġ(x, y), �������� ����, �湮 ����)
void dfs(int x, int y, char dot, vector<vector<int>> visited)
{
	// �����¿� Ž��
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i]; // ���ο� x, y ��ǥ
		// ��ǥ�� ������ ���� ������, �ش� ��ǥ�� ���������� �Ȱ��� ���� ��,
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && adj[nx][ny] == dot)
		{
			// �ش� ��ǥ�� ���������� ���
			if (nx == start.first && ny == start.second)
				// ����Ŭ ���� ����: ���������� (x, y)���� �̵� Ƚ���� 3 �̻�
				if (visited[x][y] >= 3)
				{
					res = 1; // ����Ŭ ������
					return;
				}
			else
				// �湮���� ���� ������ ���
				if (!visited[nx][ny])
				{
					// ���� ��ġ������ �̵� Ƚ���� 1�� ���� ���� ����
					visited[nx][ny] = visited[x][y] + 1;
					// dfs Ž��
					dfs(nx, ny, dot, visited);
					// ����Ŭ�� �����Ǿ����� Ž�� ����
					if (res) return;
				}
		}
	}
}

int main(void)
{
	
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < n; i++)
		cin >> adj[i];
	// ������ �� ��� ������ ���������� �Ͽ� dfs Ž��
	// ����Ŭ�� �����Ǵ� ��� Yes ��� �� ����
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			start = make_pair(i, j); // ���� ���� ��ǥ ����
			// dfs Ž�� ����
			dfs(i, j, adj[i][j], vector<vector<int>>(n, vector<int>(m)));
			// ����Ŭ�� ������ �� ������
			if (res)
			{
				// Yes ���
				cout << "Yes\n";
				return 0;
			}
		}
	cout << "No\n";	
}