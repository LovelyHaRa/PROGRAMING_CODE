// ��Ʈ��ŷ ����
// DFS �̿�

#include<iostream>
#include<vector>
#include<utility>
#include<cstdlib>

using namespace std;

int sudoku[9][9] = { 0 };
vector<pair<int, int>> blank; // ����ִ� ĭ ��ǥ ����

// ���� ���� �˻�
bool check_horizontal(int r, int num)
{
	for (int c = 0; c < 9; c++)
	{
		if (sudoku[r][c] == num)
			return false;
	}
	return true;
}

// ���� ���� �˻�
bool check_vertical(int c, int num)
{
	for (int r = 0; r < 9; r++)
	{
		if (sudoku[r][c] == num)
			return false;
	}
	return true;
}

// �簢�� ���� �˻�
bool check_square(int r, int c, int num)
{
	// �ش� ��ǥ�� ���ϴ� �簢�� ���� ������ ���ϱ�
	int x = (r / 3) * 3;
	int y = (c / 3) * 3;
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
			if (sudoku[i][j] == num)
				return false;
	}
	return true;
}

void dfs(int idx)
{
	// ĭ�� ��� ä������ ���
	if (idx == blank.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << sudoku[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}

	// 1���� 9���� ���ʴ�� �־�鼭 ���ɿ��� üũ
	for (int i = 1; i <= 9; i++)
	{
		int r = blank[idx].first;
		int c = blank[idx].second;
		if (check_horizontal(r, i) && check_vertical(c, i) && check_square(r, c, i))
		{
			sudoku[r][c] = i;
			dfs(idx + 1);
			sudoku[r][c] = 0; // ��Ʈ��ŷ
		}
	}
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
			// ����ִ� ĭ�� ���� ����
			if (!sudoku[i][j])
				blank.push_back({ i,j });
		}
	}
	dfs(0);
}