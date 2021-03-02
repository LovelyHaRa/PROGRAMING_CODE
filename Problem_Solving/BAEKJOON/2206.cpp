#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;
// ���� �μ��� �ִ� ����, x, y�� ������ ������� �̵� Ƚ�� ���ϱ�
int moveCount[2][1000][1000];

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> map(n);
	for (int i = 0; i < n; i++)
		cin >> map[i];
	// �����¿� �̵� ������
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };
	// �ʱ� ť ����
	queue<pair<int, pair<int, int>>> q; // �μ� �� �ִ� ����, x, y�� ������ ������� ť ����
	q.push(make_pair(1, make_pair(0, 0)));
	moveCount[1][0][0] = 1;
	int res = -1;
	// BFS Ž��
	while (!q.empty())
	{
		pair<int, pair<int, int>> cur = q.front();
		int isBreakable = cur.first; // �μ��� �ִ� ����
		int x = cur.second.first, y = cur.second.second; // ���� ��ǥ
		q.pop();
		// �����ϸ�
		if (x == n - 1 && y == m - 1)
		{
			res = moveCount[isBreakable][x][y]; // ����
			break;
		}
		// �����¿� �̵�
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			// ���� Ȯ��
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// ���� �μ� �� �ְ� �̵��� ��ǥ�� ���� ���
			if (isBreakable && map[nx][ny]=='1')
			{
				// ���� �μ��� �̵� Ƚ�� ���
				moveCount[isBreakable - 1][nx][ny] = moveCount[isBreakable][x][y] + 1;
				// ť�� ����
				q.push(make_pair(isBreakable - 1, make_pair(nx, ny)));
			}
			// �̵��� ��ǥ�� ���� �ƴϰ� ó�� �湮�� ���
			else if (map[nx][ny]=='0' && !moveCount[isBreakable][nx][ny])
			{
				// �̵� Ƚ�� ���
				moveCount[isBreakable][nx][ny] = moveCount[isBreakable][x][y] + 1;
				// ť�� ����
				q.push(make_pair(isBreakable, make_pair(nx, ny)));
			}
		}
	}
	cout << res << '\n';
}