#include<iostream>
#include<vector>

using namespace std;

// ��ǥ�� �ش��ϴ� ��Ʈ ���
inline int cell(int y, int x) { return 1 << (y * 5 + x); }

vector<int> moves;
// ������ ���� ���� �� �ִ� ����� ��� ����� ���� ����
void precalc()
{
	// L ��� ����� ��츦 ��������(�׷��� ��������)
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			// 1. �簢�� ��� ����
			vector<int> cells;
			for (int dy = 0; dy < 2; dy++)
			{
				for (int dx = 0; dx < 2; dx++)
					cells.push_back(cell(y + dy, x + dx));
			}
			int square = cells[0] + cells[1] + cells[2] + cells[3];
			// 2. �簢�� ��翡�� �ϳ��� ���鼭 ��츦 ����
			for (int i = 0; i < 4; i++)
				moves.push_back(square - cells[i]);
		}
	}
	// 1�� ��� ����� ���
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			moves.push_back(cell(i, j) + cell(i, j + 1));
			moves.push_back(cell(j, i) + cell(j + 1, i));
		}
	}
}

vector<char> cache(1 << 25 + 1, -1); // �޸� �ʰ������� char������ ����

char play(int board)
{
	char& ret = cache[board];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < moves.size(); i++)
	{
		// ��ġ�� �ʴ� ���
		if ((moves[i] & board)==0)
		{
			// �ش� ����� ��ġ��Ų �� ��� Ž��
			if (!play(board | moves[i]))
			{
				ret = 1;
				break;
			}
		}
	}
	return ret;
}

int main(void)
{
	precalc();
	int c;
	cin >> c;
	while (c--)
	{
		int board = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				char k;
				cin >> k;
				if (k == '#') board += cell(i, j);
			}
		}
		int res = play(board);
		res ? cout << "WINNING\n" : cout << "LOSING\n";
	}
}