#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int n; // ���� ũ��
int maxBlockSize = 0; // �ִ� ��� ũ��

int max(int a, int b) { return a > b ? a : b; }

// ����� �����¿� �̵� ��Ų ����� ��ȯ
vector<vector<int>> moveBlock(vector<vector<int>> curBoard, int dir)
{
	// dir: ��, ��, ��, ��
	queue<int> q; // ����� �����ų ť
	// 1. ����� ť�� ����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			switch (dir)
			{
			case 0:
				if (curBoard[j][i])
					q.push(curBoard[j][i]);
				curBoard[j][i] = 0;
				break;
			case 1:
				if (curBoard[i][j])
					q.push(curBoard[i][j]);
				curBoard[i][j] = 0;
				break;
			case 2:
				if (curBoard[i][n - j - 1])
					q.push(curBoard[i][n - j - 1]);
				curBoard[i][n - j - 1] = 0;
				break;
			case 3:
				if (curBoard[n - j - 1][i])
					q.push(curBoard[n - j - 1][i]);
				curBoard[n - j - 1][i] = 0;
				break;
			}
		}
		// 2. ť���� ����� ���� ��ġ��
		int curBlock = 0, idx = 0;
		while (!q.empty())
		{
			curBlock = q.front();
			q.pop();
			switch (dir)
			{
			case 0:
				// ���� ��ġ�� ����� ������� ���� ���
				if (!curBoard[idx][i]) curBoard[idx][i] = curBlock;
				// ���� ��ġ�� ����� ����Ǿ� �ְ� ���� ��ϰ� ���� ���� ���
				else if (curBoard[idx][i] == curBlock) curBoard[idx++][i] *= 2;
				// �� �ΰ��� ��찡 �ƴ� ���
				else curBoard[++idx][i] = curBlock;
				break;
			case 1:
				if (!curBoard[i][idx]) curBoard[i][idx] = curBlock;
				else if (curBoard[i][idx] == curBlock) curBoard[i][idx++] *= 2;
				else curBoard[i][++idx] = curBlock;
				break;
			case 2:
				if (!curBoard[i][n - idx - 1]) curBoard[i][n - idx - 1] = curBlock;
				else if (curBoard[i][n - idx - 1] == curBlock) curBoard[i][n - (idx++) - 1] *= 2;
				else curBoard[i][n - (++idx) - 1] = curBlock;
				break;
			case 3:
				if (!curBoard[n - idx - 1][i]) curBoard[n - idx - 1][i] = curBlock;
				else if (curBoard[n - idx - 1][i] == curBlock) curBoard[n - (idx++) - 1][i] *= 2;
				else curBoard[n - (++idx) - 1][i] = curBlock;
				break;
			}
		}
	}
	return curBoard;
}

// ���忡�� �ִ� ��� ����� ã�´�
int findMaxBlockSize(vector<vector<int>> board)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret = max(ret, board[i][j]);
	return ret;
}

// dfs Ž������ ��� ��� ����
void move(vector<vector<int>> curBoard, int cnt, int curMaxBlockSize)
{
	// 5�� �̵� ������
	if (cnt == 5)
	{
		maxBlockSize = max(maxBlockSize, curMaxBlockSize); // �ִ� ��� ������ ���ϱ�
		return;
	}
	// �����¿� �̵�
	for (int i = 0; i < 4; i++)
	{
		vector<vector<int>> nextBoard = moveBlock(curBoard, i); // ��� �̵� ��� ���ϱ�
		move(nextBoard, cnt + 1, findMaxBlockSize(nextBoard)); // dfs Ž��
	}
}

int main(void)
{
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	move(board, 0, findMaxBlockSize(board));
	cout << maxBlockSize << '\n';
}