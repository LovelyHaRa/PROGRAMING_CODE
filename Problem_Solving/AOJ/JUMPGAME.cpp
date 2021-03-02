#include<iostream>
#include<vector>

using namespace std;

int jump(const vector<vector<int>>& board, vector<vector<int>>& cache, int n, int y, int x)
{
	// ���� ���: ������ ����� �� �� ����
	if (y >= n || x >= n) return 0;
	// ���� ���: ������ ĭ�� �����ϸ� ������ ���̹Ƿ� 1 ����
	if (y == n - 1 && x == n - 1) return 1;
	int& ref = cache[y][x]; // ��������
	if (ref != -1) return ref; // ĳ�̵Ǿ������� ĳ�� �� ����
	int jumpSize = board[y][x]; // ��ǥ��=��������ĭ
	// ���Ž���� ���ÿ� ĳ��
	return ref = jump(board, cache, n, y + jumpSize, x) || jump(board, cache, n, y, x + jumpSize);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<vector<int>> cache(n, vector<int>(n, -1)); // �޸����̼� ĳ��
		vector<vector<int>> board(n, vector<int>(n)); // ����
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		}
		cout << (jump(board, cache, n, 0, 0) ? "YES\n" : "NO\n");
	}
}