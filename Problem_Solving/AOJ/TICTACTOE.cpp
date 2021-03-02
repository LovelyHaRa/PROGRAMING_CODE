#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> cache(19683, -2);

// �� �� �Ǵ� �밢���� o �Ǵ� x�� ä���� ��� true
bool isFinished(const vector<string>& board, char turn)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		// ������
		for (j = 0; j < 3; j++)
			if (board[i][j] == turn) continue;
			else break;
		if (j == 3) return true;
		// ������
		for (j = 0; j < 3; j++)
			if (board[j][i] == turn) continue;
			else break;
		if (j == 3) return true;
	}
	// ������ �밢��
	for (i = 0; i < 3; i++)
	{
		if (board[i][i] == turn) continue;
		else break;
	}
	if (i == 3) return true;
	// �������� �밢��
	for (i = 0; i < 3; i++)
	{
		if (board[i][2 - i] == turn) continue;
		else break;
	}
	if (i == 3) return true;
	return false; // ��� �ش�ȵǸ� false
}

// �������� ��Ȳ�� 3������ ��ȯ�� 10������ ����
int bijection(const vector<string>& board) {
	int ret = 0, k = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int sum = 0;
			if (board[i][j] == 'o') ++sum;
			else if (board[i][j] == 'x') sum += 2;
			sum *= k;
			ret += sum;
			k *= 3;
		}
	}
	return ret;
}

int min(int a, int b) { return a < b ? a : b; }

// turn�� �̱� �� �ִ� ��� 1, ���� ��� 0, ���� ��� -1
int canWin(vector<string>& board, char turn)
{
	// �������: ���� �� ��밡 ������ ���� �� �ִ� ���
	if (isFinished(board, 'o' + 'x' - turn)) return -1;
	// �޸������̼�
	int& ret = cache[bijection(board)];
	if (ret != -2) return ret;
	int minValue = 2;
	// �������� ��� Ž���ϸ鼭 �ּڰ� ����
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '.')
			{
				board[i][j] = turn;
				minValue = min(minValue, canWin(board, 'o' + 'x' - turn));
				board[i][j] = '.';
			}
		}
	}
	// ���ų� ������ �ȵ� ���
	if (minValue == 2 || !minValue) return ret = 0;
	// ������ ���� ���� �̱��, ������ �̱�� ���� ����.
	return ret = -minValue;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		vector<string> board(3);
		int turnCount = 0;
		for (int i = 0; i < 3; i++)
		{
			cin >> board[i];
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] != '.')
					turnCount++;
			}
		}
		// ���� ����
		char turn = (turnCount % 2) ? 'o' : 'x';
		int res = canWin(board, turn);
		if (res == -1)
			turn == 'o' ? cout << "x\n" : cout << "o\n";
		else if (res == 1)
			turn == 'o' ? cout << "o\n" : cout << "x\n";
		else
			cout << "TIE\n";
	}
}