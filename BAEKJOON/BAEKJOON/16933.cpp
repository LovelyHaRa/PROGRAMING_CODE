#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

// ���¸� ����ȭ
struct State {
	int x, y, moveCnt, breakCnt; // ��ǥ, �̵�Ƚ��, �μ� ���� ����
	bool isNight; // ������ ����
	State(int _x, int _y, int _moveCnt, int _breakCnt, bool _isNight):
		x(_x),y(_y),moveCnt(_moveCnt), breakCnt(_breakCnt), isNight(_isNight) {}
};

bool visited[11][1000][1000]; // �μ����� ����, x,y ��ǥ�� ������� �湮 üũ

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> map(n); // �� ����
	for (int i = 0; i < n; i++)
		cin >> map[i];
	// �ʱ� ť ����
	queue<State> q;
	q.push(State(0, 0, 1, 0, 0));
	visited[0][0][0] = 1;
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // �����¿� �̵� ������
	int res = -1;
	// BFS Ž��
	while (!q.empty())
	{
		// ť���� ����
		State cur = q.front();
		q.pop();
		int x = cur.x, y = cur.y, moveCnt = cur.moveCnt, breakCnt = cur.breakCnt;
		bool isNight = cur.isNight;
		// �������� ��
		if (x == n - 1 && y == m - 1)
		{
			res = moveCnt; // �̵� Ƚ�� ����
			break;
		}
		// �����¿� �̵�
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i]; // ��ǥ ����
			// ���� ���̸� �ǳʶٱ�
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// �̵��� ������ ���̰� �湮���� �ʾҴٸ�
			if (breakCnt < k && map[nx][ny] == '1' && !visited[breakCnt + 1][nx][ny])
			{
				// ���̸� �̵����� �ʰ� �̵��Ÿ��� ���� ��Ű�� ������ �ٲ� �� ť�� ����
				if (isNight)
					q.push(State(x, y, moveCnt + 1, breakCnt, !isNight));
				// ���̸� ���� �μ��� �̵��Ÿ��� ������Ű�� ������ �ٲ� �� ť�� ����
				else
				{
					visited[breakCnt + 1][nx][ny] = 1; // �湮 üũ
					q.push(State(nx, ny, moveCnt + 1, breakCnt + 1, !isNight));
				}
			}
			// �̵��� ������ ���� �ƴϰ� �湮���� �ʾҴٸ�
			else if (map[nx][ny] == '0' && !visited[breakCnt][nx][ny])
			{
				visited[breakCnt][nx][ny] = 1; // �湮 üũ
				// ť�� �̵��Ÿ��� ������Ű�� ������ ����Ī�� �� ť�� ����
				q.push(State(nx, ny, moveCnt + 1, breakCnt, !isNight));
			}
		}
	}
	cout << res << '\n';
}