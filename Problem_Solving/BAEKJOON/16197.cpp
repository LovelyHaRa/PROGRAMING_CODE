#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, m; // ����, ������ ����
vector<string> board(20); // ���� ����
pair<int, int> coin[2]; // ���忡 ��ġ�� �� ������ x, y ��ǥ ���
int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // �̵� ������

// (x, y)�� ���� ���� ���� �ִ��� �Ǻ�
bool isOutRange(int x, int y)
{
	return (x<0 || x>=n || y < 0 || y >= m);
}

// (x, y)�� ���� ��ġ���ִ��� Ȯ��
bool isWall(int x, int y) { return !isOutRange(x, y) && board[x][y] == '#'; }

// �� ���� c1, c2�� �ϳ��� ���忡�� ������ �� ���� �̵�
int move(pair<int, int> c1, pair<int, int> c2, int cnt)
{
	if (cnt > 10) return -1; // ������� 1: Ƚ�� 10ȸ �ʰ� �� -1 ����
	// ��ġ�� ����
	int c1x = c1.first, c1y = c1.second, c2x = c2.first, c2y = c2.second;
	// ���� ��(�������� ��) Ȯ��
	bool out1 = isOutRange(c1x, c1y), out2 = isOutRange(c2x, c2y);
	// ������� 2: �� �� �������� �Ұ���(-1 ����)
	if (out1 && out2) return -1;
	// ������� 3: �ϳ��� �������� �̵� Ƚ�� ����
	if (out1 || out2) return cnt;

	int ret = -1; // ��ȯ�� �̵� Ƚ��
	// �����¿� �̵�
	for (int i = 0; i < 4; i++)
	{
		// ���� �̵�
		int c1nx = c1x + dx[i], c1ny = c1y + dy[i];
		int c2nx = c2x + dx[i], c2ny = c2y + dy[i];
		// ���� ��ġ�ߴٸ� ���� ����
		if (isWall(c1nx, c1ny)) c1nx = c1x, c1ny = c1y;
		if (isWall(c2nx, c2ny)) c2nx = c2x, c2ny = c2y;
		// ���� ���� Ž��
		int next = move(make_pair(c1nx, c1ny), make_pair(c2nx, c2ny), cnt + 1);
		// �Ұ��� �� ���� �ǳ� �ٱ�
		if (next == -1) continue;
		// �׷��� �ʴٸ� ������ ��� �̹Ƿ� ����/�ּڰ� ����
		if (ret == -1 || ret > next) ret = next;
	}
	return ret; // �̵� Ƚ�� ��ȯ
}

int main()
{
	cin >> n >> m;
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < m; j++)
			if (board[i][j] == 'o')
				coin[c++] = make_pair(i, j); // ���� ����
	}
	cout << move(coin[0], coin[1], 0) << '\n';;
}