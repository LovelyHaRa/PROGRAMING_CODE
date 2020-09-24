#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

bool visited[11][1000][1000]; // �μ� ���� ����, x, y ������ ������� �湮 ���� Ȯ��
queue <pair<pair<int, int>, pair<int, int>>> q; // x,y ���, �̵��Ÿ�, �μ� ���� ���� ��� ť

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> map(n); // �� ����
	for (int i = 0; i < n; i++)
		cin >> map[i];
	// �ʱ� ť ����
	q.push(make_pair(make_pair(0, 0), make_pair(1,0)));
	visited[0][0][0] = 1; // �湮 üũ
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // �����¿� �̵� ������
	int res = -1; // �ּ� �̵� �Ÿ�
	// BFS Ž��
	while (!q.empty())
	{
		// ť���� ����
		pair<pair<int, int>, pair<int, int>> cur = q.front();
		q.pop();
		int x = cur.first.first, y = cur.first.second; // ��ǥ
		int move = cur.second.first; // ���ݱ����� �̵� �Ÿ�
		int breakWall = cur.second.second; // ���ݱ����� �� �μ� Ƚ��
		// ���� �����ϸ�
		if (x == n - 1 && y == m - 1)
		{
			res = move; // ��� ����
			break; // Ž�� ����
		}
		// �����¿� �̵�
		for (int i = 0; i < 4; i++)
		{
			// ���� ��ǥ
			int nx = x + dx[i], ny = y + dy[i];
			// ���� ���̰ų� �̹� �湮�ߴٸ� �ǳʶٱ�
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[breakWall][nx][ny]) continue;
			// ���μ��� �̵� ������ ��
			if (breakWall < k && map[nx][ny] == '1')
			{
				visited[breakWall + 1][nx][ny] = 1; // �� �μ��� �湮 üũ
				// ť�� ����
				q.push(make_pair(make_pair(nx, ny), make_pair(move + 1, breakWall + 1)));
			}
			// �̵� ������ �����̸�
			else if (map[nx][ny] == '0')
			{
				visited[breakWall][nx][ny] = 1; // �湮 üũ
				// ť�� ����
				q.push(make_pair(make_pair(nx, ny), make_pair(move + 1, breakWall)));
			}
		}
	}
	cout << res << '\n';
}