#include<iostream>

using namespace std;

int res = 0; // ��� ����Ǽ�
int m, n; // ��� ����
int map[501][501]; // ������
int v[501][501]; // �̹� �湮�� �������� üũ

void process(int x, int y)
{
	int now = map[x][y];
	v[x][y] = 1;
	if (x == m && y == n)
	{
		res++;
		v[x][y] = 0;
		return;
	}
	/* 4���� ������ ���ȣ�� �Ѵ� */
	if (y < n && now > map[x][y + 1] && v[x][y + 1] == 0)
	{
		process(x, y + 1);
		v[x][y] = 0;
	}
	if (x < m && now > map[x + 1][y] && v[x + 1][y] == 0)
	{
		process(x + 1, y);
		v[x][y] = 0;
	}
	if (y > 1 && now > map[x][y - 1] && v[x][y - 1] == 0)
	{
		process(x, y - 1);
		v[x][y] = 0;
	}
	if (x > 1 && now > map[x - 1][y] && v[x - 1][y] == 0)
	{
		process(x - 1, y);
		v[x][y] = 0;
	}
	return;
}

int main(void)
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}
	process(1, 1);
	cout << res << endl;
}