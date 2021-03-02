#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<bool>> board, visited;
int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // �����¿� �̵�

void dfs(int x, int y)
{
	visited[x][y] = 1;
	// �����¿� Ž��
	for (int i = 0; i < 4; i ++ )
	{
		int nx = x + dx[i], ny = y + dy[i];
		// ���� ��, �̹� �湮�ߴٸ� �ǳʶٱ�
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
		if (board[nx][ny]) dfs(nx, ny); // ���߰� �ִٸ� dfsŽ��
	}
	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> n >> m >> k;
		board.resize(n, vector<bool>(m));
		visited.resize(n, vector<bool>(m));
		while (k--)
		{
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; i ++ )
			for (int j = 0; j < m; j++)
				if (board[i][j] && !visited[i][j])
				{
					dfs(i, j);
					cnt++; // ������Ʈ Ž���� �������Ƿ� �Ѹ��� �߰�
				}
		cout << cnt << '\n';
		board.clear();
		visited.clear();
	}
}