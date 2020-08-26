#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>> board, tile; // ����, ���̳� Ÿ��
vector<int> row, col, square; // ��Ʈ ����ũ�� ��, ��, �簢�� ���� �ߺ� üũ
int t = 1, solved, dx[] = { 1,0 }, dy[] = { 0,1 };

// ����(x, y)�� ���� num�� ���� �� �ִ��� �Ǵ�
bool check(int x, int y, int num)
{
	bool checkRow = row[x] & (1 << num); // �� �˻�(������ true)
	bool checkCol = col[y] & (1 << num); // �� �˻�(������ true)
	bool checkSquare = square[x / 3 * 3 + y / 3] & (1 << num); // �簢�� �˻�(������ true)
	return !checkRow && !checkCol && !checkSquare; // ��� ����
}

// ���� �߰�
void addNum(int x, int y, int num)
{
	row[x] |= (1 << num); // �ش� �࿡ �߰�
	col[y] |= (1 << num); // �ش� ���� �߰�
	square[x / 3 * 3 + y / 3] |= (1 << num);  // �ش� �簢���� �߰�
}

void deleteNum(int x, int y, int num)
{
	row[x] &= (~(1 << num)); // �ش� �࿡�� ����
	col[y] &= (~(1 << num)); // �ش� ������ ����
	square[x / 3 * 3 + y / 3] &= (~(1 << num)); // �ش� �簢������ ����
}

// 0~80 ���� 81ĭ�� ��� �湮�Ѵ�
void solve(int here)
{
	// ��� �湮 ���� ���
	if (here == 81)
	{
		// ��� ���
		cout << "Puzzle " << t << '\n';
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << board[i][j];
			cout << '\n';
		}
		solved = 1; // Ż�� �÷��� ����
		return;
	}
	// ��ǥ ���
	int x = here / 9, y = here % 9;
	// �ش� ��ǥ�� �̹� ���� �ִٸ� ���� ĭ���� �ǳʶٱ�
	if (board[x][y])
	{
		solve(here + 1);
		return;
	}
	// ������ ��� Ÿ�� ��ȸ
	for (int i = 1; i <= 9; i++)
	{
		for (int j = i + 1; j <= 9; j++)
		{
			if (tile[i][j] || tile[j][i]) continue; // �̹� ����� Ÿ���̸� �ǳʶٱ�
			// ����, ���� Ÿ�� �߰�
			for (int k = 0; k < 2; k++)
			{
				int nx = x + dx[k], ny = y + dy[k]; // ù ��°�� ����, �� ��°�� ����
				// ���� �� ���忡 ���ڰ� �ִ��� �˻�
				if (nx < 9 && ny < 9 && !board[nx][ny])
				{
					int l = 2; // (i, j), (j, i) ��� �־�� �Ѵ�
					while (l--)
					{
						// ���� ���� �� �ִ��� üũ
						bool checkFirst = check(x, y, i);
						bool checkSecond = check(nx, ny, j);
						// ���� ���� �� �ִٸ�
						if (checkFirst && checkSecond)
						{
							// Ÿ�� ��� üũ
							tile[i][j] = 1;
							tile[j][i] = 1;
							// ���忡 �� �ֱ�
							board[x][y] = i;
							board[nx][ny] = j;
							// ���� ��� üũ
							addNum(x, y, i);
							addNum(nx, ny, j);
							// ���� ���� Ž��
							solve(here + 1);
							// ���󺹱�
							deleteNum(x, y, i);
							deleteNum(nx, ny, j);
							board[x][y] = 0;
							board[nx][ny] = 0;
							tile[i][j] = 0;
							tile[j][i] = 0;
						}
						// swap
						int tmp = i;
						i = j;
						j = tmp;
					}
				}
			}
			if (solved) return; // ������ ��� Ǯ������ �׳� ����
		}
	}
}


int main(void)
{
	while (1)
	{
		int n;
		cin >> n;
		if (!n) break;
		// �ʱ� ����
		board.resize(9, vector<int>(9));
		tile.resize(10, vector<int>(10));
		row.resize(9);
		col.resize(9);
		square.resize(9);
		solved = 0;
		// Ÿ�� �Է�
		for (int i = 0; i < n; i++)
		{
			int first, second;
			string fpos, spos;
			cin >> first >> fpos >> second >> spos;
			// ��ǥ ���
			int fx = fpos[0] - 65, fy = fpos[1] - '0' - 1, sx = spos[0] - 65, sy = spos[1] - '0' - 1;
			// ���忡 ���� �߰�
			board[fx][fy] = first, board[sx][sy] = second;
			// ���� ��� üũ
			addNum(fx, fy, first);
			addNum(sx, sy, second);
			// Ÿ�� ��� üũ
			tile[first][second] = tile[second][first] = 1;
		}
		for (int i = 1; i <= 9; i++)
		{
			string pos;
			cin >> pos;
			// ��ǥ ���
			int x = pos[0] - 65, y = pos[1] - '0' - 1;
			board[x][y] = i; // ���� ��� üũ
			addNum(x, y, i); // Ÿ�� ��� üũ
		}
		solve(0); // ���� Ǯ��
		t++;
		// ���� �ʱ�ȭ
		board.clear();
		tile.clear();
		row.clear();
		col.clear();
		square.clear();
	}
}