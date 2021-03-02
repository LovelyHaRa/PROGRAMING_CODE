#include<iostream>
#include<queue>
#include<string>

using namespace std;

// bfs�� ������ ���� ����
struct balls
{
	// �̵�Ƚ��, ���� ���� ��ǥ, �Ķ� ���� ��ǥ
	int cnt, rx, ry, bx, by;
};

int board[10][10]; // ����, 0: ��, 1: �������, 2: ����
bool visited[10][10][10][10]; // visited(x,y,z,w): ���� ���� ��ǥ, �Ķ� ���� ��ǥ �湮����
int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // �����¿� ������

// ���̳� ������ ���� �� ���� d�������� �����̱�
void moveBall(int &x, int &y, int d)
{
	while (board[x+dx[d]][y+dy[d]])
	{
		x += dx[d], y += dy[d];
		if (board[x][y] == 2) break;
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	// ���� ����, �Ķ� ����, ���� ��ǥ
	pair<int, int> red, blue, hole;
	// ���� ����
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			// �Է¹��� ���� ������ ���ڷ� �ٲ� �ֱ�
			switch (s[j])
			{
			case '#': board[i][j] = 0; break; // ��
			case '.': board[i][j] = 1; break; // �������
			case 'O': board[i][j] = 2; hole = make_pair(i, j); break; // ����
			case 'R': board[i][j] = 1; red = make_pair(i, j); break; // ���� ����
			case 'B': board[i][j] = 1; blue = make_pair(i, j); break; // �Ķ� ����
			}
		}
	}
	int res = -1; // ���
	// �ʱ� ť ����
	queue<balls> q;
	q.push({ 0,red.first,red.second,blue.first,blue.second });
	visited[red.first][red.second][blue.first][blue.second] = 1;
	// BFS Ž��
	while (!q.empty())
	{
		// ť���� ����
		balls cur = q.front();
		q.pop();
		// 1. 10ȸ�� �ʰ��ϸ� Ž�� ����
		if (cur.cnt > 10)
			break;
		// 2. ���� ������ ���ۿ� ���� ��� ���� �� Ž�� ����
		if (make_pair(cur.rx, cur.ry) == hole)
		{
			res = cur.cnt;
			break;
		}
		// 3. �����¿� �ùķ��̼�
		for (int i = 0; i < 4; i++)
		{
			// ���� �����̱�
			red = make_pair(cur.rx, cur.ry);
			blue = make_pair(cur.bx, cur.by);
			moveBall(red.first, red.second, i);
			moveBall(blue.first, blue.second, i);

			if (blue == hole) continue; // �Ķ� ������ ���ۿ� ������ �ǳʶٱ�

			// ������ ������ �� ���� ���� ��ġ�� ������
			if (red == blue)
			{
				// �ʱ� ��ġ���踦 �ľ� �� ���� ��ġ ������
				switch (i)
				{
				case 0: cur.rx > cur.bx ? red.first++ : blue.first++; break;
				case 1: cur.ry > cur.by ? red.second++ : blue.second++; break;
				case 2: cur.ry < cur.by ? red.second-- : blue.second--; break;
				case 3: cur.rx < cur.bx ? red.first-- : blue.first--; break;
				}
			}
			// �湮 ���θ� Ȯ�� �� ť�� �߰�
			if (!visited[red.first][red.second][blue.first][blue.second])
			{
				visited[red.first][red.second][blue.first][blue.second] = 1;
				q.push({ cur.cnt + 1, red.first,red.second,blue.first,blue.second });
			}
		}
	}
	cout << res << '\n';
}