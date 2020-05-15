#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> board;
vector<vector<int>> cache;
const int EMPTY = -987654321;

int max(int a, int b) { return a > b ? a : b; }

int play(int left, int right)
{
	if (left > right) return 0;
	int& ret = cache[left][right];
	if (ret != EMPTY) return ret;
	// ���� ���� �������� ���� ������ ���� �������� ��� �� ū ���� ����
	ret = max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));
	// ���� �����ϴ� ���
	if (right - left >= 2)
	{
		// (���� ����) - (���� ����)�� ���ϱ� ���� ��ȣ ����
		ret = max(ret, -play(left + 2, right)); // ���� �� 2�� ����
		ret = max(ret, -play(left, right - 2)); // ���� �� �� 2�� ����
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		board.resize(n);
		for (int i = 0; i < n; i++)
			cin >> board[i];
		cache.resize(n, vector<int>(n, EMPTY));
		cout << play(0, n - 1) << '\n';
		board.clear();
		cache.clear();
	}
}