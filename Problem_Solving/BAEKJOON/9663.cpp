// ��Ʈ��ŷ dfs ����
#include<iostream>
#include<cmath>

using namespace std;

int cnt = 0;
// ���࿡�� �� �ϳ��� ������ �� ������ �̿��Ѵ�
int col[15]= { 0, };
int N;

// ���� ����� üũ �ϸ鼭 ���� �࿡ ��ġ�ϰų� �밢���� ��ġ�ϸ� ��ġ�� �� ����
bool isPossible(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (col[i] == col[row] || abs(col[i] - col[row]) == abs(i - row))
			return false;
	}
	return true;
}

void queen(int row)
{
	// ���� ��� ä��� ���� ����
	if (row == N)
		cnt++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			// üũ
			col[row] = i;
			if (isPossible(row))
				queen(row + 1); // ���������� �Ѿ��
			else
				// ��Ʈ��ŷ
				col[row] = 0;
		}
	}
	// ��Ʈ��ŷ
	col[row] = 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	queen(0);
	cout << cnt << '\n';
}