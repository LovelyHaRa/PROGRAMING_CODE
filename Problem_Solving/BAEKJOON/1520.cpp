#include<iostream>
#include<cstring>

using namespace std;

int m, n; // ��� ����
int map[501][501]; // ������
int v[501][501]; // �̹� �湮�� �������� üũ
int pos[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // �����¿� �̵��Ÿ�


int process(int x, int y)
{
	if (x == m && y == n) return 1; // ���� ���
	int &res = v[x][y];
	if (res != -1) return res; //�湮���� üũ
	res = 0;
	// �޸����̼�
	for (int i = 0; i < 4; i++)
	{
		int dx = x + pos[i][0];
		int dy = y + pos[i][1];
		// ���ο� ��ǥ�� �ʵ����� ���� ���� �����ϰ� �������̸� �̵�
		if (dx <= m && dy <= n && dx >= 1 && dy >= 1 && map[dx][dy] < map[x][y])
			res += process(dx, dy);
	}
	return res;
}

int main(void)
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}
	// �湮���� -1�� �ʱ�ȭ
	memset(v, -1, sizeof(v));	
	cout << process(1, 1) << endl;
}